#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 1000000

/* variavel para salvar o peso dos vertices apos a leitura do arquivo */
int *pesoVertice;

/* Struct Arco */
typedef struct{
    int v;
    int w;
} Arco;

/* Struct Aresta */
typedef struct{
    int v;
    int w;
} Aresta;

/* Struct Grafo representado por matriz */
struct grafo{
    int n;
    int m;
    int **adj;
};

/* Um Grafo é um ponteiro para um grafo, ou seja, Grafo contém o endereço de um grafo. */
typedef struct grafo *Grafo;

/* TAD GRAFO */
Grafo GRAFOcria(int);
void GRAFOinsereA(Grafo, Arco, int);
void GRAFOinsereE(Grafo, Aresta, int);
void GRAFOimprime(Grafo);
void GRAFOdestroi(Grafo);

int **MATRIZint(int l, int c);

void Prim(Grafo G, int* pesoVertice);

Grafo leitura(const char *nomeDoArquivo);