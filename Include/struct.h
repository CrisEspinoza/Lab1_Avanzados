# ifndef STRUCT_H
# define STRUCT_H

// Definimos las estructuras a ocupar dentro de la aplicacion

typedef struct List
{
	int* path;
	int weigth;
}List;

typedef struct Matriz
{
	int numbersNodo;
	int** adjacency;
	List* listPath;
	int minimoPeso;
	int combinaciones;
}Matriz;

// Definimos las funciones que se van a utilizar dentro del codigo 

Matriz *loadMatriz(char nombre[]);
Matriz* createBoard(int numeroDeNodos);
void printBoard(Matriz *matriz);
int viewNumber (int numero, int listNumbers[], int largo);
int factorial(int numero);
void reiniciarList (int listNumbers[], int largo);
int revisarListaFinal (Matriz* matriz, int listCaminos[], int fin);
void saveTablero (Matriz* matriz);
Matriz*  bruteForce (Matriz* matriz);
void freeMemory(Matriz* matriz);

// Permutacion
int permutacion(Matriz* matriz);
void lexperms (int *P, int N, int *total, Matriz* matriz);
void reverse (int *P, int N);
void swap(int *x, int *y);
void process(int* P, int N, int* total, Matriz* matriz);
void printCurrent(Matriz* matriz);

# endif