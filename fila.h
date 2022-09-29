#ifndef FILA_H
#define FILA_H
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct FILA_NO{
	int dados;
	struct FILA_NO *prox;
} FILA_NO;

typedef struct{
	FILA_NO *ini;
	FILA_NO *fim;
}FILA; 




FILA* cria_fila(){ // ela irá alocar um espaço na memória;
	FILA *fi = (FILA*) malloc(sizeof(FILA));
	if(fi != NULL){ // Deu certo a alocação
		fi->fim = NULL;  // Faz o ponteiro apontar para NULL, ou seja, a fila está vazia
		fi->ini = NULL;
	}
	return fi;
}	

int fila_vazia(FILA *f){
	if(f==NULL || f->ini==NULL) return 1;
	return 0;
}





int enfileira(FILA *f, int p){ 
	if(f==NULL) return 0;
	FILA_NO *novo_no = (FILA_NO*)malloc(sizeof(FILA_NO));
	if(novo_no==NULL) return 0; // Não alocou memória
	// atribuir os valores para o novo nó;
	novo_no->dados = p;
	novo_no->prox = NULL;
	if(f->ini==NULL){ // Fila vazia, vamos inserir no início
		f->ini = novo_no;
		f->fim = novo_no;
	}else{
		f->fim->prox = novo_no;
		f->fim = novo_no;
	}
	return 1;
}


int desenfileira(FILA *f){ 
	if(f==NULL) return 0;
	FILA_NO *aux = f->ini;
	
	
	// Desloca o inicio fazendo-o apontar para o próximo nó
	f->ini = aux->prox;
	int dado = aux->dados;
	// Libera o nó desempilhado
	free(aux);

	return dado;
}

void destroi_fila(FILA *f){
	FILA_NO *atu = f->ini;
	while (atu!=NULL){
		f->ini=atu->prox;
		free(atu);
		atu=f->ini;
	}
	f=NULL;
}


#endif