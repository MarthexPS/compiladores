#include "hoc.h"
#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h> // <--- AÑADIDO para free y malloc

// Declaraciones de funciones que devuelven BigAP*
extern BigAP intToBig(int n);
extern BigAP stringToBig(char *s);
extern void free(void *ptr); // Explícito para evitar warnings en algunos sistemas

#define NSTACK  256
static Datum stack[NSTACK];    /* la pila */
static Datum *stackp;          /* siguiente sitio libre en la pila */
#define NPROG  2000
Inst   prog[NPROG];   /* la Máquina */
Inst   *progp;        /* siguiente sitio libre para la generación de código */
Inst   *pc;              /* contador de programa durante la ejecución */
Inst   *progbase = prog; /* Inicie del subprograaa actual */
int    returning;      /* 1 si se ve la proposiolón de retorno */
typedef struct Frame {     /* nivel da pila par» Huida a proc/func */
Symbol  *sp;         /* entrada en la tabla da simbolos */
Inst    *retpc;   /* dónde reanudar después del retorno */
Datum  *argn;     /* n-esimo argumento en la pila */
int    nargs;     /* número da argumentos */
} Frame;
#define NFRAME  10000 
Frame  frame[NFRAME] ;
Frame   *fp;  /* apuntador a nivel */
// void execute(Inst *p); // Ya declarado en hoc.h
void initcode() {
   progp = progbase;
   stackp = stack;
   fp = frame;
   returning = 0; 
}
void push(Datum d){
   if (stackp >= &stack[NSTACK])
      execerror("stack too deep", (char *)0); 
   *stackp++ = d;
}
Datum pop( ){
   if (stackp == stack)
      execerror("stack underflow" , (char *)0);
   // NO LIBERAR AQUÍ. SOLO DEVOLVER EL VALOR.
   return *--stackp; 
}
void pop1( ){
   if (stackp == stack)
      execerror("stack underflow" , (char *)0);
   // Para evitar fugas en expresiones de alto nivel (como print):
   if (stackp[-1].bval) { 
        freeBig(stackp[-1].bval); 
   }
   --stackp;
}

void constpush( ) /* meter una constante a la pila  */
{
   Datum d;
   // CORRECCIÓN: Usar copiaBig para no pasar el puntero original que ret() liberará después
   d.bval = copiaBig(((Symbol  *)*pc++)->u.bval);
   push(d);
}
void varpush(){
   Datum d;
   d.sym =  (Symbol *)(*pc++);
   push(d);
}
void whilecode() {
   Datum d;
   Inst  *savepc  = pc; 
   execute(savepc+2);     /* condición   */ 
   d  =  pop(); 
   while   (!isZeroBig(d.bval))   {
      execute(*((Inst  **)(savepc)));     /* cuerpo  */
      execute(savepc+2);
      d  = pop(); 
   } 
   pc  =  *((Inst  **)(savepc+1));     /* siguiente proposición   */
}
void ifcode(){
   Datum d;
   Inst  *savepc  = pc; /* parte then */
   execute(savepc+3);   /* condición   */
   d  =  pop(); 
   if (!isZeroBig(d.bval))
      execute(*((Inst   **)(savepc))); 
   else  if   (*((Inst  **)(savepc+1)))   /* ¿parte else?   */
      execute(*(( Inst  **) (savepc+1)));
   pc  =  *((Inst  **)(savepc+2));  /* siguiente proposición   */ 
}

void define(Symbol *sp){
   sp->u.defn = (void (*)(void))progbase;    /* lnlolo de código */ // <--- CAST PARA EVITAR WARNING
   progbase = progp;      /* el siguiente código comienza aquí */
}

void call() {
Symbol  *sp  =   (Symbol *)pc[0];
if   (fp++   >=  &frame[NFRAME-1])
execerror(sp->name,   "call  nested too deeply");
   fp->sp = sp;
   fp->nargs =   (int)(long)pc[1]; // <--- CAST PARA EVITAR WARNING
   fp->retpc = pc  + 2;
   fp->argn  =  stackp  -   1;     /* último argumento   */
   execute((Inst *)sp->u.defn); // <--- CAST NECESARIO
   returning = 0; 
} 
// code.c (cerca de la línea 109)
void ret( ) {
   int i;
   Datum d; // Usamos una Datum temporal

   // Los argumentos están en fp->argn (el último argumento) y descienden
   // HOC: La pila de args contiene arg1, arg2, ..., argN (fp->argn)
   // Y pop() mueve stackp hacia abajo

   // Liberar el valor BigAP de cada argumento en la pila
   for (i = 0; i < fp->nargs; i++) {
        // Accedemos a la ranura de la pila que contiene el argumento
        Datum *arg_slot = fp->argn - i;
        if (arg_slot->bval) {
            freeBig(arg_slot->bval);
            arg_slot->bval = NULL; // Opcional: Anular el puntero
        }
   }

   // Limpiar la pila (decrementa stackp n veces)
   for (i = 0; i < fp->nargs; i++)
      pop();  /* sacar argumentos de la pila */

   pc = (Inst *)fp->retpc;
   --fp;
   returning = 1; 
}

void funcret(){
Datum d;
if (fp->sp->type == PROCEDURE)
execerror(fp->sp->name, "(proc) returns value");

d = pop();      /* conservar el valor de retorno de la función */
// pop() ya no libera la memoria de d.bval

ret(); // Llama a ret, que limpia los argumentos.

push(d); // Empuja el valor de retorno (d.bval) de nuevo.
}

void procret( ){
   if   (fp->sp->type  ==  FUNCTION)
      execerror(fp->sp->name, "(func) returns no value"); 
   ret(); 
}

BigAP getarg( ) { // <--- CAMBIADO: devuelve BigAP
int narg = (int)(long) *pc++; // <--- CAST PARA EVITAR WARNING
if (narg > fp->nargs)
   execerror(fp-> sp->name, "not enough arguments");
// Devuelve el valor BigAP directamente
return fp->argn[narg - fp->nargs].bval; 
}


void arg( ) {
   Datum d;
   Big *val = getarg();
   
   if (val == NULL) {
       execerror("Argumento nulo o invalido", (char *)0);
   }

   d.bval = copiaBig(val); // Copia el argumento de la pila
   push(d); 
}

void argassign() {
   Datum d;
   d = pop();
   push(d); 
   int narg = (int)(long) *pc++; 
   if (narg > fp->nargs)
      execerror(fp->sp->name, "not enough arguments");
   
   // CORRECCIÓN CRÍTICA: Usar freeBig para limpiar el valor anterior
   if (fp->argn[narg - fp->nargs].bval != NULL) {
       freeBig(fp->argn[narg - fp->nargs].bval); 
   }
   fp->argn[narg - fp->nargs].bval = copiaBig(d.bval);
}
void bltin() {
   execerror("BLTIN functions not supported for BigAP", (char *)0);
}

void eval( )  {
   Datum  d;
   d   =  pop();
   if   (d.sym->type   ==   UNDEF)
      execerror("undefined variable", d.sym->name); 
   d.bval = copiaBig(d.sym->u.bval);
   push(d);
}

void add( ) { /* sumar los dos elementos superiores de la pila   */
   Datum d1,   d2; 
   d2  =  pop(); 
   d1   =  pop(); 
   d1.bval  =  sumaBig(d1.bval, d2.bval);
   push(d1); 
}

void sub(){
   Datum d1,  d2; 
   d2  = pop(); 
   d1  = pop(); 
   d1.bval  = restaBig(d1.bval, d2.bval);
   push(d1);
}
void mul(){
   Datum d1, d2;
   d2 = pop(); 
   d1 = pop(); 
   d1.bval = multiBig(d1.bval, d2.bval);
   push(d1);
}

void h_div( ){
   execerror("division for Big numbers not implemented", (char *)0);
}


void negate(){
   Datum d; 
   d = pop(); 
   d.bval->signo *= -1;
   push(d);
}
void power(){
   Datum d1, d2;
   d2 = pop();
   d1 = pop();
   d1.bval = potBig(d1.bval, d2.bval);
   push(d1);
}

void gt() {
   Datum d1,  d2;
   d2 = pop();
   d1 = pop();
   int res = (comparaBig(d1.bval, d2.bval) > 0);
   d1.bval  = intToBig(res);
   push(d1);
}

void lt(){
   Datum d1,  d2;
   d2 = pop();
   d1 = pop();
   int res = (comparaBig(d1.bval, d2.bval) < 0);
   d1.bval  = intToBig(res);
   push(d1);
}

void ge( ) {
   Datum d1,  d2;
   d2  = pop();
   d1  = pop();
   int res = (comparaBig(d1.bval, d2.bval) >= 0);
   d1.bval  = intToBig(res);
   push(d1) ;
}

void le() {
   Datum d1,  d2;
   d2   =  pop();
   d1   =  pop();
   int res = (comparaBig(d1.bval, d2.bval) <= 0);
   d1.bval  = intToBig(res);
   push(d1);
}

void eq( ) {
   Datum d1,  d2;
   d2  = pop();
   d1  = pop();
   int res = (comparaBig(d1.bval, d2.bval) == 0);
   d1.bval  = intToBig(res);
   push(d1);
}

void ne(){
   Datum d1, d2;
   d2 = pop();
   d1 = pop();
   int res = (comparaBig(d1.bval, d2.bval) != 0);
   d1.bval = intToBig(res);
   push(d1);
}

void and(){
   Datum d1,   d2;
   d2   = pop();
   d1   = pop();
   int res = (!isZeroBig(d1.bval) && !isZeroBig(d2.bval));
   d1.bval = intToBig(res);
   push(d1);
}

void or(){
   Datum d1, d2;
   d2 = pop();
   d1 = pop();
   int res = (!isZeroBig(d1.bval) || !isZeroBig(d2.bval));
   d1.bval = intToBig(res);
   push(d1);
}

void not( ){
   Datum d;
   d = pop();
   int res = isZeroBig(d.bval);
   d.bval = intToBig(res);
   push(d);
}


void assign( ){
   Datum d1, d2;
   d1 = pop(); 
   d2 = pop(); 
   if (d1.sym->type != VAR && d1.sym->type != UNDEF) 
      execerror("assignment to non-variable", d1.sym->name);
      
   // CORRECCIÓN CRÍTICA: Usar freeBig
   if (d1.sym->u.bval != NULL) {
       freeBig(d1.sym->u.bval); 
   }
   d1.sym->u.bval = copiaBig(d2.bval); 
   d1.sym->type = VAR;
   push(d2); 
}
void print( ){  /* sacar el valor superior de la pila e imprimirlo */ 
   Datum d;
   d = pop();
   printf("\t");
   imprimeBig(d.bval);
}
void prexpr() {      
   Datum d;
   d = pop();
   imprimeBig(d.bval);
   printf(" ");
}

void prstr() {
/* Imprimir valor de la cadena */ 
printf("%s", (char *) ((Symbol *)*pc++)->u.str); 
}

void varread(){
Datum d;
extern FILE *fin; 
Symbol *var = (Symbol *) *pc++; 
char sbuf[1024]; 

Again:
// Leer una "palabra" (número) del archivo. 
if (fscanf(fin, "%s", sbuf) == EOF) { 
    if (moreinput()) { 
        goto Again;
    }
    // EOF, no hay más archivos. Asignar 0.
    if (var->u.bval != NULL) free(var->u.bval);
    var->u.bval = intToBig(0); 
    d.bval = intToBig(0);
    var->type = VAR; 
    return; // Salir sin push, comportamiento clásico de EOF en read
} else {
    // Lectura exitosa de una cadena que se asume es un número
    if (var->u.bval != NULL) free(var->u.bval);
    var->u.bval = stringToBig(sbuf); 
    
    // d.bval = 1 (representa éxito en lectura, para push)
    d.bval = intToBig(1); 
}

var->type = VAR; 
push(d);
}

Inst *code(Inst f){
Inst *oprogp = progp;
if (progp >= &prog[NPROG])
execerror("program too big", (char *)0);
*progp++ = f;
return oprogp;
}
void execute(Inst *p){
for (pc = p; *pc != STOP && !returning; ) 
   ((*pc++))();
}       