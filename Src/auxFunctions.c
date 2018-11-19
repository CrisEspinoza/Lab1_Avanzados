#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "../Include/struct.h"

#define DEBUG

// **************** Funciones auxiliares ******************

/* 
Entrada: Recibe la matriz que se utiliza actualmente.
Procedimiento: Se encarga de ir imprimiendo cada uno de los caminos generados y su respectivo costo de viaje.
Salida: -.
*/
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

/* 
Entrada: Recibe un numero "x".
Procedimiento: Se encarga de calcular el factorial del numero ingresado.
Salida: Entrega el factorial del numero ingresado.
*/

int factorial(int numero)
{
  int c, fact = 1;
 
  for (c = 1; c <= numero; c++)
    fact = fact * c;
 
  return fact;
}

int contador2 = 0;

/* 
Entrada: Recibe una lista de numero y el final de la listaFinal de caminos generados hasta el momento.
Procedimiento: Se encarga de verificar si una lista de camino se encuentra ya en la lista final.
Salida: Entrega un numero que representa un valor booleano que indica si se encuentra o no en la lista final de caminos.
*/

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

/* 
Entrada: Reccibe un numero entero, una lista de numero y su respectivo largo de la lista.
Procedimiento: Se encarga de verificar si el numero ingresado se encuentra en la lista ingresada como parametro.
Salida: Entrega un numero que representa un valor booleano que indica si se encuentra o no en la lista ingresada como parametro.
*/

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

/* 
Entrada: Recibe una lista de numeros y su respectivo largo.
Procedimiento: Se encarga de resetear cada uno de sus valores y setenado cada posicion de la lista en -1.
Salida: -.
*/

void reiniciarList (int listNumbers[], int largo)
{
    int i;
    for(i = 0 ; i < largo; i++)
        listNumbers[i] = -1;
    
}

/* 
Entrada: Recibe la variable matriz.
Procedimiento: Se encarga de liberar la memoria de la variable matriz que se ocupa a lo largo del programa, que ayuda a reiniciar el programa 
sin necesidad que se tenga que volver a ejecutar.
Salida: -.
*/

void freeMemory(Matriz* matriz)
{
    int i;
    for(i = 0 ; i < matriz->numbersNodo; i++)
        free(matriz->adjacency[i]);
    free(matriz->adjacency);
    for(i = 0; i < (matriz->combinaciones + 1 ) ; i++)
        free(matriz->listPath[i].path);
    free(matriz->listPath);
    free(matriz);
}