// Se importan las cosas que ayudaran al funcionamiento del codigo 
#include <stdio.h>
#include <string.h>

// Definimos las estructuras a ocupar dentro de la aplicacion

typedef struct Nodo
{
	int origen;
	int destino;
	int peso;
}Nodo;

typedef struct Lista
{
	int largo;
	Nodo* nodo;
}Lista;

typedef struct Matriz
{
	int numeroDeNodos;
	int** adyacencia;
	Lista* listaNodos;
	int entrada;
	int llave;
	int salida;
}Matriz;

// Definimos las funciones que se van a utilizar dentro del codigo 

Matriz *cargar(char nombre[]);