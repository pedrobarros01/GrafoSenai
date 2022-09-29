#include<stdio.h>
#include<stdlib.h>
//pedro henrique barros de oliveira sousa
typedef int tp_item;

typedef struct tp_no{
	struct tp_no *esq;
	tp_item info;
	struct tp_no *dir;
	
} tp_no;

typedef tp_no *tp_arvore;

tp_arvore* inicializaArvore(){
	tp_arvore* raiz = (tp_arvore*) malloc(sizeof(tp_arvore));
	if(raiz != NULL){
		*raiz = NULL;
	}
	return raiz;
}

int arvoreVazia(tp_arvore* raiz){
	if(raiz == NULL || *raiz == NULL){
		return 1;
	}else{
		return 0;
	}
	
}
void destroi_NO(tp_no* no){
	if(no == NULL){
		return;
	}
	destroi_NO(no->esq);
	destroi_NO(no->dir);
	free(no);
	no = NULL;
}
void destroi_Arv(tp_arvore* raiz){
	if(raiz == NULL){
		return;
	}
	destroi_NO(*raiz);
	free(raiz);
	
	
}

int num_Nos(tp_arvore* raiz){
	if(raiz == NULL){
		return 0;
	}
	if(*raiz == NULL){
		return 0;
	}
	int cont_esq = num_Nos(&((*raiz)->esq));
	int cont_dir = num_Nos(&((*raiz)->dir));
	return (cont_esq + cont_dir + 1);
	
}
int altura_arvore(tp_arvore* raiz){
	if(raiz == NULL){
		return 0;
	}
	if(*raiz == NULL){
		return 0;
	}
	
	int alt_esq = altura_arvore(&((*raiz)->esq));
	int alt_dir = altura_arvore(&((*raiz)->dir));
	if(alt_esq > alt_dir){
		return (alt_esq + 1);
	}else{
		return (alt_dir + 1);
	}
	
	
	
}

void pre_ordem_arvore(tp_arvore* raiz){
	if(raiz == NULL){
		return;
	}
	if(*raiz != NULL){
		printf("Valor do no: %d\n", (*raiz)->info);
		pre_ordem_arvore(&((*raiz)->esq));
		pre_ordem_arvore(&((*raiz)->dir));
	}
}
void em_ordem_arvore(tp_arvore* raiz){
	if(raiz == NULL){
		return;
	}
	if(*raiz != NULL){
		em_ordem_arvore(&((*raiz)->esq));
		printf("Valor do no: %d\n", (*raiz)->info);
		em_ordem_arvore(&((*raiz)->dir));
	}
}
void pos_ordem_arvore(tp_arvore* raiz){
	if(raiz == NULL){
		return;
		
	}
	if(*raiz != NULL){
		pos_ordem_arvore(&((*raiz)->esq));
		pos_ordem_arvore(&((*raiz)->dir));
		printf("Valor do no: %d\n", (*raiz)->info);
	}
}
int procurar_onde_inserir(tp_no* atual, tp_no* ant, tp_no* novo, tp_item valor){
	
	if(atual != NULL){
		ant = atual;
		if(valor == atual->info){
				free(novo);
				return 0;
				//elemento ja existe;
			}
			if(valor > atual->info){
				atual = atual->dir;
				return procurar_onde_inserir(atual, ant, novo, valor);
			}else{
				atual = atual->esq;
				return procurar_onde_inserir(atual, ant, novo, valor);
			}
		}
		if(valor > ant->info){
			ant->dir = novo;
		}else{
			ant->esq = novo;
		}
	
	
	
}
int insere_aarbore(tp_arvore *raiz, tp_item valor){
		if(raiz == NULL){
		return 0;
	}
	tp_no* novo = (tp_no*) malloc(sizeof(tp_no));
	if(novo == NULL){
		return 0;
	}
	novo->info = valor;
	novo->esq = NULL;
	novo->dir = NULL;
	//procurar onde vai ir
	if(*raiz == NULL){
		*raiz = novo;
	}else{
		tp_no* atual = *raiz;
		tp_no* ant = NULL;
		procurar_onde_inserir(atual,  ant,  novo,  valor);
	}
	return 1;
}

int insere_arvore(tp_arvore *raiz, tp_item valor){
	if(raiz == NULL){
		return 0;
	}
	tp_no* novo = (tp_no*) malloc(sizeof(tp_no));
	if(novo == NULL){
		return 0;
	}
	novo->info = valor;
	novo->esq = NULL;
	novo->dir = NULL;
	//procurar onde vai ir
	if(*raiz == NULL){
		*raiz = novo;
	}else{
		tp_no* atual = *raiz;
		tp_no* ant = NULL;
		
		while(atual != NULL){
			ant = atual;
			if(valor == atual->info){
				free(novo);
				return 0;
				//elemento ja existe;
			}
			if(valor > atual->info){
				atual = atual->dir;
			}else{
				atual = atual->esq;
			}
		}
		if(valor > ant->info){
			ant->dir = novo;
		}else{
			ant->esq = novo;
		}
	}
	return 1;
}
tp_no* remover_atual(tp_no* atual){
	tp_no *no1, *no2;
	if(atual->esq == NULL){
		no2 = atual->dir;
		free(atual);
		return no2;
	}
	no1 = atual;
	no2 = atual->esq;
	while(no2->dir != NULL){
		no1 = no2;
		no2 = no2->dir;
	}
	 if(no1 != atual){
	 	no1->dir = no2->esq;
	 	no2->esq = atual->esq;
	 }
	no2->dir = atual->dir;
	free(atual);
	return no2;
	
}

int remove_arvore(tp_arvore *raiz, tp_item valor){
	if(raiz == NULL){
		return 0;
	}
	tp_no* ant = NULL;
	tp_no* atual = *raiz;
	while(atual != NULL){
		if(valor == atual->info){
			if(atual == *raiz){
				*raiz = remover_atual(atual);
			}else{
				if(ant->dir == atual){
					ant->dir = remover_atual(atual);
				}else{
					ant->esq = remover_atual(atual);
				}
			}
			return 1;
		}
		ant = atual;
		if(valor > atual->info){
			atual = atual->dir;
		}else{
			atual = atual->esq;
		}
	}
	
	
}

int consulta_arvore(tp_arvore *raiz, tp_item valor){
	if(raiz == NULL){
		return 0;
	}
	tp_no* atual = *raiz;
	if(valor > atual->info){
		return consulta_arvore(&((*raiz)->dir), valor);
	}
	if(valor < atual->info){
		return consulta_arvore(&((*raiz)->esq), valor);
	}
	if(valor == atual->info){
		
		return atual->info;
	}
}



