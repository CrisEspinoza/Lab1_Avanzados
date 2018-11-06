#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../Include/struct.h"


int contador1 = 0;

// ******************   Funciones principales  ******************//

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

int factorial(int numero)
{
  int c, fact = 1;
 
  for (c = 1; c <= numero; c++)
    fact = fact * c;
 
  return fact;
}

void bruteForce (Matriz* matriz) 
{
    int i,j,z,contador = 0, largo = 0,numero = 0, combinacion = factorial(matriz->numbersNodo),sumWeigth = 0, minimo = 0;    
    int listNumbers[matriz->numbersNodo];
    srand(time(NULL));
    printf("EL largo de la lista es: %d", factorial(matriz->numbersNodo));
    matriz->listPath = (List*)malloc(sizeof(List)* factorial(matriz->numbersNodo) );
    for(i = 0 ; i < combinacion ; i++)
    {
        matriz->listPath[i].path = (int*)malloc(matriz->numbersNodo*sizeof(int));
    }
    for (i = 0; i < matriz->numbersNodo ; i++)
    { 
        printf("ENtre aca ajajajajaj\n");
        while (contador < (combinacion/matriz->numbersNodo))
        { 
            listNumbers[largo] = i;
            printf("%d-%d ** ", i ,listNumbers[largo]);
            largo++;
            while (largo < matriz->numbersNodo)
            {
                numero = rand()%matriz->numbersNodo;
                //printf("EL numero generado es : %d", numero);
                if (viewNumber(numero,listNumbers,matriz->numbersNodo) != 1)    
                {
                    listNumbers[largo] = numero;
                    printf("%d-%d ** ", numero ,listNumbers[largo]);
                    largo++;
                }
            }
            printf("\n");
            printf("Numero de contador lista final : %d \n", contador1);
                        
            if (revisarListaFinal(matriz,listNumbers,contador1) == 1)
            {
                printf("%d %d %d", matriz->listPath[contador].path[0],matriz->listPath[contador].path[1],matriz->listPath[contador].path[2]);
                contador++;
                
                for (z = 0 ; z < matriz->numbersNodo ; z++)
                {
                    matriz->listPath[contador1].path[z] = listNumbers[z];
                }
                contador1++;
            }   
            
            //free(listNumbers);
            reiniciarList(listNumbers,matriz->numbersNodo);
            largo = 0;
            printf("\n");
        }
        reiniciarList(listNumbers,matriz->numbersNodo);
        printf ("\n");
        printf ("\n");
        printf ("************************* \n");
        printf ("\n");
        printf ("\n");
        contador = 0;
    }

    printf("************************************************* Caminos ********************* \n");

    for (i = 0 ; i < combinacion; i++)
    {
        printf("%d %d %d\n", matriz->listPath[i].path[0],matriz->listPath[i].path[1],matriz->listPath[i].path[2]);
    }

    for (i = 0 ; i < combinacion ; i ++ )
    {
        for (j = 0 ; j < (matriz->numbersNodo - 1) ; j++)
        {   
            printf("El peso del camino es: %d \n",matriz->adjacency[matriz->listPath[i].path[j]][matriz->listPath[i].path[j+1]]);
            sumWeigth = sumWeigth + matriz->adjacency[matriz->listPath[i].path[j]][matriz->listPath[i].path[j+1]];
        }
        matriz->listPath[i].weigth  = sumWeigth + 2 ;
        sumWeigth = 0 ;
    }

    printf("************************************************* Pesos *************************** \n");

    for (i = 0 ; i < matriz->numbersNodo ; i ++ )
    {
        for (j = 0 ; j < matriz->numbersNodo  ; j++)
        {   
            printf("%d " , matriz->adjacency[i][j]);
        }
        printf("\n");
    }

    for (i = 0 ; i < combinacion; i++)
    {
        printf("%d \n", matriz->listPath[i].weigth);
    }

    minimo = matriz->listPath[0].weigth;
    for (i = 1 ; i < combinacion; i++)
    {
        if (minimo > matriz->listPath[i].weigth)
            minimo = matriz->listPath[i].weigth;
    }

    printf("El peso menor es: %d ", minimo);

    saveTablero(matriz,minimo);    
}

int revisarListaFinal (Matriz* matriz, int listCaminos[],int fin)
{
    int i,j,contador = 0;
    
    for(i = 0 ; i < fin ; i++)
    {
        for (j = 0 ; j < matriz->numbersNodo ; j++)
        {
            if (matriz->listPath[i].path[j] == listCaminos[j])
            {
                //printf("%d %d ", matriz->listPath[i].path[j] , listCaminos[j]);
                //printf("*****************************************************");
                //printf("El valor del contador es : %d",contador);
                contador++;
            }
        }
        if (contador == matriz->numbersNodo)
        {
            printf("eNTRE ACA");
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
    {
        listNumbers[i] = -1;
    }
}





// ******************   Funciones para realizar escritura y lectura de archivos  ******************//

Matriz* loadMatriz (char nombre[])
{
	FILE *file; // Declaramos un puntero File para poder leer el file de entrada.
	char* route = (char*)calloc(100, sizeof(char));
	strcat(route, "../Documents/");
	strcat(route, nombre);
    strcat(route, ".txt");
    file = fopen (route, "r"); // Estamos abriendo el file en modo lectura

    Matriz* matriz; // Se declara una variable de tipo matriz
    int numbersNodo,destination,origin,weight; 

    //Verificamos si el file se encuentra nulo
    if( file == NULL)
    {
        printf("Error al abrir archivo \n");
        return NULL;
    }

    // Leemos las primeras lineas del file para un mejor manejo de este
    fscanf(file, "%d", &numbersNodo);

    // Creamos el tablero para luego colocar lo extraido desde el file
    matriz = createBoard(numbersNodo); //Creamos un tablero con las dimensiones que tendra el tablero   

    while(getc(file) != '\n'); // Que lea el file siempre y cuando no sea un salto de linea
    while (!feof(file)) 
    {
        fscanf(file, "%d %d %d",&origin, &destination ,&weight);
        printf("%d %d %d \n", origin,destination,weight );
        matriz->adjacency[origin-1][destination-1] = weight; // Cada caracter que lea sera almacenado en la variable de tipo (struct Tablero)
    }
    
    fclose(file); // Cerramos el file
 
    return matriz; //Retornamo la variable matriz, con el tablero contenido, el cual se leyó desde el file ingresado

}

void saveTablero (Matriz* matriz, int pesoTotalMinimo)
{   
    printf("ENtre aca ajjajajajaja salida ajja");
    FILE *txt;  // Incialzamos una variable de tipo FILE para poder trabajar con los archivos
    txt = fopen("../Out/Salida.out", "wt");
    int i , j;
    fprintf(txt,"%d",pesoTotalMinimo); // Se coloca el peso total ocupado en la ruta minima obtenida y se pone en el archivo
    fprintf(txt, "\n"); // S ehace un salto de linea en ele archio
    
    for (i = 0; i < factorial(matriz->numbersNodo) ; i++)
    {
        if (pesoTotalMinimo == matriz->listPath[i].weigth)
        {
            for (j = 0; j < matriz->numbersNodo; j++)
            {
                if (j == (matriz->numbersNodo-1))
                    fprintf(txt, " %d \n", matriz->listPath[i].path[j]);
                else
                    fprintf(txt, " %d -", matriz->listPath[i].path[j]);
            }
        }
    }

    fclose(txt); // Cerramos el archivo
}





// ******************   Funciones para realizar eventos I/O   ******************//

void printBoard(Matriz *matriz)
{
    for (int i = 0; i < matriz->numbersNodo; i++)
    {
        for (int j = 0; j < matriz->numbersNodo; j++)
        {
            printf("%d  ", matriz->adjacency[i][j]); //Imprimos por pantalla cada una de las caracteristicas que guarda dentro de si el tablero
        }
        printf("\n");
    }  
}
