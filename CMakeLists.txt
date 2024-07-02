cmake_minimum_required(VERSION 3.28)
project(unicesumar_aula10_estrutura_dados1 C)

set(CMAKE_C_STANDARD 11)

add_executable(unicesumar_aula10_estrutura_dados1 main.c
        01_busca_largura/bfs.c
        01_busca_largura/bfs.h
        01_busca_largura/bfs.h
        02_dijkstra/dijkstra.c
        02_dijkstra/dijkstra.h
        02_dijkstra/dijkstra.h)
