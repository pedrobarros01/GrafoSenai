#include<stdio.h>
#include "ListaGrafos.h"
#include "Matriz.h"

int main(){
GrafoLista *gf = criarGrafo(6, false, false);
   inserirAresta(gf, 0, 1, 0, false);
   inserirAresta(gf, 0, 2, 0, false);
   inserirAresta(gf, 2, 3, 0, false);
   inserirAresta(gf, 4, 5, 0, false);
   VerticeBusca **vetor;

   vetor = BuscaLargura(gf, 0);

   int i;
   for(i = 0; i < gf->quantVertices; i++){
    printf("==== %d ====\n", vetor[i]->dado);
    printf("Distancia: %d\n", vetor[i]->distancia);
    printf("Visitado: %d\n", vetor[i]->visitado);
    if(vetor[i]->p == NULL){
        printf("Predecessor: NULL\n");
    }else{
        printf("Predecessor: %d\n", vetor[i]->p->dado);
    }
   }
    return 0;
}