#ifndef BFS_GRAFO_PESOS_H
#define BFS_GRAFO_PESOS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_VERTICES 6

void inicializarMatrizPesos(int matriz[NUM_VERTICES][NUM_VERTICES]);
void adicionarArestasPesosAleatorios(int matriz[NUM_VERTICES][NUM_VERTICES]);
void bfsComPesos(int matriz[NUM_VERTICES][NUM_VERTICES], int inicio);
void executarBFSComPesos(void);

#endif // BFS_GRAFO_PESOS_H
