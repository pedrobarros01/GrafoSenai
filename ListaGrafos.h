#ifndef LISTAGRAFOS_H
#define LISTAGRAFOS_H
#define CINZA 1
#define BRANCO 0
#define PRETO 2
#define INFINITO INT_MAX
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include "fila.h"
#include "lista.h"
#include "pilha.h"
typedef int Vertice;
typedef int Peso;
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
typedef struct VerticeDjikstra{
    int d;
    int p;
} VerticeDjikstra;
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
Peso qualPeso(GrafoLista *gf, int origem, int destino){
    NO_ADJ *aux;
    Peso peso = 0;
    for(aux=gf->lista[origem]; aux != NULL; aux=aux->prox){
        if(aux->vertice == destino){
            peso = aux->peso;
            break;
        }
    }
    return peso;
}
bool inserirAresta(GrafoLista *gf, int origem, int destino, Peso peso, bool eh_digrafo){
    //printf("%d\n", peso);
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
            printf("%d | Peso: %d ,", lista->vertice, lista->peso);
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
void relaxamento(VerticeDjikstra *vetor, Vertice origem, Vertice destino, Peso peso){
    
}
VerticeDjikstra* djikstra(GrafoLista *gf, Vertice comeco){
    VerticeDjikstra *vetor = (VerticeDjikstra*)malloc(gf->quantVertices*sizeof(VerticeDjikstra));
    int i;
    for(i = 0; i < gf->quantVertices; i++){
        vetor[i].d = INFINITO;
        vetor[i].p = -1; // -1 aqui considera como null, nao quero usar ponteiro
    }
    vetor[comeco].d = 0;
    vetor[comeco].p = -1;
    LISTA *Q = cria_lista();
    for(i = 0; i < gf->quantVertices; i++){
        insere_listase(Q, i, vetor[i].d);
    }
    imprime_listase(Q);
    while(tamanho(Q) != 0){
        int u = buscarMenor(Q);
        for(i = 0; i < gf->quantVertices; i++){
            atualizarDistancias(Q, i, vetor[i].d);
        }
        NO_ADJ *aux;
        for(aux=gf->lista[u]; aux != NULL; aux=aux->prox){
            Peso peso = qualPeso(gf, u, aux->vertice);
            if(vetor[aux->vertice].d > vetor[u].d + peso){
                vetor[aux->vertice].d = vetor[u].d + peso;
                vetor[aux->vertice].p = u;
            }
        }
               
    }
    return vetor;
    

}
/*
Prim -> gera um grafo conexo de custo minimo

*/
// serve pra grafos com pesos negativos
// nao servem para digrafo
GrafoLista* prim(GrafoLista *gf, Vertice fonte){
    GrafoLista* grafoPrim = criarGrafo(gf->quantVertices, gf->eh_digrafo, gf->eh_com_peso);
    int* key = (int*)malloc(gf->quantVertices*sizeof(int));
    int* pai = (int*)malloc(gf->quantVertices*sizeof(int));
    int i;
    for(i=0; i < gf->quantVertices; i++){
        key[i] = INFINITO;
        pai[i] = -1;
    }
    key[fonte] = 0;
    LISTA* Q = cria_lista();
    for(i=0; i < gf->quantVertices; i++){
        insere_listase(Q, i, key[i]);
    }
    while(tamanho(Q) != 0){
        Vertice u = buscarMenor(Q);
        NO_ADJ  *aux;
        for(aux=gf->lista[u]; aux != NULL; aux=aux->prox){
            int v = aux->vertice;
            if(pertence(Q, aux->vertice) && (qualPeso(gf, u, v) < key[v])){
                key[v] = qualPeso(gf, u, v);
                pai[v] = u;
                atualizarDistancias(Q, v, key[v]);            
            }
        }
    }
    for(i = 0; i < gf->quantVertices; i++){
        if(i != fonte){
            inserirAresta(grafoPrim, pai[i], i, key[i], false);
        }
    }
    return grafoPrim;
}


#endif