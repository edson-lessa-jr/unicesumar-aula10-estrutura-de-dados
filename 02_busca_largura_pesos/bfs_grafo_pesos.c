#include "bfs_grafo_pesos.h"

void inicializarMatrizPesos(int matriz[NUM_VERTICES][NUM_VERTICES]) {
    for (int i = 0; i < NUM_VERTICES; i++) {
        for (int j = 0; j < NUM_VERTICES; j++) {
            matriz[i][j] = 0; // Sem aresta inicialmente
        }
    }
}

void adicionarArestasPesosAleatorios(int matriz[NUM_VERTICES][NUM_VERTICES]) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < NUM_VERTICES; i++) {
        for (int j = i + 1; j < NUM_VERTICES; j++) {
            if (rand() % 2) { // 50% de chance de criar uma aresta
                int peso = (rand() % 10) + 1; // Peso de 1 a 10
                matriz[i][j] = peso;
                matriz[j][i] = peso; // Grafo não direcionado
            }
        }
    }
}

void bfsComPesos(int matriz[NUM_VERTICES][NUM_VERTICES], int inicio) {
    int visitado[NUM_VERTICES] = {0};
    int fila[NUM_VERTICES], front = 0, rear = 0;

    visitado[inicio] = 1;
    fila[rear++] = inicio;

    while (front < rear) {
        int vertice = fila[front++];
        printf("Visitando vertice %d\n", vertice);

        for (int i = 0; i < NUM_VERTICES; i++) {
            if (matriz[vertice][i] > 0 && !visitado[i]) { // Verifica existencia de aresta (peso > 0)
                printf("  Aresta encontrada: %d -> %d (peso: %d)\n", vertice, i, matriz[vertice][i]);
                fila[rear++] = i;
                visitado[i] = 1;
            }
        }
    }
}

void executarBFSComPesos(void) {
    int matriz[NUM_VERTICES][NUM_VERTICES];
    inicializarMatrizPesos(matriz);
    adicionarArestasPesosAleatorios(matriz);

    printf("Matriz de adjacencia com pesos:\n");
    for (int i = 0; i < NUM_VERTICES; i++) {
        for (int j = 0; j < NUM_VERTICES; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nResultado da Busca em Largura (BFS) com Pesos:\n");
    bfsComPesos(matriz, 0);

    printf("\nPressione Enter para voltar ao menu principal...\n");
    getchar();
    getchar();
}
