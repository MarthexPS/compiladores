#include "hoc.h"
#include "y.tab.h"
#include<string.h>
#include<stdlib.h> // CORRECCIÓN: Agregado para malloc
// Añadir prototipos para funciones externas usadas:
extern void execerror(char *s, char *t);
extern BigAP intToBig(int n); // De big_calc.h
static Symbol *symlist = 0;  /* lista ligada da la tabla de símbolos */

Symbol *lookup(char *s)      /* encontrar s an la tabla da simbolos */
{
Symbol *sp;
for (sp = symlist; sp != (Symbol *) 0; sp = sp->next)
if (strcmp(sp->name, s) == 0)
	return sp;
return 0;      /* 0 ==> not found */
}

Symbol *install(char *s, int t, double d) // 'd' es ahora un dummy
{
	Symbol *sp;
	char *emalloc();
	sp = (Symbol *) emalloc(sizeof(Symbol));
	sp->name = emalloc(strlen(s)+1);
	strcpy(sp->name, s);
	sp->type = t;
	
	// sp->u.val = d; // <-- REEMPLAZADO
	if (t == NUMBER) {
		// bval será asignado después en yylex
		sp->u.bval = NULL; 
	} else if (t == VAR) {
		// Inicializar variables a 0
		sp->u.bval = intToBig(0); 
	} else {
		sp->u.bval = NULL; // Para BLTINs (si los hubiera)
	}

	sp->next = symlist;
	symlist = sp;
	return sp;
}
char *emalloc(unsigned n)       /* veriflcar retorno da malloc */
{
char *p; // CORRECCIÓN: Eliminamos *malloc() que causaba conflicto
p = malloc(n);
if (p == 0)
execerror("out of memory", (char *) 0);
return p;
}