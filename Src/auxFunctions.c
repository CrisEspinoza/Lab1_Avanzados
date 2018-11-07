#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../Include/struct.h"

//#define DEBUG

// **************** Funciones auxiliares ******************

void printCurrent(Matriz* matriz)
{
    #ifdef DEBUG
    int i,j;
    for(i = 0 ; i < matriz->combinaciones ; i ++)
    {
        for (j = 0 ; j < matriz->numbersNodo ; j++)
        {
            if (j == 0) 
                printf("Camino: ");
            if (j == (matriz->numbersNodo-1))
                printf("%d  | | | | | | ",matriz->listPath[i].path[j]);
            else
                printf("%d - ",matriz->listPath[i].path[j]);
        }
        printf(" Peso es: %d \n", matriz->listPath[i].weigth );
    } 
    #endif
}

int factorial(int numero)
{
  int c, fact = 1;
 
  for (c = 1; c <= numero; c++)
    fact = fact * c;
 
  return fact;
}

int contador2 = 0;

int revisarListaFinal (Matriz* matriz, int listCaminos[],int fin)
{
    int i,j,contador = 0;
    
    for(i = 0 ; i < fin ; i++)
    {
        for (j = 0 ; j < matriz->numbersNodo ; j++)
            if (matriz->listPath[i].path[j] == listCaminos[j])
                contador++;
        if (contador == matriz->numbersNodo)
        {
            contador2++;
            if (contador2 % 1000 == 0)
                printf("EL contador es: %d \n", contador2);
            return 0;
        }
        contador = 0;
    }
    return 1;
}

int viewNumber (int numero, int listNumbers[], int largo)
{
    int i;
    for (i = 0 ; i < largo; i++)
    {
        if (listNumbers[i] == numero)
            return 1;
    }
    return 0 ;
}

void reiniciarList (int listNumbers[], int largo)
{
    int i;
    for(i = 0 ; i < largo; i++)
        listNumbers[i] = -1;
    
}