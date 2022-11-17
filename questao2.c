#include<stdio.h>
#include "ListaGrafos.h"

int main(){
    GrafoLista *gf = criarGrafo(6, false, false);
    inserirAresta(gf, 0, 1, 0, false);
    inserirAresta(gf, 0, 2, 0, false);
    inserirAresta(gf, 2, 3, 0, false);
    inserirAresta(gf, 4, 5, 0, false);
    VerticeBuscaProfundida vetor[gf->quantVertices];
    BuscaEmProfundidade(gf, vetor);
    int i;
    for(i =0; i < gf->quantVertices; i++){
        printf("====Vertice %d====\n", vetor[i].dado +1);
        printf("TempoD: %d\n", vetor[i].tempoD);
        printf("TempoF: %d\n", vetor[i].tempoF);
        printf("p: %d\n", vetor[i].p);
        if(vetor[i].visitado == 2){
            printf("cor: PRETO\n", vetor[i].visitado);
        }
        
    }
    return 0;

}