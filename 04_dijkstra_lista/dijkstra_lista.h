#ifndef DIJKSTRA_LISTA_H
#define DIJKSTRA_LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define NUM_VERTICES 6

// Estrutura para representar uma aresta
typedef struct Aresta {
    int destino;
    int peso;
    struct Aresta* prox;
} Aresta;

// Estrutura para lista de adjacência de cada vértice
typedef struct {
    Aresta* inicio;
} ListaAdj;

void inicializarListaAdj(ListaAdj* lista, int numVertices);
void adicionarArestaLista(ListaAdj* lista, int origem, int destino, int peso);
void criarArestasAleatoriasLista(ListaAdj* lista, int numVertices);
void exibirListaAdj(ListaAdj* lista, int numVertices);
void calcularMenorDistanciaLista(ListaAdj* lista, int numVertices);
void dijkstraLista(int numVertices, ListaAdj* lista, int* distancia, int* visitado, int* anterior);
void exibeMenorDistanciaLista(int origem, int destino, const int* distancia, const int* anterior);
void exibePesoLista(ListaAdj* lista, int destino, const int* anterior);
void executarDijkstraLista(void);

#endif // DIJKSTRA_LISTA_H
