#ifndef LISTA_H
#define LISTA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct VerticeBusca {
    int dado;
    int distancia;
    int visitado;
    VerticeBusca *p;
} VerticeBusca;


// Pedro Barros
typedef struct no{
	VerticeBusca dados;
	struct no *prox;
} NO;

typedef NO* LISTA; // Ponteiro para um Ponteiro

LISTA* cria_lista(){ // ela irá alocar um espaço na memória;
	LISTA *li = (LISTA*) malloc(sizeof(LISTA));
	if(li != NULL) // Deu certo a alocação
		*li = NULL;  // Faz o ponteiro apontar para NULL, ou seja, a lista está vazia
	return li;
}	

int listase_vazia(LISTA *l){
	if(l==NULL) return 1;
	return 0;
}

// Função que insere ao final da lista
int insere_listase(LISTA *l, VerticeBusca c){ // Esse *l é um ponteiro que está apontando para outro ponteiro para o endereço de memória original da LISTA*, o que está apontando para o NULL
	if(l==NULL) return 0;
	NO *novo_no = (NO*)malloc(sizeof(NO));
	if(novo_no==NULL) return 0; // Não alocou memória
	// atribuir os valores para o novo nó;
	novo_no->dados = c;
	novo_no->prox = NULL;
	if((*l)==NULL)// Lista está vazia, vamos inserir no início
		*l = novo_no;
	else{
		NO *aux = *l;              // novo_no { Z, NULL }
		while(aux->prox != NULL){  // aux = F
			                       // |A ->B| |B ->F| |F ->Z| |Z ->NULL|
			aux = aux->prox;
		}
		aux->prox = novo_no;
	}
	return 1;
}


void imprime_listase(LISTA *l){
	NO *aux = *l;
	while (aux!=NULL){
		printf("%d ", aux->dados);
		aux=aux->prox;
	}
	printf("\n");
}


#endif