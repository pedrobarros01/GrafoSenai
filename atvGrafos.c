#include <stdio.h>
# define tam 4
typedef struct Vertice {
    int tamanho; // objeto do vertice
} Vertice;

typedef struct Aresta {
    Vertice v1; //vertice 1
    Vertice v2; // vertice 2
} Aresta;

typedef struct Grafo {
    Vertice vertices[tam]; // Conjunto de Vertice
    Aresta arestas[tam]; // Conjunto de Arestas
} Grafo;

typedef struct MatrizAd {
    int matriz[tam][tam]; // Matriz de adjacencia
} MatrizAd;

typedef struct ListaAdj {
    int** edges; // ponterro de ponteiro que simboliza a lista
    int* grade; // lista de grau dos vertices, auxilia na inserção e remoção
} ListaAdj;
// modificarei ainda para uma biblio de grafos de respeito
int main(){
    Vertice v1, v2;
    v1.tamanho = 1;
    v2.tamanho = 2;
    Aresta a1;
    a1.v1 = v1;
    a1.v2 = v2;
    MatrizAd matrizAd;
    ListaAdj listaAdj;
    printf("ola mundo\n");
    return 0;
}