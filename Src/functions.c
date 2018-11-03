#include <stdio.h>
#include <string.h>
#include "../Include/struct.h"





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
    Nodo* auxiliaryNodo;// Se declara una variable de tipo nodo
    int numbersNodo,destination,origin,weight;

    //Verificamos si el file se encuentra nulo
    if( file == NULL)
    {
        printf("Error al abrir archivo \n");
        return 0;
    }

    // Leemos las primeras lineas del file para un mejor manejo de este
    fscanf(file, "%d", &numbersNodo);
    while(getc(file) != '\n');

    // Creamos el tablero para luego colocar lo extraido desde el file
    matriz = createBoard(numbersNodo); //Creamos un tablero con las dimensiones que tendra el tablero

    //Guardamos las posiciones mas importantes del laberinto
    matriz->listNodos = createList(); //Creamos la lista de nodos 

    while(getc(file) != '\n'); // Que lea el file siempre y cuando no sea un salto de linea
    while (!feof(file)) 
    {
        fscanf(file, "%d %d %d",&origin, &destination ,&weight);
        //printf("%d %d %d \n", origin,destination,weight );
        matriz->adjacency[origin-1][destination-1] = weight; // Cada caracter que lea sera almacenado en la variable de tipo (struct Tablero)
        matriz->adjacency[destination-1][origin-1] = weight;
        auxiliaryNodo = createNodo(weight,origin,destination); // Creamos un nuevo nodo con lo caputrado desde el file
        addNodo(matriz->listNodos,auxiliaryNodo); // Agregamos el nodo creado a la lista
        auxiliaryNodo = createNodo(weight,destination,origin); // Agregamos el reciproco de lo leido en la lista
        addNodo(matriz->listNodos,auxiliaryNodo); // Lo agregamos a la lista el nuevo nodo creado
    }
    
    fclose(file); // Cerramos el file
 
    return matriz; //Retornamo la variable matriz, con el tablero contenido, el cual se leyó desde el file ingresado

}

void outputFileMatriz (List* minimalRoute, int totalWeight)
{
    FILE *outputFile;  // Incialzamos una variable de tipo FILE para poder trabajar con los archivos
    int i;

    outputFile = fopen("Salida.out", "a"); // Abrimos el archivo en modo sobreescritura, para no perder el camino anterior que esta en el archivo
    fprintf(outputFile,"\n");
    fprintf(outputFile,"La distancia recorrida es: %d",totalWeight); // Se coloca el peso total ocupado en la ruta minima obtenida y se pone en el archivo
	fprintf(outputFile, "\n"); // S ehace un salto de linea en ele archio
    fprintf(outputFile, "\n"); // S ehace un salto de linea en ele archio
    
    for (i = minimalRoute->length-1 ; i >= 0 ; i--)
    {
    	if (i == 0)
    		fprintf(outputFile,"%d ",minimalRoute->nodo[i].destination); // Se escribe la ruta minima en el archivo
    	else
    		fprintf(outputFile,"%d - ",minimalRoute->nodo[i].destination); // Se escribe la ruta minima en el archivo
    }

    fclose(outputFile); // Cerramos el archivo
}






// ******************   Funciones para trabajar listas de nodos   ******************//

List* createList() // Creamos la lista nueva 
{
    List* list = (List*)malloc(sizeof(List)); // Pedimos memoria para la nueva lista 
    list->nodo = NULL;
    list->length = 0 ; // El length de la lista es igual a "0".
    return list; // Se retorna la lista creada
}

Nodo* createNodo(int weight, int origin, int destination)
{
    Nodo* newNodo = (Nodo*)malloc(sizeof(Nodo)); // Pedimos memoria para el nuevo nodo declarado
    if (newNodo != NULL)
    {
        newNodo->weight = weight; // Asignamos lo que recibe la funcion a la variable direccion
        newNodo->origin = origin; // Asignamo el valor de file que recibe a lo que pertenece a la estructura
        newNodo->destination = destination; // Asignamos el valor de columna que recibe a lo que pertenece a ala estructura
    }
    return newNodo; // Se retorna el nuevo nodo creado
}

List* addNodo(List* list , Nodo* auxiliary)
{
    if(list->length == 0)
    {
    	list->nodo = (Nodo*)malloc(sizeof(Nodo));
    	list->nodo[0] = *auxiliary;
    }
    else
    {
        list->nodo = (Nodo*)realloc(list->nodo, (list->length + 1) * sizeof (Nodo)); // Pedimos mas memoria para el arreglo creado
        list->nodo[list->length] = *auxiliary; // Agregamos el nodo que se desea agregar, luego de haber solicitado memoria
    }
    list->length++; // aumnetamos el length de la list de arreglos
    return list;
}






// ******************   Funciones para realizar eventos I/O   ******************//

void print(Matriz *matriz)
{
    for (int i = 0; i < matriz->numbersNodo; i++)
    {
        for (int j = 0; j < matriz->numbersNodo; j++)
        {
            printf("%d  ", matriz->adjacency[i][j]); //Imprimos por pantalla cada una de las caracteristicas que guarda dentro de si el tablero
        }
        printf("\n");
    }

    for (int j = 0; j < matriz->listNodos->length; j++)
    {
        // Mostramos por pantalla detalladamente cada uno de los valores que contiene la lista
    	printf("Entrada es: %d , la salida es: %d y el peso es : %d \n",matriz->listNodos->nodo[j].origin,matriz->listNodos->nodo[j].destination,
    		matriz->listNodos->nodo[j].weight);
    }   
}

void printCurrent(Nodo* nodo)
{
	printf("\n");
	printf("******* *******\n");
	printf("\n");
	printf("Nodo actual: %d \n", nodo->origin);
	printf("Nodo de destino: %d \n", nodo->destination );
	printf("Costo de viaje: %d\n", nodo->weight);
	//printf("Camino actual: \n", );
	printf("\n");
	printf("******* *******\n");
	printf("\n");
}