#ifndef LISTAGRAFOS_H
#define LISTAGRAFOS_H
#define CINZA 1
#define BRANCO 0
#define PRETO 2
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include "fila.h"
#include "lista.h"
#include "pilha.h"
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
typedef struct VerticeBuscaLargura{
    Vertice dado;
    int distancia;
    int visitado;
    struct VerticeBuscaLargura *p;
} VerticeBuscaLargura;

typedef struct VerticeBuscaProfundida{
    Vertice dado;
    int visitado;
    int tempoD;
    int tempoF;
    int p;
} VerticeBuscaProfundida;
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
    novo_no->prox = NULL;
    //caso for grafo
    if(gf->lista[origem] == NULL){
        novo_no->prox = gf->lista[origem];
        gf->lista[origem] = novo_no;
    }else{
        NO_ADJ *aux = gf->lista[origem];
        while(aux->prox !=NULL){
            aux = aux->prox;
        }
        aux->prox = novo_no;
    }
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
VerticeBuscaLargura** BuscaLargura(GrafoLista *gf, Vertice raiz){
    VerticeBuscaLargura **vetor = (VerticeBuscaLargura**)malloc(gf->quantVertices* sizeof(VerticeBuscaLargura));
	FILA *filaVertice = cria_fila();
    int i;
    for(i=0; i < gf->quantVertices; i++){
        vetor[i] = (VerticeBuscaLargura*)malloc(sizeof(VerticeBuscaLargura));
    }
    for(i=0; i < gf->quantVertices; i++){
        vetor[i]->dado = i;
        vetor[i]->visitado = BRANCO;
        vetor[i]->distancia = -1;
        vetor[i]->p = NULL;
    }
	vetor[0]->dado = raiz;
    vetor[0]->distancia = 0;
    vetor[0]->p = NULL;
    vetor[0]->visitado = CINZA;
	enfileira(filaVertice, raiz);
	while(!fila_vazia(filaVertice)){
		Vertice dado = desenfileira(filaVertice);
        printf("%d\n", dado);
		NO_ADJ *aux = gf->lista[dado];
		for(aux=gf->lista[dado]; aux != NULL; aux=aux->prox){
			if(!vetor[aux->vertice]->visitado){             
                vetor[aux->vertice]->p = vetor[dado];
				vetor[aux->vertice]->visitado = CINZA;
				vetor[aux->vertice]->distancia = vetor[dado]->distancia + 1;
                enfileira(filaVertice, aux->vertice);
			}
		}
        vetor[dado]->visitado = PRETO;
		//gf->lista[dado.dado].vertice.visitado = 2;
		
	}
	destroi_fila(filaVertice);
	return vetor;
}

int tempo;
void BuscaEmProfundidadeAux(GrafoLista *gf, Vertice atual, VerticeBuscaProfundida *vetor){
	tempo = tempo + 1;
	vetor[atual].tempoD = tempo;
    vetor[atual].visitado = CINZA;
    NO_ADJ *aux;
    for(aux = gf->lista[atual]; aux != NULL; aux=aux->prox){
        if(vetor[aux->vertice].visitado == BRANCO){
        	vetor[aux->vertice].p = aux->vertice;
            BuscaEmProfundidadeAux(gf, aux->vertice, vetor);
        }
    }
    tempo = tempo + 1;
    vetor[atual].tempoF = tempo;
    vetor[atual].visitado = PRETO;
}

void BuscaEmProfundidade(GrafoLista *gf, VerticeBuscaProfundida *vetor){
    int i;
    tempo = 0;
    for(i = 0; i < gf->quantVertices; i++){
        vetor[i].visitado = BRANCO;
        vetor[i].tempoD = vetor[i].tempoF = tempo;
        vetor[i].dado = i;
        vetor[i].p = 0;
        
    }
    for(i = 0; i < gf->quantVertices; i++){
        if(vetor[i].visitado == BRANCO){
            BuscaEmProfundidadeAux(gf, i, vetor);
        }
        
    }

    
}
void bubbleSort(VerticeBuscaProfundida *vetor, int tamanho){
    int i, j;
    for(i = 0; i < tamanho - 1; i++){
        for(j = 0; j < tamanho - i - 1; j++){
            if(vetor[j].tempoF < vetor[j + 1].tempoF){
                VerticeBuscaProfundida temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j+1] = temp;
            }
        }
    }
}

VerticeBuscaProfundida* ordenacaoTopologica(GrafoLista *gf){
    VerticeBuscaProfundida *vetor = (VerticeBuscaProfundida*)malloc(gf->quantVertices * sizeof(VerticeBuscaProfundida));
    BuscaEmProfundidade(gf, vetor);
    bubbleSort(vetor, gf->quantVertices);
    return vetor;
}
PILHA* ordenacaoTopologicaKahn(GrafoLista *gf){
	int vetorI[gf->quantVertices];
	int i;
	NO_ADJ *aux;
	for(i = 0; i<gf->quantVertices; i++){
		vetorI[i] = 0;
	}
	for(i = 0; i < gf->quantVertices; i++){
		for(aux=gf->lista[i]; aux != NULL; aux=aux->prox){
			vetorI[aux->vertice] += 1; 
		}
	}
	
	PILHA* L = criar_pilha();
	PILHA* S = criar_pilha();
	for(i = 0; i < gf->quantVertices; i++){
		if(vetorI[i] == 0){
			empilhar(S, i);
		}
	}
	while(!pilha_vazia(S)){
		int v = desempilhar(S);
		empilhar(L, v);
		for(aux=gf->lista[v]; aux != NULL; aux=aux->prox){
			vetorI[aux->vertice] -= 1;
			if(vetorI[aux->vertice] == 0){
				empilhar(S, aux->vertice);
			}
		}
	}
	return L;
	
	
}




#endif