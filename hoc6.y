%{
#include "hoc.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <signal.h>
#include <setjmp.h>

#define code2(c1,c2)     code(c1); code(c2)
#define code3(c1,c2,c3)  code(c1); code(c2); \
code(c3) /* La \ es crucial para multilínea */

int indef = 0;
jmp_buf begin;
char    *progname;
int    lineno = 1 ;
char   *infile;       /* nombre de archivo de entrada */
FILE    *fin;
/* apuntador a archivo de entrada */
char   **gargv;       /* lista global de argumentos */
int    gargc;
int c;                /* global, para uso de warning() */

%}

%union {
    Symbol     *sym;
/* Apuntador a la tabla de símbolos */
    Inst       *inst;
/* instrucción de máquina */
    int        narg;
/* número de argumentos */
}

%token     <sym>   NUMBER STRING PRINT VAR BLTIN UNDEF WHILE IF ELSE
%token     <sym>   FUNCTION PROCEDURE RETURN FUNC PROC READ
%token     <narg>  ARG
%type      <inst>  expr stmt asgn prlist stmtlist
%type      <inst>  cond while if begin end
%type      <sym>   procname
%type      <narg>  arglist

%right     '='
%left       OR
%left       
AND
%left       GT GE LT LE EQ NE
%left       '+' '-'
%left       '*' '/'
%left       UNARYMINUS NOT
%right      '^'
%%

/* Lista principal: aceptar sentencias con o sin EOL para tolerar CRLF/variantes */
list:            /* nada */
   |
list '\n'
   | list defn                 { code(STOP);
return 1; }
   | list asgn '\n'           { code2(pop1, STOP);
return 1; }
   | list asgn                 { code2(pop1, STOP);
return 1; }
   | list stmt '\n'           { code(STOP);
return 1; }
   | list stmt                 { code(STOP);
return 1; }
   | list expr '\n'           { code2(print, STOP);
return 1; }
   | list expr                 { code2(print, STOP);
return 1; }
   | list error '\n'          { yyerrok;
}
   ;

asgn: VAR '=' expr { /*puts("VAR = expr ###");*/
              code3(varpush,(Inst)$1, assign);
$$=$3; }
   | ARG '=' expr
     { defnonly("$"); code2(argassign,(Inst)$1); $$=$3; }
   ;
stmt:     expr  { code(pop1); }
   | RETURN { defnonly("return"); code(procret);
}
   | RETURN expr { defnonly( "return" ); $$ = $2; code(funcret); }
   |
PROCEDURE begin '(' arglist ')'
          { $$ = $2;
code3(call, (Inst)$1, (Inst)$4); }
   | PRINT prlist  { $$ = $2; }
   |
while cond stmt end {
           /* whilecode estructura: $1           */
           ($1)[1] = (Inst)$3;
/* cuerpo del ciclo */
           ($1)[2] = (Inst)$4;
/* fin, si la condición no se cumple */
       }
   |
if cond stmt end {    /* if sin else */
           ($1)[1] = (Inst)$3;
/* parte then */
           ($1)[3] = (Inst)$4;
/* fin, si la condición no se cumple */
       }
   |
if cond stmt end ELSE stmt end {      /* if con else */
           ($1)[1] = (Inst)$3;
/* parte then */
           ($1)[2] = (Inst)$6;
/* parte else */
           ($1)[3] = (Inst)$7;
/* fin, si la condición no se cumple */
       }
   |
'{' stmtlist '}'     { $$ = $2; }
   ;
cond: '(' expr ')'     {  code(STOP);   $$ =  $2;   }
   ;
while:  WHILE { $$ = code3(whilecode,STOP,STOP); }
   ;
if:     IF   { $$ = code(ifcode); code3(STOP,STOP,STOP); }
   ;
begin:  /* nada */          { $$ = progp;
}
   ;

end:    /* nada */          { code(STOP);
$$ = progp; }
   ;

stmtlist: /* nada */        { $$ = progp;
}
   | stmtlist '\n'
   | stmtlist stmt
   ;
expr:  NUMBER {   $$ = code2(constpush, (Inst)$1); }
   |
VAR    {   $$ = code3(varpush, (Inst)$1, eval); }
   |
 ARG    {   defnonly("$"); $$ = code2(arg, (Inst)$1); }
   | asgn
   |
FUNCTION begin '(' arglist ')'
           { $$ = $2; code3(call,(Inst)$1,(Inst)$4);
}
   | READ '(' VAR ')' { $$ = code2(varread, (Inst)$3); }
   |
BLTIN '(' expr ')' { $$=$3; code2(bltin, (Inst)$1->u.ptr); }
   | '(' expr ')'  { $$ = $2;
}
   | expr   '+'   expr {   code(add); }
   |
expr   '-'   expr {   code(sub); }
   |
expr   '*'   expr {   code(mul); }
   |
expr   '/'   expr {   code(h_div); }
   |
expr   '^'   expr {   code(power); }
   |
'-' expr  %prec UNARYMINUS   { $$=$2; code(negate); }
   |
expr   GT   expr   { code(gt); }
   |
expr   GE   expr   { code(ge); }
   |
expr   LT   expr   { code(lt); }
   |
expr   LE   expr   { code(le); }
   |
expr   EQ   expr   { code(eq); }
   |
expr   NE   expr   { code(ne); }
   |
expr  AND    expr  { code(and);}
   |
expr   OR    expr  { code(or); }
   |
NOT expr     { $$= $2; code(not); }
   ;
prlist: expr               {   code(prexpr);
}
   |   STRING              {    $$ = code2(prstr, (Inst)$1);
}
   |   prlist ','  expr    {   code(prexpr); }
   |
prlist ','  STRING    {   code2(prstr, (Inst)$3); }
   ;
/* Definiciones de funciones y procedimientos */
/* Definiciones de funciones y procedimientos */
defn:    FUNC procname { $2->type=FUNCTION; indef=1; }
         '(' ')' stmt { code(funcret); define($2); indef=0; } // <--- CAMBIADO a funcret
   |
PROC procname { $2->type=PROCEDURE; indef=1; }
     '(' ')' stmt { code(procret); define($2); indef=0; } // Este sigue siendo procret
   ;

procname: VAR
   | FUNCTION
   | PROCEDURE
   ;
arglist:  /* nada */      { $$ = 0; }
   |
expr                 { $$ = 1;
}
   | arglist ',' expr     { $$ = $1 + 1;
}
   ;

%%

/* fin de la gramática */

/* Implementaciones y utilidades */

/* Prototipos locales para evitar warnings */
int yylex(void);
int backslash(int c);
int follow(int expect, int ifyes, int ifno);
void defnonly(char *s);
void yyerror(char *s);
void execerror(char *s, char *t);
void fpecatch(void);
int moreinput(void);
void run(void);
void warning(char *s, char *t);
int yylex(void){
    /* Ignorar espacios, tab y CR (soporte CRLF) */
    while ((c=getc(fin)) == ' ' || c == '\t' || c == '\r')
        ;
if (c == EOF)
       return 0;
if (isdigit(c)) {   /* n�mero */
      char numbuf[1024], *p = numbuf;
      do {
         if (p >= numbuf + sizeof(numbuf) - 1) {
            *p = '\0';
            execerror("name too long", numbuf);
         }
         *p++ = c;
      } while ((c=getchar()) != EOF && isdigit(c)); // Solo d�gitos
      ungetc(c, stdin);
      *p = '\0';
      
      // Instalar el n�mero grande
      yylval.sym = install("", NUMBER, 0.0); // 0.0 es dummy
      yylval.sym->u.bval = stringToBig(numbuf); // Usar nueva funci�n
      return NUMBER;
   }
   // --- FIN DE SECCI�N MODIFICADA ---

    if (isalpha(c)) { 
      Symbol *s;
      char sbuf[100], *p = sbuf;
      do {
         if (p >= sbuf + sizeof(sbuf) - 1) { 
            *p = '\0'; 
            execerror("name too long", sbuf);
         }
         *p++ = c;
      } while ((c=getc(stdin)) != EOF && isalnum(c)); 
      ungetc(c, stdin); 
      *p = '\0';
      if ((s=lookup(sbuf)) == 0)
         s=install(sbuf, UNDEF, 0.0); // <--- Aquí se usa UNDEF
      yylval.sym = s;
      return s->type == UNDEF ? VAR : s->type; // <--- CAMBIADO DE INDEF A UNDEF
   }
    if (c == '$') { /* ¿argumento?
*/
       int n = 0;
while (isdigit(c=getc(fin)))
           n = 10 * n + c - '0';
ungetc(c, fin);
       if (n == 0)
          execerror("strange $...", (char *)0);
yylval.narg = n;
       return ARG;
    }
    if (c == '"') { /* cadena entre comillas */
       char sbuf[100], *p = sbuf;
       for (; (c=getc(fin)) != '"'; ) {
          if (c == '\n' || c == EOF)
             execerror("missing quote", "");
if (p >= sbuf + sizeof(sbuf) - 1) {
             *p = '\0';
execerror("string too long", sbuf);
          }
          *p++ = backslash(c);
}
       *p = 0;
       
       // INICIO DE CORRECCIÓN (líneas originales en hoc6.y 94-96)
       Symbol *s = install("", STRING, 0.0);
       s->u.str = emalloc(strlen(sbuf)+1);
       strcpy(s->u.str, sbuf);
       yylval.sym = s;
       // FIN DE CORRECCIÓN

       return STRING;
}
    switch (c) {
   case '>':                return follow('=', GE, GT);
   case '<':                return follow('=', LE, LT);
   case '=':                return follow('=', EQ, '=');
   case '!':                return follow('=', NE, NOT);
   case '|':                return follow('|', OR, '|');
   case '&':                return follow('&', AND, '&');
   case '\n':              lineno++; return '\n';
   default:                  return c;
   }
}

int backslash(int c){
    /* tomar siguiente carácter con las \ interpretadas */
    static const char transtab[] = "b\bf\fn\nr\rt\tt";
if (c != '\\')
        return c;
    c = getc(fin);
if (islower(c)) {
        const char *p = strchr(transtab, c);
if (p)
            return p[1];
}
    return c;
}

int follow(int expect,   int ifyes,   int ifno)  { /* buscar  >=, etc.   */ 
   int c  = getchar();
   if  (c  ==  expect)
      return ifyes; 
   ungetc(c,   stdin);
   return  ifno;
}

void defnonly( char *s )     /* advierte si hay definición ilegal */
{
    if (!indef)
       execerror(s, "used outside definition");
}

void yyerror(char *s)      /* comunicar errores de tiempo de compilación */
{
    warning(s, (char *)0);
}

void execerror(char *s, char *t) /* recuperación de errores de tiempo de ejecución */
{
    warning(s, t);
fseek( fin, 0L, 2); /* sacar el resto del archivo */
    longjmp(begin, 0);
}

void fpecatch(void)      /* detectar errores por punto flotante */
{
    execerror("floating point exception", (char *) 0);
}

int moreinput( void ) {
    if (gargc-- <= 0)
       return 0;
if (fin && fin != stdin)
       fclose(fin);
    infile = *gargv++;
    printf("arch ent=(%s)\n",infile);
lineno = 1;
    if (strcmp(infile, "-") == 0) {
       fin = stdin;
infile = 0;
    } else if ((fin=fopen(infile, "r")) == NULL) {
       fprintf(stderr, "%s: can't open %s\n" , progname, infile);
return moreinput();
    }
    return 1;
}

void run(void)   /* ejecutar hasta el fin de archivo (EOF) */
{
    setjmp(begin);
    signal(SIGFPE, (void (*)(int))fpecatch); // <--- CAST NECESARIO
    for (initcode(); yyparse(); initcode()){
        execute(progbase);
    }
}

void warning(char *s, char *t)        /* imprimir mensaje de advertencia   */
{
    fprintf(stderr, "%s: %s", progname, s);
if (t)
       fprintf(stderr, " %s", t);
if (infile)
       fprintf(stderr, " in %s", infile);
    fprintf(stderr, " near line %d\n", lineno);
while (c != '\n' && c != EOF)
       c = getc(fin);
/* sacar el resto del renglón de entrada */
    if (c == '\n')
       lineno++;
}

int main(int argc, char **argv){  /* hoc6 */
    int i;
    void fpecatch();
    progname = argv[0];
if (argc == 1) {        /* simular una lista de argumentos */
       static char *stdinonly[] = { "-" };
gargv = stdinonly;
       gargc = 1;
    } else {
       gargv = argv+1;
gargc = argc-1;
    }
    init();
    while (moreinput())
       run();
    return 0;
}