#include<stdio.h>
#include "ListaGrafos.h"

int main(){
    GrafoLista *gf = criarGrafo(7, true, false);
    PILHA *saida;
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
	imprimeLista(gf);
	saida = ordenacaoTopologicaKahn(gf);
	imprime_pilha(saida);
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