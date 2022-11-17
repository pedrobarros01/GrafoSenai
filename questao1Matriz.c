#include<stdio.h>
#include "Matriz.h"



int main(){
    GrafoMatriz *gf;
    int vertice, aresta, resp, liga, resp2;
        printf("A matriz eh custo/Adj/Incidencia(0/1/2)\n");
        scanf("%d", &resp);
        if(resp == 0 || resp == 1){
            printf(" Me diga o numero de vertices: ");
            scanf("%d", &vertice);
            gf = criaMatrizAdjCusto(vertice);
            int i, j;
            for(i = 0; i < vertice; i++){
                for(j = 0; j < vertice; j++){
                    printf("Qual o peso dessa vertice [%d][%d]? -> ", i, j);
                    scanf("%d", &liga);
                    insereAresta(gf, i, j, liga, false);
                }
            }
        }else{
            printf(" Me diga o numero de vertices: ");
            scanf("%d", &vertice);
            printf(" Me diga o numero de arestas: ");
            scanf("%d", &aresta);
            gf = criaMatrizIncidencia(vertice, aresta);
            int i, j;
            for(i = 0; i < vertice; i++){
                printf("------ Vertice %c ------\n", i+97);
                for(j = 0; j < aresta; j++){
                    printf("Liga %c com %d (1/0/-1): ", i+97, j+1);
                    scanf("%d", &liga);
                    insereAresta(gf, i, j, liga, true);
                }
            }
        }
        imprimeGrafo(gf);
    
    
    return 0;
}