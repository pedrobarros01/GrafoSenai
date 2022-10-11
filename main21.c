#include<stdio.h>
#include "ListaGrafos.h"

int main(){
    GrafoLista *gf = criarGrafo(6, false, false);
	inserirAresta(gf, 0, 1, 0, false);
	inserirAresta(gf, 0, 2, 0, false);
	inserirAresta(gf, 2, 3, 0, false);
	inserirAresta(gf, 4, 5, 0, false);
	imprimeLista(gf);
	/* VerticeBuscaProfundida *vetor;
	vetor = ordenacaoTopologica(gf);
	int i;
	for(i = 0; i < gf->quantVertices; i++){
		printf("=====VERTICE %d=====\n", vetor[i].dado);
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