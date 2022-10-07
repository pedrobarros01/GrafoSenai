#ifndef LISTA_H
#define LISTA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "arvores.h"


// Pedro Barros
typedef struct LISTA_NO{
	int dado;
	struct LISTA_NO *prox;
} LISTA_NO;

typedef LISTA_NO* LISTA; // Ponteiro para um Ponteiro

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
int insere_listase(LISTA *l, int c){ // Esse *l é um ponteiro que está apontando para outro ponteiro para o endereço de memória original da LISTA*, o que está apontando para o NULL
	if(l==NULL) return 0;
	LISTA_NO *novo_no = (LISTA_NO*)malloc(sizeof(LISTA_NO));
	if(novo_no==NULL) return 0; // Não alocou memória
	// atribuir os valores para o novo nó;
	novo_no->dado = c;
	novo_no->prox = NULL;
	if((*l)==NULL)// Lista está vazia, vamos inserir no início
		*l = novo_no;
	else{
		LISTA_NO *aux = *l;              // novo_no { Z, NULL }
		while(aux->prox != NULL){  // aux = F
			                       // |A ->B| |B ->F| |F ->Z| |Z ->NULL|
			aux = aux->prox;
		}
		aux->prox = novo_no;
	}
	return 1;
}


void imprime_listase(LISTA *l){
	LISTA_NO *aux = *l;
	while (aux!=NULL){
		if(aux->prox == NULL){
			printf("%d", aux->dado);
		}else{
			printf("%d -> ", aux->dado); 
		}
		aux=aux->prox;
	}
	printf("\n\n\n");
}
int buscar_posMenor(LISTA *l){
	int c = 1, menor = 276447232, posMenor = 1;
	if(l == NULL) return 0;
	LISTA_NO *anterior, *aux = *l;
	while(aux != NULL){
		if(aux->dado < menor){
			menor = aux->dado;
			posMenor = c;
		}
		aux = aux->prox;
		c++;
	}
	return posMenor; 
}
int buscar_remover(LISTA *l, int pos){
	int c = 1, answer;
	if(l == NULL) return 0;
	LISTA_NO *anterior, *aux = *l;
	while(aux != NULL && c < pos){
		anterior = aux;
		aux = aux->prox;
		c++;
		
	} 
	if(aux == NULL) return 0;
	if(aux == *l){
		answer = aux->dado;
		*l = aux->prox;
	}else{
		
		answer = aux->dado;
		anterior->prox = aux->prox;
		free(aux);
	}
	return answer;
}
int buscarMenor(LISTA *l){
	int posMenor = buscar_posMenor(l);
	int menor = buscar_remover(l, posMenor);
	return menor;
}

void destroi_listase(LISTA *l){
	LISTA_NO *atu = *l;                  //             atu
	while (atu!=NULL){             //              l
		*l=atu->prox;              //             NULL
		free(atu);
		atu=*l;
	}
	free(l);
}
#endif