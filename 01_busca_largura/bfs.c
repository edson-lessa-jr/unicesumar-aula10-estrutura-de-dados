#include "bfs.h"

void inicializarMatrizBFS(int matriz[NUM_VERTICES][NUM_VERTICES]) {
    for (int i = 0; i < NUM_VERTICES; i++) {
        for (int j = 0; j < NUM_VERTICES; j++) {
            matriz[i][j] = 0; // Inicializa cada entrada da matriz com 0 (sem aresta)
        }
    }
}

void adicionarArestasAleatoriasBFS(int matriz[NUM_VERTICES][NUM_VERTICES]) {
    srand(time(NULL)); // Inicializa a semente para números aleatórios
    for (int i = 0; i < NUM_VERTICES; i++) {
        for (int j = i + 1; j < NUM_VERTICES; j++) {
            if (rand() % 2) { // Adiciona uma aresta com probabilidade de 50%
                matriz[i][j] = 1; // Define a entrada (i, j) como 1 (existe uma aresta)
                matriz[j][i] = 1; // Para grafos não direcionados, adiciona também a aresta oposta
            }
        }
    }
}

void bfs(int matriz[NUM_VERTICES][NUM_VERTICES], int inicio) {
    int visitado[NUM_VERTICES] = {0}; // Array para marcar os vértices visitados
    int fila[NUM_VERTICES], front = 0, rear = 0; // Array para a fila e variáveis de controle

    visitado[inicio] = 1; // Marca o vértice inicial como visitado
    fila[rear++] = inicio; // Adiciona o vértice inicial à fila

    while (front < rear) {
        int vertice = fila[front++]; // Remove o primeiro vértice da fila
        printf("Visitando vertice %d\n", vertice); // Imprime o vértice visitado

        for (int i = 0; i < NUM_VERTICES; i++) { // Itera sobre os vértices adjacentes
            if (matriz[vertice][i] == 1 && !visitado[i]) { // Se há uma aresta e o vértice não foi visitado
                fila[rear++] = i; // Adiciona o vértice à fila
                visitado[i] = 1; // Marca o vértice como visitado
            }
        }
    }
}

void executarBFS() {
    int matriz[NUM_VERTICES][NUM_VERTICES]; // Declara a matriz de adjacência
    inicializarMatrizBFS(matriz); // Inicializa a matriz de adjacência
    adicionarArestasAleatoriasBFS(matriz); // Adiciona arestas aleatórias ao grafo
    printf("Resultado da Busca em Largura (BFS):\n");
    bfs(matriz, 0); // Executa a busca em largura a partir do vértice 0
    printf("\nPressione Enter para voltar ao menu principal...\n");
    getchar(); // Aguarda o usuário pressionar Enter
    getchar(); // Aguarda o usuário pressionar Enter
}