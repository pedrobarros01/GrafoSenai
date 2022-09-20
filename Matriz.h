#ifndef MATRIZ_H
#define MATRIZ_H
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>

typedef int Vertice;
typedef struct GrafoMatriz {
    int numAresta;
    int numVertice;
    Vertice **matriz;
} GrafoMatriz;

GrafoMatriz* criaMatrizAdjCusto(int vertice){
    GrafoMatriz *gf = (GrafoMatriz*)malloc(sizeof(GrafoMatriz));
    gf->numAresta = 0;
    gf->numVertice = vertice;
    gf->matriz = (Vertice**)malloc(gf->numVertice * sizeof(Vertice*));
    int i, j;
    for(i = 0; i < gf->numVertice; i++){
        gf->matriz[i] = (Vertice*)malloc(gf->numVertice * sizeof(Vertice));
    }
    return gf;
}
GrafoMatriz* criaMatrizIncidencia(int vertice, int aresta){
    GrafoMatriz *gf = (GrafoMatriz*)malloc(sizeof(GrafoMatriz));
    gf->numAresta = aresta;
    gf->numVertice = vertice;
    gf->matriz = (Vertice**)malloc(gf->numVertice * sizeof(Vertice*));
    int i, j;
    for(i = 0; i < gf->numVertice; i++){
        gf->matriz[i] = (Vertice*)malloc(gf->numAresta * sizeof(Vertice));
    }
    return gf;
}

bool insereAresta(GrafoMatriz *gf,Vertice origem, Vertice destino, int valor, bool ehDigrafo){
    gf->matriz[origem][destino] = valor;
    if(!ehDigrafo){
        insereAresta(gf, destino, origem, valor, true);
    }
    return true;
}
void imprimeGrafo(GrafoMatriz *gf){
    int i, j;
    for(i = 0; i < gf->numVertice; i++){
        for(j = 0; j < gf->numVertice; j++){
            printf("%d ", gf->matriz[i][j]);
        }
        printf("\n");
    }
}
int caminhoCritico(GrafoMatriz *gf, int verticeAtual, int* vetorResposta, int ind){
	if(verticeAtual + 1 == 9){
		vetorResposta[6] = 9;
		return 0;
		
	}
	int maior = 0, j, verticeDestino;
	for(j=0; j<9; j++){
		printf("verticeAtual: %d\n", (verticeAtual + 1));
		if(gf->matriz[verticeAtual][j] > maior){
			maior = gf->matriz[verticeAtual][j];
            verticeDestino = j;
			printf("indice resposta: %d\n", ind);
			
			
		}
	}
    vetorResposta[ind] = verticeAtual + 1;
    ind++;
    caminhoCritico(gf, verticeDestino, vetorResposta, ind);
	return 1;
}
#endif