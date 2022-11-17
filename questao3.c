#include<stdio.h>
#include "ListaGrafos.h"

int main(){
    GrafoLista *gf = criarGrafo(5, false, true);
    inserirAresta(gf, 0, 1, 2, false);
	inserirAresta(gf, 0, 3, 3, false);
	inserirAresta(gf, 1, 3, 4, false);
	inserirAresta(gf, 1, 2, 3, false);
	inserirAresta(gf, 2, 4, 5, false);
	inserirAresta(gf, 3, 1, 6, false);
	inserirAresta(gf, 3, 4, 3, false);	
    VerticeDjikstra *vetor;
    vetor = djikstra(gf, 0);
    int i;
	for(i = 0; i < gf->quantVertices; i++){
		printf("=====VERTICE %d=====\n", i);
		printf("distancia: %d\n", vetor[i].d);
		printf("pai: %d\n", vetor[i].p);
	}
    return 0;
}