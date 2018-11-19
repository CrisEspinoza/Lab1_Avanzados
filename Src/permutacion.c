
#include <stdio.h>
#include <stdlib.h>
#include "../Include/struct.h"

/* 
Entrada: Recibe como pamatro un entero que indica el numero que se lleva, uno que indica el numero del arreglo, el total que se tiene hasta el 
momento, y por utlimo la matriz.
Procedimiento: Se procede a ingresar cada termino que genera la combinacion a la lista que se encuentra en la variable matriz.
Salida: -.
*/

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

/* 
Entrada: Recibe dos enteros como entrada.
Procedimiento: Se encarga de cambiar el valor de las dos variables que se ingresan como parametro
Salida: -.
*/

void swap(int *x, int *y) 
{ 
  int temp = *x;
  *x = *y;
  *y = temp;
}

/* 
Entrada: Recibe como entrada un entero y el puntero que indica el numero generado.
Procedimiento: Se encarga de cambiar el orden de los digitos que se crearon en la permutacion.
Salida: -.
*/

void reverse (int *P, int N) 
{
  int i = 1;  
  while ( i < (N + 1 - i) ) 
  {
    swap(&P[i], &P[N+1-i]);
    i ++;
  }
}

/* 
Entrada: Recibe como parametro dos enteros los cuales indican el numero a verificar y el otro numero si no se cumple dicha condicion.
Procedimiento: Se encarga de verificar si se cumple la condicion de si el parametro ingresado en par o no.
Salida: Entrega una valor entero.
*/

int B(int N, int c) 
{  
  return ( (N % 2) != 0 ? 1 : c );
}

/* 
Entrada: Recibe como parametro los numeros que se estan generando, el numero que indica de donde se parte, el total que se lleva hasta el 
momento y por utlimo la matriz que se estan ocupando dentro del codigo
Procedimiento: Funcion que genera los numeros de la combinacion que se esta estudiando actualmente.
Salida: -.
*/

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

/* 
Entrada: Recibe como parametro la matriz que se esta trabajando dentro del codigo.
Procedimiento: Se encarga de unir cada una de las funciones que realizan la combionacion de cada una de los caminos que se pueden 
generan con la cantidad de nodos que se estan trabajando actualmente.
Salida: Entrega un valor entero que indica cuando termina el codigo.
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