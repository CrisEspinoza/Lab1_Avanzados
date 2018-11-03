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
}Lista;

typedef struct Matriz
{
	int numbersNodo;
	int** adjacency;
	Lista* listNodos;
}Matriz;

// Definimos las funciones que se van a utilizar dentro del codigo 

Matriz *loadMatriz(char nombre[]);
void print(Matriz *matriz);
Lista* addNodo(Lista* lista , Nodo* aux);
Nodo* createNodo(int peso, int origen, int destino);
Lista* createList();
Matriz* createBoard(int numeroDeNodos);