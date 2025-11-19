#ifndef HOC_H
#define HOC_H

#include "big_calc.h"

// --- DEFINICIONES DE TIPOS (DEBEN IR PRIMERO) ---
typedef void (*Inst)(void);

typedef struct Symbol { /* entrada en la tabla de símbolos */
   char   *name;
   short  type;
   union {
      BigAP bval;       /* VAR */
      BigAP  (*ptr)(BigAP);      /* BLTIN */
      void    (*defn)(void);     /* FUNCIÓN, PROCEDIMIENTO */
      //Inst *defn;
      char    *str;         /* CADENA */
   } u;
   struct Symbol   *next;  /* para ligar a otro */
} Symbol;
Symbol  *install(), *lookup();

typedef union Datum {   /* tipo de la pila del intérprete */
   BigAP   bval; // <--- CAMBIADO
   Symbol  *sym; 
} Datum; 
// --------------------------------------------------------

// --- PROTOTIPOS FALTANTES E IMPORTANTES ---
void initcode();
void define(Symbol *sp);
void execerror(char *s, char *t);
int moreinput(void);
int yylex(void);
void defnonly(char *s);
void yyerror(char *s);
void init( ); // Añadido prototipo para main/run
// ------------------------------------------

extern void pop1( );
extern Datum pop( );
extern void eval(), add(), sub(), mul(), h_div(), negate(), power();
extern char *emalloc();

#define STOP   (Inst) 0

// Declara code como extern
extern Inst *progp, *progbase, prog[], *code();

extern void assign(), bltin(), varpush(), constpush(), print(), varread();
extern void prexpr(), prstr();
extern void gt(), lt(), eq(), ge(), le(), ne(), and(), or(), not();
extern void ifcode(), whilecode(), call(), arg(), argassign();
extern void funcret(), procret();
// Asegurar execute es extern y coincide con la implementación
extern void execute(Inst *p);

#endif // HOC_H