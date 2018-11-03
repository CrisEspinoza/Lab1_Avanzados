// Se importan las cosas que ayudaran al funcionamiento del codigo 

#include <stdio.h>
#include <string.h>

// Definimos las estructuras a ocupar dentro de la aplicacion

typedef struct Nodo
{
	int origin;
	int destination;
	int weight;
	//Lista* listaNodos; // Lista que almacena el camino que se realiza para llegar al destino final 
}Nodo;

typedef struct List
{
	int length;
	Nodo* nodo;
}List;

typedef struct Matriz
{
	int numbersNodo;
	int** adjacency;
	List* listNodos;
}Matriz;

// Definimos las funciones que se van a utilizar dentro del codigo 

Matriz *loadMatriz(char nombre[]);
Matriz* createBoard(int numeroDeNodos);
List* addNodo(List* lista , Nodo* aux);
List* createList();
Nodo* createNodo(int peso, int origen, int destino);
void print(Matriz *matriz);
void outputFileMatriz (List* minimalRoute, int totalWeight);