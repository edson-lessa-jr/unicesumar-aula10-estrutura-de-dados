#include <stdio.h>
#include "01_busca_largura/bfs.h"
#include "02_dijkstra/dijkstra.h"


void menu() {
    int escolha;

    while (1) { // Loop infinito para o menu
        printf("\nMenu:\n");
        printf("1. Exemplo BFS\n");
        printf("2. Exemplo Dijkstra\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &escolha); // Le a escolha do usuario

        switch (escolha) {
            case 1:
                executarBFS(); // Chama a função para executar o BFS
                break;
            case 2:
                executarDijkstra(); // Chama a função para executar o Dijkstra
                break;
            case 0:
                printf("Saindo...\n");
                return; // Sai do menu e termina o programa
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }
}

int main() {
    menu(); // Chama a função de menu para interação com o usuário
    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}
