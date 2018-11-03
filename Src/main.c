#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.c"

int main()
{    
	// Se declaran las variables que se van a utilizar
    char name[25];
    int option;
    Matriz* matriz;
    matriz = NULL; // Se inicializa la matriz como nula
 
    do
    {
        printf( "\n   1. Leer archivo");
        printf( "\n   2. Realizar busqueda de camino minimo");
        printf( "\n   3. Crear archivo de salida");
        printf( "\n   4. Creditos" );
        printf( "\n   5. Salir" );
        printf( "\n\n   Introduzca opcion (1-5): ");

        scanf( "%d", &option );

        /* Inicio del anidamiento */

        switch ( option )
        {
            case 1: printf("Ingrese nombre del archivo a leer\n");
                    scanf("%s",name); // Se carga el nombre del archivo
                    matriz = loadMatriz(name); // Se lee el archivo y se almacena en memoria el grafo
                    //print(matriz);
                    break;              

            case 2: if (matriz != NULL)
            		{
            			//buscarCaminoMinomo(matriz); // Se busca el camino hacia la llave
            			//printf("Camino minimo  hacia la Llave encontrado , archivo generado\n");
                   	 	break;
                   	}
                    printf("Primero debe cargar alguna matriz, elegir opcion 1 \n");
                    break;     

            case 3: if (matriz != NULL)
                    {
                       // crear archivo de salida
                    }
                    printf("Primero debe cargar alguna matriz, elegir opcion 1 \n");
                    break;           	

            case 4: printf(" * Autor: CRISTIAN EDUARDO ESPINOZA SILVA \n ");
                    printf(" * Universidad santiago de chile \n");
                    break;
        }

    }while(option != 5);

    return 0;
}