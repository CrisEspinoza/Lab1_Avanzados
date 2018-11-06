#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "../Include/struct.h"


// ****************** Funcion principal ******************//

Matriz*  bruteForce (Matriz* matriz)
{
    int i,j,combinacion = factorial(matriz->numbersNodo),sumWeigth = 0,minimo = 0;
    matriz->listPath = (List*)malloc(sizeof(List)*(combinacion+1) );
    for(i = 0 ; i < combinacion ; i++)
        matriz->listPath[i].path = (int*)malloc(matriz->numbersNodo*sizeof(int));
    
    permutacion(matriz);

    for (i = 0 ; i < combinacion ; i ++ )
    {
        for (j = 0 ; j < (matriz->numbersNodo - 1) ; j++)
        {   
            sumWeigth = sumWeigth + matriz->adjacency[matriz->listPath[i].path[j]-1][matriz->listPath[i].path[j+1]-1];
        }
        matriz->listPath[i].weigth  = sumWeigth + 2 ;
        sumWeigth = 0 ;
    }

    printCurrent(matriz);

    minimo = matriz->listPath[0].weigth;
    for (i = 1 ; i < combinacion; i++)
    {
        if (minimo > matriz->listPath[i].weigth)
            minimo = matriz->listPath[i].weigth;
    }
    matriz->minimoPeso = minimo;

    return matriz;
}