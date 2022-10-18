#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef struct no{
	int dados;
	struct no *prox;
} NO;


typedef NO* PILHA; // ponteiro para ponteiro->ponteiro especial


PILHA* criar_pilha(){
	PILHA *pi = (PILHA*) malloc(sizeof(PILHA));
	if(pi != NULL){
		*pi = NULL;
	}
	return pi;
}


int empilhar(PILHA *p, int c){
	if(p == NULL) return 0;
	NO *novo_no = (NO*) malloc(sizeof(NO));
	if(novo_no == NULL) return 0;
	
	novo_no->dados = c;
	novo_no->prox = NULL;
	if((*p) == NULL){
		*p = novo_no;
	}else{
		novo_no->prox = *p;
		*p = novo_no;
	}
	return 1;	
}

int desempilhar(PILHA *p){
	NO *topo = *p;
	int dado = -1;
	if(topo != NULL){
		dado = topo->dados;
		*p = topo->prox;
		 free(topo);	 
	}
	return dado;
	
}

int tamanho_pilha(PILHA *p){
	int cont = 0;
	NO *aux = *p;
	while(aux != NULL){
		cont++;
		aux=aux->prox;
	}
	return cont;
	
}

void destruir_pilha(PILHA *p){
	NO *aux = *p;
	while(aux != NULL){
		*p = aux->prox;
		free(aux);
		aux=*p;
	}
	*p = NULL;
	//free(p);
}

void imprime_pilha(PILHA *p){
	NO *aux = *p;
	printf("#### PILHA TOPO ####\n");
	
	while(aux != NULL){
		printf("###Valor:%d\n",aux->dados + 1);
		aux = aux->prox;
	}
	printf("#### PILHA BASE ####\n");
}

int pilha_vazia(PILHA *p){
	if(p == NULL) return 1;
	if(*p == NULL) return 1;
	return 0;
}

int consulta_pilha(PILHA *p, int *c){
	if(p == NULL) return 0;
	if((*p) == NULL) return 0;
	*c = (*p)->dados;
	return 1;
		
}
