#include<stdio.h>
#include<stdlib.h>
typedef struct GrafoIncidencia {
	int **matriz;
} GrafoIncidencia;


GrafoIncidencia* criaGrafo(int vertice, int aresta){
	GrafoIncidencia *gf = (GrafoIncidencia*)malloc(sizeof(GrafoIncidencia));
	if(gf==NULL){
		return NULL;
	}
	gf->matriz = (int**)malloc(vertice * sizeof(int*));
	int i;
	for(i=0; i<vertice; i++){
		gf->matriz[i] = (int*)malloc(aresta * sizeof(int));
	}
	return gf;
}

int main(){
	GrafoIncidencia *gf;
	int vertice, aresta;
	printf("Quant de vertices: ");
	scanf("%d", &vertice);
	printf("Quant de arestas: ");
	scanf("%d", &aresta);
	gf = criaGrafo(vertice, aresta);
	int i, j;
	for(i=0; i<vertice; i++){
		printf("------ Vertice %c ------\n", i+97);
		for(j=0; j<aresta;j++){
			printf("Liga %c com %d (1/0/-1): ", i+97, j+1);
			scanf("%d", &gf->matriz[i][j]);
			printf("\n");
		}
		printf("\n");
		
	}
	
	for(i=0; i<vertice; i++){
		for(j=0; j<aresta;j++){
			printf("%d ",gf->matriz[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
