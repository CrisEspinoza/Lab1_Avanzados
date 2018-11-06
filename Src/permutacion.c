/*
 * Ejemplo de permutaciones en orden lexicografico en C, 
 * usando algoritmo de R. Sedgewick (ver referencia).
 *
 * Autor: manuel.freire@uam.es & pablo.haya@uam.es
 * (C) 2007-08 Escuela Politecnica Superior, UAM
 */

#include <stdio.h>
#include <stdlib.h>
#include "../Include/struct.h"

/* 
 * OJO: las permutaciones llegan *invertidas*, y se debe
 * ignorar P[0] y llegar hasta P[N] (en lugar de P[N-1])
 */
void process(int* P, int N, int* total, Matriz* matriz) 
{ 
  int i;  
  for (i=N; i>0; i--) {
    //printf("%d ", P[i]);
    matriz->listPath[*total].path[N-i] = P[i];
  }  
  (*total) ++;
  if (*total % 100 == 0)
    printf("Llegamos a %d \n", *total);
}

/* esto seguro que sabes lo que hace ... */
void swap(int *x, int *y) 
{ 
  int temp = *x;
  *x = *y;
  *y = temp;
}

/* ==== Comienzo de la magia ==== 
 * Extraido de R. Sedgewick, "Permutations Generation Methods"
 * ACM Computing Surveys, Vol. 9, No. 2, p. 154, Junio 1977
 */

/* invierte el orden del array de enteros P */
void reverse (int *P, int N) 
{
  int i = 1;  
  while ( i < (N+1-i) ) {
    swap(&P[i], &P[N+1-i]);
    i ++;
  }
}

int B(int N, int c) {  
  return ( (N % 2) != 0 ? 1 : c );
}

/* permutaciones en orden lexicografico; cuenta tambien el total 
 * OJO: el elemento '0' del array P *no* se procesa; y P[N] *sÃ­* cuenta
 */
void lexperms (int *P, int N, int *total, Matriz* matriz) 
{
  
  int i;
  int c[N];
  for (i = N; i > 1; i --) {
    c[i] = 1;
  }
  i = 2;
  
  process(P,N,total,matriz);   
  do {
    if (c[i] < i) {
      swap(&P[i],&P[c[i]]);
      reverse(P,i-1); /* inversion parcial! */
      process(P,N,total,matriz);
      c[i] ++;
      i = 2;
    } else {
      c[i] = 1;
      i ++;
    }
  } while (i <= N);
}
    
/* ==== Final de la magia ==== */    
    
/* main de prueba; usa un array estatico de 20 elementos; pero
 * 17! ya vale 355689428096000, y tarda decadas en calcularse: sobra
 */
int permutacion(Matriz* matriz) 
{
  int n, i, P[20], total;
  
  for (i=0; i<20; i++) 
    P[i] = i;
  n = matriz->numbersNodo + 1;
  total = 0;
  lexperms(P,n-1, &total, matriz);
  printf("Total: %d permutaciones\n", total);
  matriz->combinaciones = total;

  return 0;
}