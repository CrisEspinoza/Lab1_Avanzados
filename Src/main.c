#include <stdio.h>
#include <string.h>
#include "functions.c"

int main()
{    
	// Se declaran las variables que se van a utilizar
    char nombre[25];
    int opcion;
    Matriz* matriz;
    matriz = NULL; // Se inicializa la matriz como nula
 
    do
    {
        printf( "\n   1. Leer archivo");
        printf( "\n   2. Realizar busqueda de camino minimo");
        printf( "\n   3. Creditos" );
        printf( "\n   4. Salir" );
        printf( "\n\n   Introduzca opcion (1-4): ");

        scanf( "%d", &opcion );

        /* Inicio del anidamiento */

        switch ( opcion )
        {
            case 1: printf("Ingrese nombre del archivo a leer\n");
                    scanf("%s",nombre); // Se carga el nombre del archivo
                    matriz = cargar(nombre); // Se lee el archivo y se almacena en memoria el grafo
                    break;              

            case 2: if (matriz != NULL)
            		{
            			//buscarCaminoMinomo(matriz); // Se busca el camino hacia la llave
            			//printf("Camino minimo  hacia la Llave encontrado , archivo generado\n");
                   	 	break;
                   	}
                    printf("Primero debe cargar alguna matriz, elegir opcion 1 \n");
                    break;                   	

            case 3: printf(" * Autor: CRISTIAN EDUARDO ESPINOZA SILVA \n ");
                    printf(" * Universidad santiago de chile \n");
                    break;
        }

    }while(opcion!=4);

    return 0;
}