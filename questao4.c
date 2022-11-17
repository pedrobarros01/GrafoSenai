#include<stdio.h>
#include "ListaGrafos.h"


int main(){
    GrafoLista *gf = criarGrafo(7, true, false);
    inserirAresta(gf, 0, 1, 0, true);
    inserirAresta(gf, 0, 2, 0, true);
    inserirAresta(gf, 0, 3, 0, true);
    inserirAresta(gf, 1, 2, 0, true);
    inserirAresta(gf, 1, 4, 0, true);
    inserirAresta(gf, 1, 5, 0, true);
    inserirAresta(gf, 2, 4, 0, true);
    inserirAresta(gf, 2, 5, 0, true);
    inserirAresta(gf, 3, 4, 0, true);
    inserirAresta(gf, 6, 5, 0, true);
    PILHA *pi = ordenacaoTopologicaKahn(gf);
    imprime_pilha(pi); 
    return 0;
}