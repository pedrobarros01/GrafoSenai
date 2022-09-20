#ifndef LISTAGRAFOS_H
#define LISTAGRAFOS_H
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include "fila.h"



typedef int Vertice;
typedef double Peso;
typedef struct NO_ADJ {
    Vertice vertice;
    Peso peso;
    struct NO_ADJ *prox;
} NO_ADJ;
typedef NO_ADJ** listaAdj;
typedef struct GrafoLista {
    int quantVertices;
    bool eh_digrafo;
    bool eh_com_peso;
    listaAdj lista;
} GrafoLista;
typedef struct VerticeBusca {
    Vertice dado;
    int distancia;
    int visitado;
    struct VerticeBusca *p;
} VerticeBusca;
GrafoLista* criarGrafo(int quantVertices, bool eh_digrafo, bool eh_com_peso){
    GrafoLista *gf = (GrafoLista*)malloc(sizeof(GrafoLista));
    if(gf == NULL){
        return NULL;
    }
    gf->eh_digrafo = eh_digrafo;
    gf->quantVertices = quantVertices;
    gf->eh_com_peso = eh_com_peso;
    gf->lista = (listaAdj)malloc(gf->quantVertices * sizeof(NO_ADJ*));
    int i;
    for(i=0; i < gf->quantVertices; i++){
        gf->lista[i] = NULL;
    }
    return gf;
}
bool temVertice(int vertice, GrafoLista *gf){
    if(vertice <= gf->quantVertices){
        return true;
    }
    return false;
}
bool inserirAresta(GrafoLista *gf, int origem, int destino, Peso peso, bool eh_digrafo){
    if(!temVertice(origem, gf) || !temVertice(destino, gf)){
        return false;
    }
    NO_ADJ *novo_no = (NO_ADJ*)malloc(sizeof(NO_ADJ));
    if(novo_no == NULL){
        return false;
    }
    novo_no->vertice = destino;
    novo_no->peso = -1;
    if(gf->eh_com_peso){
        novo_no->peso = peso;
    }
    //caso for grafo
    novo_no->prox = gf->lista[origem];
    gf->lista[origem] = novo_no;
    
    if(!eh_digrafo){
        inserirAresta(gf, destino, origem, peso, true);
    }
    //continuo digrafo
    return true;

}
void imprimeLista(GrafoLista *gf){
int i;
NO_ADJ *lista;
    for(i=0; i < gf->quantVertices; i++){
        printf("%d: ", i);
        lista = gf->lista[i];
        while(lista != NULL){
            printf("%d ", lista->vertice);
            lista=lista->prox;
        }
        printf("\n");
    }
}
VerticeBusca** BuscaLargura(GrafoLista *gf, Vertice raiz){
    VerticeBusca **vetor = (VerticeBusca**)malloc(gf->quantVertices* sizeof(VerticeBusca));
	FILA *filaVertice = cria_fila();
    int i;
    for(i=0; i < gf->quantVertices; i++){
        vetor[i] = (VerticeBusca*)malloc(sizeof(VerticeBusca));
    }
    for(i=0; i < gf->quantVertices; i++){
        vetor[i]->dado = i;
        vetor[i]->visitado = 0;
        vetor[i]->distancia = -1;
        vetor[i]->p = NULL;
    }
	vetor[0]->dado = raiz;
    vetor[0]->distancia = 0;
    vetor[0]->p = NULL;
    vetor[0]->visitado = 1;
	enfileira(filaVertice, raiz);
	while(!fila_vazia(filaVertice)){
		Vertice dado = desenfileira(filaVertice);
        printf("%d\n", dado);
		NO_ADJ *aux = gf->lista[dado];
		for(aux=gf->lista[dado]; aux != NULL; aux=aux->prox){
			if(!vetor[aux->vertice]->visitado){             
                vetor[aux->vertice]->p = vetor[dado];
				vetor[aux->vertice]->visitado = 1;
				vetor[aux->vertice]->distancia = vetor[dado]->distancia + 1;
                enfileira(filaVertice, aux->vertice);
			}
		}
        vetor[dado]->visitado = 2;
		//gf->lista[dado.dado].vertice.visitado = 2;
		
	}
	destroi_fila(filaVertice);
	return vetor;
}
#endif