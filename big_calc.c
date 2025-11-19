#include <stdio.h>
#include <stdlib.h>
#include "big_calc.h"
#include <string.h>
#include <ctype.h>

// Helper: Convertir int (pequeño) a BigAP
Big *intToBig(int n) {
    Big *b;
    long long n_long = n; // Usar long long para manejar -n
    
    if (n_long == 0) {
        b = creaBig(1);
        b->cifras[0] = 0;
        return b;
    }
    
    if (n_long < 0) {
        n_long = -n_long;
    }
    
    // Asumir que 10000^2 es suficiente para 1 o 0
    if (n_long >= 10000) { 
        b = creaBig(2);
        b->cifras[0] = n_long % 10000;
        b->cifras[1] = n_long / 10000;
    } else {
        b = creaBig(1);
        b->cifras[0] = n_long;
    }

    if (n < 0) {
        b->signo = -1;
    }
    
    return b;
}

// Helper: Comprobar si BigAP es cero
int isZeroBig(Big *b) {
    if (!b) return 1; // NULL es tratado como cero
    // Comprobar todas las 'cifras'
    for (int i = 0; i < b->n; i++) {
        if (b->cifras[i] != 0) return 0; // No es cero
    }
    return 1; // Es cero
}

// Helper: Convertir string de dígitos a BigAP
Big *stringToBig(char *s) {
    int len = strlen(s);
    if (len == 0) {
        return intToBig(0);
    }
    
    // Omitir signo (asumimos positivo por ahora, 'negate' lo maneja)
    int start = 0;
    if (s[0] == '-') {
        start = 1;
    }
    
    int num_len = len - start;
    if (num_len == 0) {
        return intToBig(0);
    }

    int n_cifras = (num_len + 3) / 4; // 4 dígitos por 'cifra'
    Big *b = creaBig(n_cifras);
    int cifra_idx = 0;
    int power = 1;
    int current_cifra = 0;

    for (int i = len - 1; i >= start; i--) {
        if (!isdigit(s[i])) continue; // Ignorar no-dígitos
        
        current_cifra += (s[i] - '0') * power;
        power *= 10;

        // Si completamos 4 dígitos o llegamos al final de la cadena
        if (power == 10000 || i == start) {
            b->cifras[cifra_idx++] = current_cifra;
            power = 1;
            current_cifra = 0;
        }
    }
    
    if (s[0] == '-') {
        b->signo = -1;
    }

    // (Opcional) Normalizar: quitar ceros no significativos
    int top = b->n - 1;
    while (top > 0 && b->cifras[top] == 0) top--;
    
    if (top + 1 < b->n) {
        b->n = top + 1;
        b->cifras = (int *)realloc(b->cifras, b->n * sizeof(int));
    }

    return b;
}

Big *creaBig(int n){
   Big *big;
   int i;
   big=(Big *)malloc(sizeof(Big));
   big->n = n;  
   big->cifras = (int *)malloc(sizeof(int)*n);
   for(i = big->n - 1; i >= 0 ; i--)
      big->cifras[i]=0;
   big->signo =1;
   return big;

}
void imprimeBig(Big *b){
   int i;
   if (b == NULL) return;
   if (b->signo < 0) printf("-");
   /* busca índice más alto no nulo para evitar ceros a la izquierda innecesarios */
   int top = b->n - 1;
   while (top > 0 && b->cifras[top] == 0) top--;
   for(i = top; i >= 0 ; i--){
      /* imprime con relleno a 4 dígitos excepto el bloque más alto que no necesita ceros a la izquierda */
      if (i == top)
         printf("%d", b->cifras[i]);
      else
         printf("%04d", b->cifras[i]);
      if (i > 0) printf(" ");
   }
   printf("\n");
}





Big *copiaBig(Big *b){
   if (b == NULL) return NULL; // Protección contra Segfaults por nulos
   
   int i;
   Big *copy = creaBig(b->n);
   
   // Copiar signo (CRÍTICO: faltaba esto en tu versión)
   copy->signo = b->signo; 
   
   for(i = 0; i < b->n; i++)
      copy->cifras[i] = b->cifras[i]; 
      
   return copy; 
}
Big *sumaBig(Big *a, Big *b){
   if (!a || !b) return NULL;
   int maxn = (a->n > b->n) ? a->n : b->n;
   int carry = 0;
   /* reserva temporal dinámicamente para no agotar stack */
   int *suma = (int *)calloc(maxn + 1, sizeof(int));
   if (!suma) {
       fprintf(stderr, "sumaBig: fallo malloc\n");
       exit(1);
   }

   for (int i = 0; i < maxn; ++i){
       int ai = (i < a->n) ? a->cifras[i] : 0;
       int bi = (i < b->n) ? b->cifras[i] : 0;
       int s = ai + bi + carry;
       carry = s / 10000;
       suma[i] = s % 10000;
       /* depuración opcional:
       printf("(%d,%d,%d)", ai, bi, s);
       */
   }
   if (carry) {
       suma[maxn] = carry;
       maxn = maxn + 1;
   }

   Big *c = creaBig(maxn);
   for (int i = 0; i < maxn; ++i)
       c->cifras[i] = suma[i];

   c->signo = 1;
   free(suma);
   
   return c;
}
   
   

Big *potBig(Big *a, Big *b){
   Big *c;
    int i, s;
   c=creaBig(1);
   c->cifras[0]=1;
   for(i=0; i < b->cifras[0]; i=i+1){
       c = multiBig(a, c);
   }
   return c;
}
Big *multiBig(Big *a, Big *b){
   int multi[10000];
    
   int i, base;
   int grado1, grado2;
   int acarreo;

   int s,t , cta, digit, remainder;
   int aux[1000], sum[1000];
   Big *c;     

   cta=0;
   base= 10000;
   grado1 = a->n;
   grado2 = b->n;
   for (s=0 ; s < 1000; s++){
       multi[s]=0; aux[s]=0; sum[s]=0;
   }
   c=creaBig(grado1+grado2+1);
   for (s=0 ; s < grado2; s++){
        digit=b->cifras[s];
        for(i=0; i < cta; i=i+1){
              aux[i]=0;  
        }
        for(i=cta; i < grado1+cta; i=i+1){
              aux[i]=a->cifras[i-cta];  
        }
        if (digit != 0){
            remainder=0;
            for(t=0; t < grado1+cta ; t++ ){ 
              sum[t] =(aux[t]* digit + multi[t] + remainder) % base;   
              remainder =(aux[t] * digit  + multi[t] + remainder) / base;
            }
            if (remainder != 0)
               sum[t] = remainder;
            for(i=0; i <= t; i=i+1){
               multi[i]=sum[i];
            }
        }
        cta++;
    }
   for(i= grado1+grado2; i >= 0 ; i=i-1){
      c->cifras[i]=multi[i];
   }
   return c;
}

// devuelve 1 si a > b, -1 si a < b, 0 si a == b (solo módulo)
int comparaBig(Big *a, Big *b) {
    if (a->n > b->n) return 1;
    if (a->n < b->n) return -1;

    for (int i = a->n - 1; i >= 0; i--) {
        if (a->cifras[i] > b->cifras[i]) return 1;
        if (a->cifras[i] < b->cifras[i]) return -1;
    }
    return 0;
}


Big *restaBig(Big *a, Big *b) {
    Big *c;
    int i;
    int acarreo = 0;
    int mayor;

    // Comparar a y b
    int cmp = comparaBig(a, b);

    if (cmp == 0) {
        // Resultado = 0
        c = creaBig(1);
        c->cifras[0] = 0;
        c->signo = 1;
        return c;
    } else if (cmp > 0) {
        // a > b → resultado positivo
        c = creaBig(a->n);
        c->signo = 1;
        mayor = 1;
    } else {
        // a < b → resultado negativo
        c = creaBig(b->n);
        c->signo = -1;
        mayor = 0;
    }

    int maxn = c->n;
    for (i = 0; i < maxn; i++) {
        int ai = (mayor && i < a->n) ? a->cifras[i] : ((i < b->n) ? b->cifras[i] : 0);
        int bi = (mayor && i < b->n) ? b->cifras[i] : ((i < a->n) ? a->cifras[i] : 0);

        int res = ai - bi - acarreo;
        if (res < 0) {
            res += 10000;
            acarreo = 1;
        } else {
            acarreo = 0;
        }
        c->cifras[i] = res;
    }

    // Normalizar: quitar ceros a la izquierda
    int top = maxn - 1;
    while (top > 0 && c->cifras[top] == 0) top--;

    if (top + 1 < c->n) {
        c->n = top + 1;
        // reacomodar memoria
        c->cifras = realloc(c->cifras, c->n * sizeof(int));
    }

    return c;
}
// big_calc.c (Implementación)
void freeBig(Big *b) {
    if (b) {
        if (b->cifras) {
            free(b->cifras);
        }
        free(b);
    }
}