#include<stdio.h>
#include "ListaGrafos.h"

int main(){
    int *lista;
    GrafoLista *gfLista = criarGrafo(6, true, false);
    inserirAresta(gfLista, 0, 1, 0, true);
    inserirAresta(gfLista, 0, 2, 0 ,true);
    inserirAresta(gfLista, 1, 2, 0 ,true);
    inserirAresta(gfLista, 2, 5, 0 ,true);
    inserirAresta(gfLista, 3, 4, 0 ,true);
    inserirAresta(gfLista, 4, 2, 0 ,true);
    lista = BuscaEmProfundidade(gfLista);
    int i;
    for ( i = 0; i < gfLista->quantVertices; i++)
    {
        printf("%d\n", lista[i]);
    }
    
    return 0;
}