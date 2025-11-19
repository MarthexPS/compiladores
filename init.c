#include "hoc.h"
#include "y.tab.h"
#include <math.h>
// Añadir prototipos para funciones externas usadas:
extern Symbol *install(char *s, int t, double d); // De symbol.c
static struct { 
char   *name;	/* Palabras clave */
int    kval;
} keywords[] = {
"proc" ,	PROC,
"func" ,	FUNC,
"return",	RETURN,
"if",		IF,
"else" ,	ELSE,
"while",	WHILE,
"print",	PRINT,
"read",		READ,
0,      0,
};

init( )  /* instalar constantes y predefinidos en la tabla */
{
int i;

for (i = 0; keywords[i].name; i++)
	install(keywords[i].name, keywords[i].kval, 0.0);

}

