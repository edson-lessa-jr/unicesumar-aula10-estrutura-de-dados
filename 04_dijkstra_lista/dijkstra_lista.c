#include "dijkstra_lista.h"

void inicializarListaAdj(ListaAdj* lista, int numVertices) {
    for (int i = 0; i < numVertices; i++)
        lista[i].inicio = NULL;
}

void adicionarArestaLista(ListaAdj* lista, int origem, int destino, int peso) {
    Aresta* nova = (Aresta*)malloc(sizeof(Aresta));
    nova->destino = destino;
    nova->peso = peso;
    nova->prox = lista[origem].inicio;
    lista[origem].inicio = nova;

    // Para grafo nao direcionado, adicione tambem o caminho inverso
    Aresta* nova2 = (Aresta*)malloc(sizeof(Aresta));
    nova2->destino = origem;
    nova2->peso = peso;
    nova2->prox = lista[destino].inicio;
    lista[destino].inicio = nova2;
}

void criarArestasAleatoriasLista(ListaAdj* lista, int numVertices) {
    srand(time(NULL));
    for (int i = 0; i < numVertices; i++) {
        int numArestas = rand() % 2 + 1; // 1 ou 2 arestas por vertice
        for (int j = 0; j < numArestas; j++) {
            int destino, peso;
            do {
                destino = rand() % numVertices;
            } while (destino == i); // nao permite laco

            // Evita aresta duplicada
            Aresta* temp = lista[i].inicio;
            int duplicada = 0;
            while (temp) {
                if (temp->destino == destino) {
                    duplicada = 1;
                    break;
                }
                temp = temp->prox;
            }
            if (duplicada) continue;

            peso = rand() % 10 + 1;
            adicionarArestaLista(lista, i, destino, peso);
        }
    }
}

void exibirListaAdj(ListaAdj* lista, int numVertices) {
    printf("Lista de adjacencia do grafo:\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%d:", i);
        Aresta* temp = lista[i].inicio;
        while (temp) {
            printf(" -> %d(peso=%d)", temp->destino, temp->peso);
            temp = temp->prox;
        }
        printf("\n");
    }
}

void dijkstraLista(int numVertices, ListaAdj* lista, int* distancia, int* visitado, int* anterior) {
    for (int i = 0; i < numVertices; i++) {
        int minDist = INT_MAX, u = -1;
        for (int j = 0; j < numVertices; j++) {
            if (!visitado[j] && distancia[j] < minDist) {
                minDist = distancia[j];
                u = j;
            }
        }
        if (u == -1) break;
        visitado[u] = 1;

        // Percorre os vizinhos de u
        for (Aresta* temp = lista[u].inicio; temp != NULL; temp = temp->prox) {
            int v = temp->destino;
            int peso = temp->peso;
            if (!visitado[v] && distancia[u] != INT_MAX && distancia[u] + peso < distancia[v]) {
                distancia[v] = distancia[u] + peso;
                anterior[v] = u;
            }
        }
    }
}

void calcularMenorDistanciaLista(ListaAdj* lista, int numVertices) {
    int origem, destino;
    printf("Digite o vertice de origem: ");
    scanf("%d", &origem);
    printf("Digite o vertice de destino: ");
    scanf("%d", &destino);

    if (origem < 0 || origem >= numVertices || destino < 0 || destino >= numVertices) {
        printf("Vertices invalidos!\n");
        return;
    }

    int distancia[NUM_VERTICES], visitado[NUM_VERTICES], anterior[NUM_VERTICES];
    for (int i = 0; i < numVertices; i++) {
        distancia[i] = INT_MAX;
        visitado[i] = 0;
        anterior[i] = -1;
    }
    distancia[origem] = 0;

    dijkstraLista(numVertices, lista, distancia, visitado, anterior);
    exibeMenorDistanciaLista(origem, destino, distancia, anterior);
    exibePesoLista(lista, destino, anterior);
}

void exibeMenorDistanciaLista(int origem, int destino, const int* distancia, const int* anterior) {
    printf("Menor distancia de %d para %d: peso %d\n", origem, destino, distancia[destino]);
    printf("Caminho: ");
    int temp = destino;
    while (temp != -1) {
        printf("%d ", temp);
        temp = anterior[temp];
    }
    printf("\n");
}

void exibePesoLista(ListaAdj* lista, int destino, const int* anterior) {
    int temp = destino;
    int totalPeso = 0;
    printf("Pesos das arestas no caminho:\n");
    while (anterior[temp] != -1) {
        // Encontra a aresta de anterior[temp] ate temp
        Aresta* curr = lista[anterior[temp]].inicio;
        while (curr) {
            if (curr->destino == temp) {
                printf("Peso entre %d e %d: %d\n", anterior[temp], temp, curr->peso);
                totalPeso += curr->peso;
                break;
            }
            curr = curr->prox;
        }
        temp = anterior[temp];
    }
    printf("Peso total do caminho: %d\n", totalPeso);
}

void executarDijkstraLista(void) {
    ListaAdj lista[NUM_VERTICES];
    inicializarListaAdj(lista, NUM_VERTICES);
    int escolha;

    while (1) {
        printf("\nMenu Dijkstra Lista de Adjacencia:\n");
        printf("1. Criar Grafo Aleatorio\n");
        printf("2. Exibir Lista de Adjacencia\n");
        printf("3. Calcular Menor Distancia\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                inicializarListaAdj(lista, NUM_VERTICES);
                criarArestasAleatoriasLista(lista, NUM_VERTICES);
                printf("Grafo criado com sucesso!\n");
                break;
            case 2:
                exibirListaAdj(lista, NUM_VERTICES);
                break;
            case 3:
                calcularMenorDistanciaLista(lista, NUM_VERTICES);
                break;
            case 0:
                printf("Saindo...\n");
                return;
            default:
                printf("Opcao invalida!\n");
        }
    }
}
