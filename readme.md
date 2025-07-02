# Estrutura de Dados em C - Algoritmos de Busca e Caminhos Mínimos

**Autor:** Prof. Edson Orivaldo Lessa Junior

## Visão Geral

Este projeto educacional apresenta uma implementação abrangente de dois algoritmos fundamentais em ciência da computação: Busca em Largura (BFS - Breadth-First Search) e o algoritmo de Dijkstra para encontrar caminhos mínimos em grafos. O projeto foi desenvolvido como material didático para o curso de Estrutura de Dados, demonstrando conceitos avançados de grafos e algoritmos de busca através de implementações práticas e bem documentadas.

O repositório está organizado de forma modular, permitindo que estudantes compreendam cada algoritmo individualmente e também vejam como eles podem ser integrados em um sistema maior. A temática de cavernas é mantida consistentemente ao longo do projeto, proporcionando um contexto prático e intuitivo para o aprendizado dos conceitos abstratos de grafos e algoritmos.

## Estrutura do Projeto

O projeto segue uma arquitetura modular bem definida, organizando os diferentes algoritmos em diretórios separados para facilitar a compreensão e manutenção:

```
unicesumar-aula10-estrutura-de-dados/
├── 01_busca_largura/
│   ├── bfs.h                    # Interface do módulo BFS
│   └── bfs.c                    # Implementação do algoritmo BFS
├── 02_dijkstra/
│   ├── dijkstra.h               # Interface do módulo Dijkstra
│   └── dijkstra.c               # Implementação do algoritmo Dijkstra
├── main.c                       # Programa principal com menu interativo
├── CMakeLists.txt               # Configuração de compilação
├── .gitignore                   # Arquivos ignorados pelo Git
└── readme.md                    # Documentação do projeto
```

Esta organização modular permite que cada algoritmo seja estudado independentemente, facilitando o processo de aprendizagem e permitindo futuras extensões do projeto.

## Módulo 1: Busca em Largura (BFS)

### Conceitos Fundamentais

A Busca em Largura é um algoritmo fundamental para exploração de grafos que visita todos os vértices alcançáveis a partir de um vértice inicial, explorando primeiro todos os vizinhos diretos antes de avançar para os vizinhos dos vizinhos. Este algoritmo é particularmente útil para encontrar o caminho mais curto em grafos não ponderados e para explorar sistematicamente todas as possibilidades em um espaço de busca.

### Implementação Técnica

O módulo BFS está implementado nos arquivos `01_busca_largura/bfs.h` e `01_busca_largura/bfs.c`, seguindo as melhores práticas de programação modular em C.

#### Interface do Módulo (bfs.h)

```c
#ifndef BFS_H
#define BFS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_VERTICES 20

void inicializarMatrizBFS(int matriz[NUM_VERTICES][NUM_VERTICES], int numVertices);
void adicionarArestasAleatoriasBFS(int matriz[NUM_VERTICES][NUM_VERTICES], int numVertices);
void bfs(int matriz[NUM_VERTICES][NUM_VERTICES], int inicio);
void executarBFS();

#endif
```

A interface define claramente as funções disponíveis no módulo, mantendo a encapsulação e facilitando o uso por outros módulos do sistema.

#### Características da Implementação

O algoritmo BFS implementado possui as seguintes características técnicas:

**Estrutura de Dados:** Utiliza uma fila implementada através de um array com variáveis de controle `front` e `rear` para gerenciar a ordem FIFO (First In, First Out) necessária para o algoritmo BFS.

**Representação do Grafo:** O grafo é representado através de uma matriz de adjacência de tamanho 20x20, onde cada posição `matriz[i][j]` indica se existe uma aresta entre os vértices `i` e `j`.

**Geração Aleatória:** O sistema inclui funcionalidade para gerar grafos aleatórios, criando arestas com 50% de probabilidade entre cada par de vértices, proporcionando cenários variados para teste e demonstração.

**Controle de Visitação:** Utiliza um array booleano para marcar vértices já visitados, evitando ciclos infinitos e garantindo que cada vértice seja processado exatamente uma vez.

### Algoritmo Principal

```c
void bfs(int matriz[NUM_VERTICES][NUM_VERTICES], int inicio) {
    int visitado[NUM_VERTICES] = {0};
    int fila[NUM_VERTICES], front = 0, rear = 0;
    
    visitado[inicio] = 1;
    fila[rear++] = inicio;
    
    while (front < rear) {
        int vertice = fila[front++];
        printf("Visitando vertice %d\n", vertice);
        
        for (int i = 0; i < NUM_VERTICES; i++) {
            if (matriz[vertice][i] == 1 && !visitado[i]) {
                fila[rear++] = i;
                visitado[i] = 1;
            }
        }
    }
}
```

### Aplicações Práticas

O algoritmo BFS tem diversas aplicações práticas importantes:

**Navegação em Redes:** Encontrar o menor número de saltos entre dois pontos em uma rede de computadores ou redes sociais.

**Jogos e Puzzles:** Resolver labirintos, encontrar soluções ótimas em jogos de tabuleiro, ou explorar árvores de possibilidades em jogos.

**Análise de Grafos:** Determinar componentes conectados, verificar se um grafo é bipartido, ou calcular a distância entre vértices.

**Sistemas de Recomendação:** Explorar conexões em grafos de relacionamento para sugerir amigos ou conteúdo relevante.

## Módulo 2: Algoritmo de Dijkstra

### Conceitos Fundamentais

O algoritmo de Dijkstra é um dos algoritmos mais importantes para encontrar caminhos mínimos em grafos ponderados com pesos não negativos. Desenvolvido por Edsger Dijkstra em 1956, este algoritmo resolve o problema do caminho mais curto de uma única origem, encontrando o caminho de menor custo de um vértice inicial para todos os outros vértices do grafo.

### Implementação Técnica

O módulo Dijkstra está implementado nos arquivos `02_dijkstra/dijkstra.h` e `02_dijkstra/dijkstra.c`, seguindo uma abordagem educacional que prioriza a clareza e compreensão dos conceitos.

#### Interface do Módulo (dijkstra.h)

```c
#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define NUM_CAVERNAS 20

void inicializarSistemaCavernas(int cavernas[NUM_CAVERNAS][NUM_CAVERNAS], int numCavernas);
void adicionarPassagem(int cavernas[NUM_CAVERNAS][NUM_CAVERNAS], int origem, int destino, int peso);
void criarPassagensAleatorias(int cavernas[NUM_CAVERNAS][NUM_CAVERNAS], int numCavernas);
void exibirCavernasEArestas(int cavernas[NUM_CAVERNAS][NUM_CAVERNAS], int numCavernas);
void calcularMenorDistancia(int cavernas[NUM_CAVERNAS][NUM_CAVERNAS], int numCavernas);
void executarDijkstra();
void dijkstra(int numCavernas, int cavernas[NUM_CAVERNAS][NUM_CAVERNAS], int origem, int destino);
void exibeMenorDistancia(int origem, int destino, const int *distancia, const int *anterior);
void exibePeso(int cavernas[NUM_CAVERNAS][NUM_CAVERNAS], int destino, const int *anterior);
void origemDestino(int *origem, int *destino);

#endif
```

### Características da Implementação

**Representação com Pesos:** Diferentemente do BFS, o algoritmo de Dijkstra trabalha com grafos ponderados, onde cada aresta possui um peso que representa o custo de atravessá-la.

**Estruturas de Dados Auxiliares:** Utiliza três arrays principais:
- `distancia[]`: Armazena a menor distância conhecida da origem até cada vértice
- `visitado[]`: Marca quais vértices já foram processados definitivamente
- `anterior[]`: Permite reconstruir o caminho ótimo encontrado

**Geração de Pesos Aleatórios:** O sistema gera automaticamente pesos aleatórios entre 1 e 10 para as arestas, simulando diferentes custos de travessia entre cavernas.

**Interface Interativa:** Inclui um menu completo que permite ao usuário criar sistemas de cavernas, visualizar conexões e calcular caminhos mínimos entre pontos específicos.

### Algoritmo Principal

O núcleo do algoritmo de Dijkstra implementado segue a abordagem clássica:

```c
void dijkstra(int numCavernas, int cavernas[NUM_CAVERNAS][NUM_CAVERNAS], int origem, int destino) {
    int distancia[NUM_CAVERNAS];
    int visitado[NUM_CAVERNAS];
    int anterior[NUM_CAVERNAS];
    
    // Inicialização
    for (int i = 0; i < numCavernas; i++) {
        distancia[i] = INT_MAX;
        visitado[i] = 0;
    }
    distancia[origem] = 0;
    
    // Algoritmo principal
    for (int i = 0; i < numCavernas; i++) {
        int minDistancia = INT_MAX, minIndex;
        
        // Encontra o vértice não visitado com menor distância
        for (int j = 0; j < numCavernas; j++) {
            if (!visitado[j] && distancia[j] < minDistancia) {
                minDistancia = distancia[j];
                minIndex = j;
            }
        }
        
        int u = minIndex;
        visitado[u] = 1;
        
        // Atualiza distâncias dos vizinhos
        for (int v = 0; v < numCavernas; v++) {
            if (!visitado[v] && cavernas[u][v] && distancia[u] != INT_MAX && 
                distancia[u] + cavernas[u][v] < distancia[v]) {
                distancia[v] = distancia[u] + cavernas[u][v];
                anterior[v] = u;
            }
        }
    }
}
```

### Funcionalidades Avançadas

**Reconstrução de Caminhos:** O algoritmo não apenas calcula a distância mínima, mas também permite reconstruir o caminho completo através do array `anterior[]`.

**Visualização de Resultados:** Inclui funções dedicadas para exibir tanto a distância total quanto o caminho detalhado com os pesos de cada segmento.

**Validação de Entrada:** Implementa verificações para garantir que as cavernas de origem e destino sejam válidas antes de executar o algoritmo.

### Aplicações Práticas

**Sistemas de Navegação:** GPS e aplicativos de mapas utilizam variações do algoritmo de Dijkstra para encontrar rotas mais rápidas ou econômicas.

**Redes de Computadores:** Protocolos de roteamento como OSPF utilizam conceitos similares para encontrar caminhos ótimos entre roteadores.

**Jogos e Simulações:** Implementação de IA para movimentação de personagens, encontrando caminhos ótimos considerando diferentes terrenos e obstáculos.

**Logística e Transporte:** Otimização de rotas de entrega, planejamento de transporte público e gestão de cadeias de suprimento.

## Programa Principal

### Arquitetura de Integração

O arquivo `main.c` serve como ponto de entrada do sistema, integrando os dois módulos através de uma interface de menu simples e intuitiva. Esta abordagem permite que usuários explorem ambos os algoritmos de forma independente ou comparativa.

```c
#include <stdio.h>
#include "01_busca_largura/bfs.h"
#include "02_dijkstra/dijkstra.h"

void menu() {
    int escolha;
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Exemplo BFS\n");
        printf("2. Exemplo Dijkstra\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha);
        
        switch (escolha) {
            case 1:
                executarBFS();
                break;
            case 2:
                executarDijkstra();
                break;
            case 0:
                printf("Saindo...\n");
                return;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }
}

int main() {
    menu();
    return 0;
}
```

### Design de Interface

A interface foi projetada para ser educacional e acessível, permitindo que estudantes experimentem com diferentes cenários sem necessidade de modificar o código fonte. Cada módulo possui seu próprio submenu com opções específicas para demonstrar suas funcionalidades.

## Configuração de Compilação

### CMake Moderno

O projeto utiliza CMake como sistema de build, proporcionando portabilidade e facilidade de compilação em diferentes plataformas:

```cmake
cmake_minimum_required(VERSION 3.28)
project(unicesumar_aula10_estrutura_dados1 C)

set(CMAKE_C_STANDARD 11)

add_executable(unicesumar_aula10_estrutura_dados1 main.c
        01_busca_largura/bfs.c
        01_busca_largura/bfs.h
        01_busca_largura/bfs.h
        03_dijkstra/dijkstra.c
        03_dijkstra/dijkstra.h
        03_dijkstra/dijkstra.h)
```

### Instruções de Compilação

Para compilar e executar o projeto:

```bash
# Criar diretório de build
mkdir build
cd build

# Configurar o projeto
cmake ..

# Compilar
make

# Executar
./unicesumar_aula10_estrutura_dados1
```

## Conceitos Educacionais Abordados

### Teoria de Grafos

O projeto proporciona uma introdução prática aos conceitos fundamentais de teoria de grafos, incluindo representação por matriz de adjacência, travessia de grafos e algoritmos de caminho mínimo.

### Estruturas de Dados

Demonstra o uso prático de estruturas de dados fundamentais como arrays, filas e técnicas de indexação para implementar algoritmos complexos de forma eficiente.

### Análise de Algoritmos

Permite que estudantes comparem diferentes abordagens algorítmicas, observando as diferenças entre busca não informada (BFS) e algoritmos de otimização (Dijkstra).

### Programação Modular

Exemplifica boas práticas de programação em C, incluindo separação de responsabilidades, encapsulamento através de headers e organização de código em módulos reutilizáveis.

## Comparação entre Algoritmos

### BFS vs Dijkstra

| Aspecto | BFS | Dijkstra |
|---------|-----|----------|
| **Tipo de Grafo** | Não ponderado | Ponderado (pesos ≥ 0) |
| **Objetivo** | Exploração sistemática | Caminho mínimo |
| **Complexidade Temporal** | O(V + E) | O(V²) na implementação atual |
| **Estrutura Auxiliar** | Fila simples | Arrays de distância e visitados |
| **Garantia** | Visita todos os alcançáveis | Encontra caminho ótimo |
| **Aplicação Principal** | Exploração, conectividade | Otimização de rotas |

### Cenários de Uso

**Use BFS quando:**
- Precisar explorar todas as possibilidades
- O grafo não possui pesos nas arestas
- Buscar o menor número de passos (não necessariamente o menor custo)
- Verificar conectividade entre componentes

**Use Dijkstra quando:**
- Precisar do caminho de menor custo
- O grafo possui pesos não negativos
- Otimização de recursos for prioritária
- Necessitar do caminho específico, não apenas da distância

## Extensões Possíveis

### Melhorias de Performance

**Heap Binário:** Implementar uma fila de prioridade com heap para reduzir a complexidade do Dijkstra de O(V²) para O((V + E) log V).

**Dijkstra Bidirecional:** Implementar busca simultânea da origem e destino para reduzir o espaço de busca.

**A* (A-estrela):** Adicionar heurísticas para guiar a busca em direção ao objetivo.

### Funcionalidades Adicionais

**Visualização Gráfica:** Implementar interface gráfica para visualizar os grafos e a execução dos algoritmos em tempo real.

**Algoritmos Adicionais:** Incluir outros algoritmos como Floyd-Warshall para todos os pares de caminhos mínimos, ou algoritmos de árvore geradora mínima como Kruskal e Prim.

**Persistência de Dados:** Adicionar capacidade de salvar e carregar grafos de arquivos para permitir experimentos com dados reais.

**Métricas de Performance:** Implementar medição de tempo de execução e uso de memória para análise comparativa.

### Aplicações Avançadas

**Simulação de Redes:** Expandir para simular protocolos de roteamento em redes de computadores.

**Jogos Educacionais:** Desenvolver jogos interativos que utilizem os algoritmos para ensinar conceitos de forma lúdica.

**Análise de Redes Sociais:** Adaptar os algoritmos para analisar grafos de relacionamentos e identificar comunidades.

## Considerações de Performance

### Complexidade Temporal

**BFS:** O(V + E) onde V é o número de vértices e E o número de arestas. Esta complexidade é ótima para exploração completa de grafos.

**Dijkstra:** O(V²) na implementação atual usando busca linear. Pode ser otimizado para O((V + E) log V) com heap binário.

### Complexidade Espacial

Ambos os algoritmos utilizam O(V) de espaço adicional para arrays de controle, além do espaço O(V²) necessário para a matriz de adjacência.

### Otimizações Implementadas

**Inicialização Eficiente:** Uso de loops otimizados para inicialização de estruturas de dados.

**Verificações de Validade:** Validação de entrada para evitar processamento desnecessário.

**Modularidade:** Separação clara de responsabilidades para facilitar otimizações futuras.

## Conclusão

Este projeto representa uma implementação educacional abrangente de dois algoritmos fundamentais em ciência da computação. A combinação de BFS e Dijkstra em um único sistema permite que estudantes compreendam tanto algoritmos de exploração quanto de otimização, proporcionando uma base sólida para estudos avançados em algoritmos e estruturas de dados.

A arquitetura modular facilita a compreensão individual de cada conceito, enquanto a integração através do programa principal demonstra como diferentes algoritmos podem ser combinados em sistemas maiores. As extensões sugeridas oferecem caminhos claros para aprofundamento e aplicação prática dos conceitos aprendidos.

O projeto serve não apenas como ferramenta de aprendizagem, mas também como base para desenvolvimento de aplicações mais complexas que requeiram algoritmos de grafos eficientes e bem implementados.

