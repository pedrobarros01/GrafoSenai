#include<stdio.h>
#include<stdlib.h>
# include "arvores.h"
//pedro henrique barros de oliveira sousa
int main(){
	tp_arvore* raiz = inicializaArvore();
	
	insere_aarbore(raiz, 100);
	insere_aarbore(raiz, 50);
	insere_aarbore(raiz, 90);
	insere_aarbore(raiz, 25);
	insere_aarbore(raiz, 55);
	
	
	
	printf("======EM ORDEM==========\n");
	em_ordem_arvore(raiz);
	printf("\n======POS ORDEM=========\n");
	pos_ordem_arvore(raiz);
	printf("\n======PRE ORDEM=========\n");
	pre_ordem_arvore(raiz);
	printf("\n========================\n");
	int altura = altura_arvore(raiz);
	printf("altura da arvore eh: %d\n", altura);
	int totalNos = num_Nos(raiz);
	printf("numero de nos eh: %d\n", totalNos);
	
	
	remove_arvore(raiz, 50);
	printf("======EM ORDEM==========\n");
	em_ordem_arvore(raiz);
	
	
	tp_item valor;
	valor = consulta_arvore(raiz, 90);
	printf("pegar : %d\n", valor);
	
	
	
	destroi_Arv(raiz);
	
	
	
	return 0;
}
