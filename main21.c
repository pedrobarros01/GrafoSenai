#include<stdio.h>
#include "ListaGrafos.h"

int main(){
    GrafoLista *gf = criarGrafo(5, true, true);
    VerticeDjikstra *vetor;
	inserirAresta(gf, 0, 1, 2, true);
	inserirAresta(gf, 0, 2, 3, true);
	inserirAresta(gf, 1, 2, 4, true);
	inserirAresta(gf, 1, 3, 3, true);
	inserirAresta(gf, 2, 1, 6, true);
	inserirAresta(gf, 2, 4, 3, true);
	inserirAresta(gf, 3, 4, 5, true);
	imprimeLista(gf);
	vetor = djikstra(gf, 0);
	/* VerticeBuscaProfundida *vetor;
	vetor = ordenacaoTopologica(gf);
	int i;
	for(i = 0; i < gf->quantVertices; i++){
		printf("=====VERTICE %d=====\n", vetor[i].dado);
	} */
    int i;
	for(i = 0; i < gf->quantVertices; i++){
		printf("=====VERTICE %d=====\n", i);
		printf("distancia: %d\n", vetor[i].d);
		printf("pai: %d\n", vetor[i].p);
	}
    return 0;
}

/*
printf("=====VERTICE %d=====\n", i);
		printf("visitado: %d\n", vetor[i].visitado);
		printf("tempoD: %d\n", vetor[i].tempoD);
		printf("tempoF: %d\n", vetor[i].tempoF);
		printf("predecessor: %d\n", vetor[i].p);
*/