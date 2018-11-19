#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Include/struct.h"

Matriz* createBoard(int numbersNodo)
{
    int i,j;
    // Procedemos a crear una variable de tipo Tablero y a solicitar memoria para dicha variable
    Matriz *matriz;
    matriz = (Matriz*)malloc(sizeof(Matriz));

    matriz->adjacency = (int**)malloc(numbersNodo*sizeof(int*)); // Inicializamos una de variables que contiene nuestra estructura con tantas filas diga el file
    matriz->numbersNodo = numbersNodo;

    for (i = 0 ; i < numbersNodo ;i++)
    {
        matriz->adjacency[i] = (int*)malloc(numbersNodo*sizeof(int)); // Aca inicializamos las columnas que rescatamos desde el file
        for (j = 0;  j < numbersNodo ;j++)
        {
            matriz->adjacency[i][j] = 0; // Asignamos un elemento neutro que demostrara que el tablero esta creado pero no utilizado 
        }
    }
    return matriz; // retornamos el tablero inicilizado (con elemento que representa estar vacio)
}

void printBoard(Matriz *matriz)
{
    int i,j;
    for (i = 0; i < matriz->numbersNodo; i++)
    {
        for (j = 0; j < matriz->numbersNodo; j++)
            printf("%d  ", matriz->adjacency[i][j]); //Imprimos por pantalla cada una de las caracteristicas que guarda dentro de si el tablero
        
        printf("\n");
    }  
}