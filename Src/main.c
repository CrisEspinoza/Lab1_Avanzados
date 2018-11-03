#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.c"

int main()
{    
	// Se declaran las variables que se van a utilizar
    char name[25];
    int option,flag;
    Matriz* matriz;
    matriz = NULL; // Se inicializa la matriz como nula
 
    do
    {
        printf( "\n   1. Leer archivo");
        printf( "\n   2. Realizar busqueda de camino minimo");
        printf( "\n   3. Crear archivo de salida");
        printf( "\n   4. Reiniciar" );
        printf( "\n   5. Creditos" );
        printf( "\n   6. Salir" );
        printf( "\n\n   Introduzca opcion (1-6): ");

        scanf( "%d", &option );

        /* Inicio del anidamiento */

        switch ( option )
        {
            case 1: system("clear");
                    if (flag == 0)
                    {
                        printf("Ingrese nombre del archivo a leer\n");
                        scanf("%s",name); // Se carga el nombre del archivo
                        matriz = loadMatriz(name); // Se lee el archivo y se almacena en memoria el grafo
                        //print(matriz);
                        flag = 1 ;
                        break;
                    }
                    printf("Ya abrio un archivo reinicie el programa antes de cargar un nuevo archivo\n");
                    break;              

            case 2: system("clear");
                    if (matriz != NULL)
            		{
            			//buscarCaminoMinomo(matriz); // Se busca el camino hacia la llave
            			//printf("Camino minimo  hacia la Llave encontrado , archivo generado\n");
                   	 	break;
                   	}
                    printf("Primero debe cargar alguna matriz, elegir opcion 1 \n");
                    break;     

            case 3: system("clear");
                    if (matriz != NULL)
                    {
                       //outputFileMatriz();
                    }
                    printf("Primero debe cargar alguna matriz, elegir opcion 1 \n");
                    break;           	

            case 4: system("clear");
                    if(flag == 0)
                    {
                        printf("Debe ocupar al menos en una oportunidad el programa para poder reiniciarlo\n");
                        break;
                    }
                    printf("Programa reiniciado\n");
                    flag = 0;
                    free(matriz);
                    break;

            case 5: system("clear");
                    printf(" * Autor: CRISTIAN EDUARDO ESPINOZA SILVA \n ");
                    printf(" * Universidad santiago de chile \n");
                    break;
        }

    }while(option != 6);

    return 0;
}