#include "dijkstra.h"

// Inicializa o sistema de cavernas, configurando todas as passagens como inexistentes
void inicializarSistemaCavernas(int cavernas[NUM_CAVERNAS][NUM_CAVERNAS], int numCavernas) {
    for (int i = 0; i < numCavernas; i++) { // Itera sobre todas as cavernas
        for (int j = 0; j < numCavernas; j++) { // Itera sobre todas as cavernas para cada caverna
            cavernas[i][j] = 0; // Inicializa cada entrada da matriz com 0 (sem passagem)
        }
    }
}

// Adiciona uma passagem entre duas cavernas, com um peso especificado
void adicionarPassagem(int cavernas[NUM_CAVERNAS][NUM_CAVERNAS], int origem, int destino, int peso) {
    cavernas[origem][destino] = peso; // Define o peso da passagem entre origem e destino
    cavernas[destino][origem] = peso; // Define o peso da passagem oposta
}

// Cria passagens aleatorias entre as cavernas, garantindo entre 1 e 2 passagens por caverna
void criarPassagensAleatorias(int cavernas[NUM_CAVERNAS][NUM_CAVERNAS], int numCavernas) {
    srand(time(NULL)); // Inicializa o gerador de numeros aleatorios
    for (int i = 0; i < numCavernas; i++) { // Itera sobre todas as cavernas
        int numPassagens = rand() % 2 + 1; // Cada caverna tera entre 1 e 2 passagens
        for (int p = 0; p < numPassagens; p++) { // Cria as passagens aleatorias
            int destino, peso;
            do {
                destino = rand() % numCavernas; // Seleciona um destino aleatorio
            } while (destino == i || cavernas[i][destino] != 0); // Garante que o destino nao seja a caverna atual e nao haja passagem duplicada
            peso = rand() % 10 + 1; // Define um peso aleatorio entre 1 e 10
            adicionarPassagem(cavernas, i, destino, peso); // Adiciona a passagem
        }
    }
}

// Exibe todas as passagens entre as cavernas
void exibirCavernasEArestas(int cavernas[NUM_CAVERNAS][NUM_CAVERNAS], int numCavernas) {
    printf("Nos e arestas do sistema de cavernas:\n"); // Exibe a cabecalho
    for (int i = 0; i < numCavernas; i++) { // Itera sobre todas as cavernas
        for (int j = 0; j < numCavernas; j++) { // Itera sobre todas as cavernas para cada caverna
            if (cavernas[i][j] != 0) { // Verifica se ha uma passagem
                printf("Caverna %d -> Caverna %d com peso %d\n", i, j, cavernas[i][j]); // Exibe a passagem
            }
        }
    }
}

// Calcula a menor distancia entre duas cavernas usando o algoritmo de Dijkstra
void calcularMenorDistancia(int cavernas[NUM_CAVERNAS][NUM_CAVERNAS], int numCavernas) {
    int origem, destino;
    origemDestino(&origem, &destino);

    if (origem < 0 || origem >= numCavernas || destino < 0 || destino >= numCavernas) { // Verifica se as cavernas sao validas
        printf("Cavernas invalidas!\n"); // Exibe uma mensagem de erro se as cavernas forem invalidas
        return;
    }
    int distancia[NUM_CAVERNAS]; // Array para armazenar a menor distancia encontrada
    int visitado[NUM_CAVERNAS]; // Array para marcar cavernas visitadas
    int anterior[NUM_CAVERNAS]; // Array para armazenar o caminho

    // Inicializa os arrays
    for (int i = 0; i < numCavernas; i++) {
        distancia[i] = INT_MAX; // Inicializa as distancias com infinito
        visitado[i] = 0; // Marca todas as cavernas como nao visitadas
        anterior[i] = -1; // Inicializa o array anterior com -1
    }
    distancia[origem] = 0; // A distancia da origem para si mesma e zero

    // Algoritmo de Dijkstra
    dijkstra(numCavernas, cavernas, distancia, visitado, anterior);

    // Exibe a menor distancia e o caminho

    exibeMenorDistancia(origem, destino, distancia, anterior);

    // Exibe os pesos das arestas do caminho
    exibePeso(cavernas, destino, anterior);
}

// Solicita ao usuario as cavernas de origem e destino
void origemDestino(int *origem, int *destino) {// Solicita ao usuario as cavernas de origem e destino
    printf("Digite a caverna de origem: "); // Solicita a caverna de origem
    scanf("%d", origem); // Le a caverna de origem
    printf("Digite a caverna de destino: "); // Solicita a caverna de destino
    scanf("%d", destino); // Le a caverna de destino

}

// Exibe os pesos das arestas do caminho
void exibePeso(int cavernas[NUM_CAVERNAS][NUM_CAVERNAS], int destino, const int *anterior) {
    int temp = destino;
    int totalPeso = 0;
    printf("Pesos das arestas no caminho:\n");
    while (anterior[temp] != -1) { // Itera sobre o caminho de volta da caverna de destino para a origem
        printf("Peso entre caverna %d e caverna %d: %d\n", anterior[temp], temp, cavernas[anterior[temp]][temp]); // Exibe o peso da aresta
        totalPeso += cavernas[anterior[temp]][temp]; // Adiciona o peso ao total
        temp = anterior[temp]; // Atualiza a variavel temporaria com a caverna anterior
    }
    printf("Peso total do caminho: %d\n", totalPeso); // Exibe o peso total do caminho
}

void exibeMenorDistancia(int origem, int destino, const int *distancia, const int *anterior) {
    printf("Menor distancia da caverna %d para caverna %d: peso %d\n", origem, destino, distancia[destino]); // Exibe a menor distancia
    printf("Caminho: "); // Exibe o cabecalho do caminho
    int temp = destino; // Inicializa a variavel temporaria com a caverna de destino
    while (temp != -1) { // Itera sobre o caminho
        printf("%d ", temp); // Exibe a caverna
        temp = anterior[temp]; // Atualiza a variavel temporaria com a caverna anterior
    }
    printf("\n"); // Nova linha

}
// Algoritmo de Dijkstra
void dijkstra(int numCavernas, int cavernas[NUM_CAVERNAS][NUM_CAVERNAS], int *distancia, int *visitado, int *anterior) {
    for (int i = 0; i < numCavernas; i++) { // Itera sobre todas as cavernas
        int minDistancia = INT_MAX, minIndex; // Inicializa a menor distancia com infinito
        for (int j = 0; j < numCavernas; j++) { // Itera sobre todas as cavernas para encontrar a menor distancia
            if (!visitado[j] && distancia[j] < minDistancia) { // Verifica se a caverna nao foi visitada e se a distancia e menor
                minDistancia = distancia[j]; // Atualiza a menor distancia
                minIndex = j; // Atualiza o indice da menor distancia
            }
        }
        int u = minIndex; // Seleciona a caverna com a menor distancia
        visitado[u] = 1; // Marca a caverna como visitada
        for (int v = 0; v < numCavernas; v++) { // Itera sobre todas as cavernas para atualizar as distancias
            if (!visitado[v] && cavernas[u][v] && distancia[u] != INT_MAX && distancia[u] + cavernas[u][v] < distancia[v]) { // Verifica se ha uma passagem, se a caverna nao foi visitada, se a distancia e valida e se a nova distancia e menor
                distancia[v] = distancia[u] + cavernas[u][v]; // Atualiza a distancia
                anterior[v] = u; // Atualiza o caminho
            }
        }
    }
}

// Funcao principal que chama a funcao executarDijkstra
void executarDijkstra() {
    int cavernas[NUM_CAVERNAS][NUM_CAVERNAS]; // Declara a matriz de adjacencia
    int numCavernas = NUM_CAVERNAS; // Define o numero de cavernas no sistema
    int escolha; // Declara a variavel para armazenar a escolha do usuario

    while (1) { // Loop infinito para o menu
        // Exibe o menu de opcoes
        printf("\nSistema de Navegacao em Cavernas:\n");
        printf("1. Criar Sistema de Cavernas\n"); // Opcao para criar o sistema de cavernas
        printf("2. Exibir Nos e Arestas\n"); // Opcao para exibir os nos e arestas
        printf("3. Calcular Menor Distancia\n"); // Opcao para calcular a menor distancia
        printf("0. Sair\n"); // Opcao para sair
        printf("Escolha uma opcao: "); // Solicita ao usuario que escolha uma opcao
        scanf("%d", &escolha); // Le a escolha do usuario

        switch (escolha) { // Verifica a escolha do usuario
            case 1:
                inicializarSistemaCavernas(cavernas, numCavernas); // Inicializa a matriz de adjacencia
                criarPassagensAleatorias(cavernas, numCavernas); // Cria passagens aleatorias entre as cavernas
                printf("Sistema de cavernas criado com sucesso!\n"); // Exibe uma mensagem de sucesso
                break;
            case 2:
                exibirCavernasEArestas(cavernas, numCavernas); // Exibe todas as passagens entre as cavernas
                break;
            case 3:
                calcularMenorDistancia(cavernas, numCavernas); // Calcula a menor distancia entre duas cavernas
                break;
            case 0:
                printf("Saindo...\n"); // Exibe uma mensagem de saida
                return; // Sai do menu e termina o programa
            default:
                printf("Opcao invalida!\n"); // Exibe uma mensagem de erro se a escolha for invalida
                break;
        }
    }
}
