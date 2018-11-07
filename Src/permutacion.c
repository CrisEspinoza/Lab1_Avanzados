
#include <stdio.h>
#include <stdlib.h>
#include "../Include/struct.h"

void process(int* P, int N, int* total, Matriz* matriz) 
{ 
  int i;  
  for ( i = N ; i > 0; i--) 
  {
    //printf("%d ", P[i]);
    matriz->listPath[*total].path[N-i] = P[i];
  }  
  //printf("\n");
  (*total)++;
  //if (*total % 10000 == 0)
    //printf("Llegamos a %d \n", *total);
}

void swap(int *x, int *y) 
{ 
  int temp = *x;
  *x = *y;
  *y = temp;
}

void reverse (int *P, int N) 
{
  int i = 1;  
  while ( i < (N + 1 - i) ) 
  {
    swap(&P[i], &P[N+1-i]);
    i ++;
  }
}

int B(int N, int c) 
{  
  return ( (N % 2) != 0 ? 1 : c );
}

void lexperms (int *P, int N, int *total, Matriz* matriz) 
{
  int i;
  int c[N];
  for (i = N; i > 1; i --) 
  {
    c[i] = 1;
  }
  i = 2;
  
  process(P,N,total,matriz);   
  do 
  {
    if (c[i] < i) 
    {
      swap(&P[i],&P[c[i]]);
      reverse(P,i-1); /* inversion parcial! */
      process(P,N,total,matriz);
      c[i] ++;
      i = 2;
    } 
    else 
    {
      c[i] = 1;
      i ++;
    }
  }while (i <= N);
}
    
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