#include <stdio.h>
#include<stdbool.h>
typedef struct Vertice {
    int peso; // objeto do vertice
    int *lista;
} Vertice;

typedef struct Aresta {
    Vertice v1; //vertice 1
    Vertice v2; // vertice 2
} Aresta;


typedef struct ListaAdj {
    int** edges; // ponterro de ponteiro que simboliza a lista
    int* grade; // lista de grau dos vertices, auxilia na inser��o e remo��o
} ListaAdj;

int caminhoCritico(int matriz[9][9], int verticeAtual, int* vetorResposta, int ind){
	if(verticeAtual + 1 == 9){
		vetorResposta[6] = 9;
		return 0;
	}
	int maior = 0, j;
	for(j=0; j<9; j++){
		printf("verticeAtual: %d\n", (verticeAtual + 1));
		if(matriz[verticeAtual][j] > maior){
			maior = matriz[verticeAtual][j];
			printf("indice resposta: %d\n", ind);
			vetorResposta[ind] = verticeAtual + 1;
			caminhoCritico(matriz, j, vetorResposta, ind + 1);
		}
	}
	return 1;
}

int main(){
    int i, j, liga, tam, maior = 0;
    int matriz[9][9] = {0, 3, 0, 0, 0, 0, 0, 0, 0,
						0, 0, 7, 0, 0, 0, 0, 0, 0,
						0, 0, 0, 6, 4, 0, 5, 0, 0,
						0, 0, 0, 0, 0, 6, 0, 0, 0,
						0, 0, 0, 0, 0, 4, 0, 0, 0,
						0, 0, 0, 0, 0, 0, 0, 6, 0,
						0, 0, 0, 0, 0, 0, 0, 0, 5,
						0, 0, 0, 0, 0, 0, 0, 0, 5,
						0, 0, 0, 0, 0, 0, 0, 0, 0};
    int vetorResposta[7];
    
    /*for(i=0; i < 9; i++){
    	for(j=0;j< 9;j++){
    		printf("Qual o peso dessa vertice [%d][%d]? -> ", i, j);
    		scanf("%d", &liga);
    		matriz[i][j] = liga;
    		
    		
		}
	}*/
	caminhoCritico(matriz, 0, vetorResposta, 0);
	
	
	
	
    for(i=0; i < 7; i++){
    	printf("%d -> ", vetorResposta[i]);
	}
    
    return 0;
}
