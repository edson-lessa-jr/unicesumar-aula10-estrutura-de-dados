#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>


#define NUM_CAVERNAS 20 // Define o numero de cavernas no sistema

// Declara as funcoes
void inicializarSistemaCavernas(int cavernas[NUM_CAVERNAS][NUM_CAVERNAS], int numCavernas);
void adicionarPassagem(int cavernas[NUM_CAVERNAS][NUM_CAVERNAS], int origem, int destino, int peso);
void criarPassagensAleatorias(int cavernas[NUM_CAVERNAS][NUM_CAVERNAS], int numCavernas);
void exibirCavernasEArestas(int cavernas[NUM_CAVERNAS][NUM_CAVERNAS], int numCavernas);
void calcularMenorDistancia(int cavernas[NUM_CAVERNAS][NUM_CAVERNAS], int numCavernas);
void executarDijkstra(); // Funcao principal que chama a funcao executarDijkstra
void dijkstra(int numCavernas, int cavernas[NUM_CAVERNAS][NUM_CAVERNAS], int *distancia, int *visitado, int *anterior);
void exibeMenorDistancia(int origem, int destino, const int *distancia, const int *anterior);
void exibePeso(int cavernas[NUM_CAVERNAS][NUM_CAVERNAS], int destino, const int *anterior);

void origemDestino(int *origem, int *destino);


#endif // DIJKSTRA_H
