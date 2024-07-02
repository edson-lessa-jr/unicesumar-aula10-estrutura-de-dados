#ifndef BFS_H
#define BFS_H

#define NUM_VERTICES 20 // Define o número de vértices no grafo

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializarMatrizBFS(int matriz[NUM_VERTICES][NUM_VERTICES]); // Função para inicializar a matriz de adjacência
void adicionarArestasAleatoriasBFS(int matriz[NUM_VERTICES][NUM_VERTICES]); // Função para adicionar arestas aleatórias ao grafo
void bfs(int matriz[NUM_VERTICES][NUM_VERTICES], int inicio); // Função para realizar a busca em largura
void executarBFS();
#endif // BFS_H
