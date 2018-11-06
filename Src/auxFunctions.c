#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../Include/struct.h"

// **************** Funciones auxiliares ******************

int factorial(int numero)
{
  int c, fact = 1;
 
  for (c = 1; c <= numero; c++)
    fact = fact * c;
 
  return fact;
}

int revisarListaFinal (Matriz* matriz, int listCaminos[],int fin)
{
    int i,j,contador = 0;
    
    for(i = 0 ; i < fin ; i++)
    {
        for (j = 0 ; j < matriz->numbersNodo ; j++)
            if (matriz->listPath[i].path[j] == listCaminos[j])
                contador++;
        
        if (contador == matriz->numbersNodo)
            return 0;
        
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