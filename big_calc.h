// big_calc.h (CORREGIDO)

#ifndef BIG_CALC_H // Protección de inclusión
#define BIG_CALC_H

struct big {
	char name;
	int n;
	int *cifras;
	int signo;
};
typedef struct big Big;
typedef struct big *BigAP;
void freeBig(Big *b);
Big *creaBig(int n);
void imprimeBig(Big *a);
Big *copiaBig(Big *a);
Big *sumaBig(Big *a, Big *b);
Big *restaBig(Big *a, Big *b);
Big *multiBig(Big *a, Big *b);
Big *potBig(Big *a, Big *b);
int comparaBig(Big *a, Big *b); // <--- AÑADIDO (Prototipo faltante)

// --- NUEVAS FUNCIONES AUXILIARES ---
Big *intToBig(int n);
int isZeroBig(Big *b);
Big *stringToBig(char *s);
// --- FIN DE NUEVAS FUNCIONES ---

#endif // BIG_CALC_H