#include<stdio.h>
#include "ListaGrafos.h"

int main(){
    GrafoLista *gf = criarGrafo(5, false, true);
    //VerticeDjikstra *vetor;
	inserirAresta(gf, 0, 1, 3, false);
	inserirAresta(gf, 0, 2, 5, false);
	inserirAresta(gf, 0, 3, 8, false);
	inserirAresta(gf, 0, 4, 9, false);
	inserirAresta(gf, 1, 3, 2, false);
	inserirAresta(gf, 2, 4, 2, false);
	inserirAresta(gf, 2, 3, 8, false);
	inserirAresta(gf, 3, 4, 1, false);
	//imprimeLista(gf);
	GrafoLista* grafoPrim = prim(gf, 0);
	imprimeLista(grafoPrim);

	//vetor = djikstra(gf, 0);
	/* VerticeBuscaProfundida *vetor;
	vetor = ordenacaoTopologica(gf);
	int i;
	for(i = 0; i < gf->quantVertices; i++){
		printf("=====VERTICE %d=====\n", vetor[i].dado);
	} */
    /* int i;
	for(i = 0; i < gf->quantVertices; i++){
		printf("=====VERTICE %d=====\n", i);
		printf("distancia: %d\n", vetor[i].d);
		printf("pai: %d\n", vetor[i].p);
	} */
    return 0;
}

/*
printf("=====VERTICE %d=====\n", i);
		printf("visitado: %d\n", vetor[i].visitado);
		printf("tempoD: %d\n", vetor[i].tempoD);
		printf("tempoF: %d\n", vetor[i].tempoF);
		printf("predecessor: %d\n", vetor[i].p);
*/