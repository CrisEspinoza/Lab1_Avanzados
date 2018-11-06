#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "../Include/struct.h"

// Variables Globales

int contador1 = 0;

// ****************** Funcion principal ******************//

Matriz*  bruteForce (Matriz* matriz) 
{
    int i,j,z,contador = 0, largo = 0,numero = 0, combinacion = factorial(matriz->numbersNodo),sumWeigth = 0, minimo = 0;    
    int listNumbers[matriz->numbersNodo];
    srand(time(NULL));
    matriz->listPath = (List*)malloc(sizeof(List)* factorial(matriz->numbersNodo) );
    for(i = 0 ; i < combinacion ; i++)
        matriz->listPath[i].path = (int*)malloc(matriz->numbersNodo*sizeof(int));
    
    for (i = 0; i < matriz->numbersNodo ; i++)
    { 
        while (contador < (combinacion/matriz->numbersNodo))
        { 
            listNumbers[largo] = i;
            largo++;

            while (largo < matriz->numbersNodo)
            {
                numero = rand()%matriz->numbersNodo;
                if (viewNumber(numero,listNumbers,matriz->numbersNodo) != 1)    
                {
                    listNumbers[largo] = numero;
                    largo++;
                }
            }
                       
            if (revisarListaFinal(matriz,listNumbers,contador1) == 1)
            {
                for (z = 0 ; z < matriz->numbersNodo ; z++)
                    matriz->listPath[contador1].path[z] = listNumbers[z];
                contador1++;      
                contador++;
            }   
            
            reiniciarList(listNumbers,matriz->numbersNodo);
            largo = 0;
        }
        
        reiniciarList(listNumbers,matriz->numbersNodo);
        contador = 0;
    }

    for (i = 0 ; i < combinacion ; i ++ )
    {
        for (j = 0 ; j < (matriz->numbersNodo - 1) ; j++)
        {   
            sumWeigth = sumWeigth + matriz->adjacency[matriz->listPath[i].path[j]][matriz->listPath[i].path[j+1]];
        }
        matriz->listPath[i].weigth  = sumWeigth + 2 ;
        sumWeigth = 0 ;
    }

    minimo = matriz->listPath[0].weigth;
    for (i = 1 ; i < combinacion; i++)
    {
        if (minimo > matriz->listPath[i].weigth)
            minimo = matriz->listPath[i].weigth;
    }
    matriz->minimoPeso = minimo;

    return matriz;
}
