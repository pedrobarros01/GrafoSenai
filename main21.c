#include<stdio.h>
#include "ListaGrafos.h"

int main(){
    GrafoLista *gf = criarGrafoPorArquivo("arquivo.txt");
	imprimeLista(gf);
	 GrafoLista* grafoPrim = prim(gf, 0);
	GrafoLista* grafoKruskal = kruskal(gf);
	printf("====PRIM=====\n");
	imprimeLista(grafoPrim);
	printf("====Kruskal=====\n");
	imprimeLista(grafoKruskal);	
	return 0;
}

/* GrafoLista *gf = criarGrafo(5, false, true);
	/* 
	A: 0
	B: 1
	C: 2
	D: 3
	E: 4
	inserirAresta(gf, 0, 1, 5, false);
	inserirAresta(gf, 0, 2, 6, false);
	inserirAresta(gf, 0, 3, 9, false);
	inserirAresta(gf, 0, 4, 10, false);
	inserirAresta(gf, 1, 3, 3, false);
	inserirAresta(gf, 2, 4, 1, false);
	inserirAresta(gf, 2, 3, 8, false);
	inserirAresta(gf, 3, 4, 2, false);
	imprimeLista(gf);
	GrafoLista *grafoKruskal = kruskal(gf);
	printf("=============\n");
	imprimeLista(grafoKruskal); */


/* 
	
	int ordeem = ordemGrafo(gf);
	int tam = tamanhoGrafo(gf);
	int maxArco = maximoArestas(gf);
	double densi = densidade(gf);
	
	Grau grauAux = grau(gf);
	printf("ordem: %d\n", ordeem);
	printf("tamanho: %d\n", tam);
	printf("densidade: %lf\n", densi);
	printf("maxArco: %d\n", maxArco);
	int i;
	printf("\nLISTA GRAU\n\n");
	for(i=0; i < gf->quantVertices; i++){
		printf("Vertice %d\n", i+1);
		printf("grau: %d\n", grauAux.grauGrafo[i]);
		printf("\n");
	} */
/* GrafoLista *gf = criarGrafo(5, false, true);
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
/*
printf("=====VERTICE %d=====\n", i);
		printf("visitado: %d\n", vetor[i].visitado);
		printf("tempoD: %d\n", vetor[i].tempoD);
		printf("tempoF: %d\n", vetor[i].tempoF);
		printf("predecessor: %d\n", vetor[i].p);
*/