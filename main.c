#include<stdio.h>
#include "ListaGrafos.h"
#include "Matriz.h"
int main(){
    // QUestao 4
    /*
    GrafoMatriz *gf;
    gf = criaMatrizAdjCusto(9);
    insereAresta(gf, 0, 1, 3, true);
    insereAresta(gf, 1, 2, 7, true);
    insereAresta(gf, 2, 3, 6, true);
    insereAresta(gf, 2, 4, 4, true);
    insereAresta(gf, 2, 6, 5, true);
    insereAresta(gf, 3, 5, 6, true);
    insereAresta(gf, 4, 5, 4, true);
    insereAresta(gf, 5, 7, 6, true);
    insereAresta(gf, 6, 8, 5, true);
    insereAresta(gf, 7, 8, 5, true);
    
    insereAresta(gf, 0, 0, 0, true);
    insereAresta(gf, 0, 2, 0, true);
    insereAresta(gf, 0, 3, 0, true);
    insereAresta(gf, 0, 4, 0, true);
    insereAresta(gf, 0, 5, 0, true);
    insereAresta(gf, 0, 6, 0, true);
    insereAresta(gf, 0, 7, 0, true);
    insereAresta(gf, 0, 8, 0, true);
    
    insereAresta(gf, 1, 0, 0, true);
    insereAresta(gf, 1, 1, 0, true);
    insereAresta(gf, 1, 3, 0, true);
    insereAresta(gf, 1, 4, 0, true);
    insereAresta(gf, 1, 5, 0, true);
    insereAresta(gf, 1, 6, 0, true);
    insereAresta(gf, 1, 7, 0, true);
    insereAresta(gf, 1, 8, 0, true);

    insereAresta(gf, 2, 0, 0, true);
    insereAresta(gf, 2, 1, 0, true);
    insereAresta(gf, 2, 2, 0, true);
    insereAresta(gf, 2, 5, 0, true);
    insereAresta(gf, 2, 7, 0, true);
    insereAresta(gf, 2, 8, 0, true);
    
    insereAresta(gf, 3, 0, 0, true);
    insereAresta(gf, 3, 1, 0, true);
    insereAresta(gf, 3, 2, 0, true);
    insereAresta(gf, 3, 3, 0, true);
    insereAresta(gf, 3, 4, 0, true);
    insereAresta(gf, 3, 6, 0, true);
    insereAresta(gf, 3, 7, 0, true);
    insereAresta(gf, 3, 8, 0, true);

    insereAresta(gf, 4, 0, 0, true);
    insereAresta(gf, 4, 1, 0, true);
    insereAresta(gf, 4, 2, 0, true);
    insereAresta(gf, 4, 3, 0, true);
    insereAresta(gf, 4, 4, 0, true);
    insereAresta(gf, 4, 6, 0, true);
    insereAresta(gf, 4, 7, 0, true);
    insereAresta(gf, 4, 8, 0, true);

    insereAresta(gf, 5, 0, 0, true);
    insereAresta(gf, 5, 1, 0, true);
    insereAresta(gf, 5, 2, 0, true);
    insereAresta(gf, 5, 3, 0, true);
    insereAresta(gf, 5, 4, 0, true);
    insereAresta(gf, 5, 5, 0, true);
    insereAresta(gf, 5, 6, 0, true);
    insereAresta(gf, 5, 8, 0, true);

    insereAresta(gf, 6, 0, 0, true);
    insereAresta(gf, 6, 1, 0, true);
    insereAresta(gf, 6, 2, 0, true);
    insereAresta(gf, 6, 3, 0, true);
    insereAresta(gf, 6, 4, 0, true);
    insereAresta(gf, 6, 5, 0, true);
    insereAresta(gf, 6, 6, 0, true);
    insereAresta(gf, 6, 7, 0, true);

    insereAresta(gf, 7, 0, 0, true);
    insereAresta(gf, 7, 1, 0, true);
    insereAresta(gf, 7, 2, 0, true);
    insereAresta(gf, 7, 3, 0, true);
    insereAresta(gf, 7, 4, 0, true);
    insereAresta(gf, 7, 5, 0, true);
    insereAresta(gf, 7, 6, 0, true);
    insereAresta(gf, 7, 7, 0, true);    

    insereAresta(gf, 8, 0, 0, true);
    insereAresta(gf, 8, 1, 0, true);
    insereAresta(gf, 8, 2, 0, true);
    insereAresta(gf, 8, 3, 0, true);
    insereAresta(gf, 8, 4, 0, true);
    insereAresta(gf, 8, 5, 0, true);
    insereAresta(gf, 8, 6, 0, true);
    insereAresta(gf, 8, 7, 0, true);
    insereAresta(gf, 8, 8, 0, true);
    int vetorResposta[7];
    caminhoCritico(gf, 0, vetorResposta, 0);
    int i;
    for(i = 0; i < 7; i++){
        if(i == 6)
            printf("%d", vetorResposta[i]);
        else
            printf("%d -> ", vetorResposta[i]);
    }
    printf("\n");
    */
   //Questao 2
    /*
    GrafoMatriz *gf;
    int vertice, aresta, resp, liga;
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
    */
   // Questao 2
    /*
    GrafoLista *gf = criarGrafo(3, false, false);
    inserirAresta(gf, 0, 1, 0, false);
    inserirAresta(gf, 0, 2, 0, false);
    inserirAresta(gf, 1, 2, 0, false);
    imprimeLista(gf);
    destroiLista(gf);
    */

   GrafoLista *gf = criarGrafo(6, false, false);
   inserirAresta(gf, 0, 1, 0, false);
   inserirAresta(gf, 0, 2, 0, false);
   inserirAresta(gf, 2, 3, 0, false);
   inserirAresta(gf, 4, 5, 0, false);
   VerticeBusca **vetor;

   vetor = BuscaLargura(gf, 0);

   int i;
   for(i = 0; i < gf->quantVertices; i++){
    printf("==== %d ====\n", vetor[i]->dado);
    printf("Distancia: %d\n", vetor[i]->distancia);
    printf("Visitado: %d\n", vetor[i]->visitado);
    if(vetor[i]->p == NULL){
        printf("Predecessor: NULL\n");
    }else{
        printf("Predecessor: %d\n", vetor[i]->p->dado);
    }
   }








    return 0;
}