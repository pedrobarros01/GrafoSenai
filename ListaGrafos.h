#ifndef LISTAGRAFOS_H
#define LISTAGRAFOS_H
#define CINZA 1
#define BRANCO 0
#define PRETO 2
#define INFINITO INT_MAX
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<string.h>
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
typedef struct GrauDigrafo{
	int saida;
	int entrada;
} GrauDigrafo;
typedef struct Grau{
    GrauDigrafo *vetor;
    int *grauGrafo;
}Grau;
typedef struct ArestaKruskal{
    Vertice fonte;
    Vertice destino;
    Peso peso;
}ArestaKruskal;

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
int ordemGrafo(GrafoLista *gf){
	return gf->quantVertices;
}
int tamanhoGrafo(GrafoLista *gf){
	int tamanhoGrafo = 0;
	int i;
	for( i =0; i < gf->quantVertices; i++){
		NO_ADJ *aux;
		for(aux = gf->lista[i]; aux != NULL; aux=aux->prox){
			tamanhoGrafo++;
		}
	}
    if(gf->eh_digrafo){
	    return tamanhoGrafo;
    }
    return tamanhoGrafo / 2;
}

int maximoArestas(GrafoLista *gf){
	if(gf->eh_digrafo){
		
		return gf->quantVertices * (gf->quantVertices - 1);
	}
	
	return (gf->quantVertices * (gf->quantVertices - 1)) / 2;
}

double densidade(GrafoLista * gf){
	return tamanhoGrafo(gf) / (double)maximoArestas(gf);
}
int SaberEntrada(GrafoLista *gf,  Vertice dado){
	int i, entrada = 0;
	for(i = 0; i < gf->quantVertices; i++){
		if( i != dado){
			NO_ADJ *aux;
            for(aux = gf->lista[i]; aux != NULL; aux=aux->prox){
                if(aux->vertice == dado){
                    entrada++;
                }
            }
		}
	}
	return entrada;
}
int saberSaida(GrafoLista *gf, Vertice dado){
	int saida = 0;
	NO_ADJ *aux;
	for(aux = gf->lista[dado]; aux != NULL; aux=aux->prox){
		saida++;
	}
	return saida;
}

Grau grau(GrafoLista *gf){
    Grau grau;
    grau.vetor = (GrauDigrafo*)malloc(gf->quantVertices*sizeof(GrauDigrafo));
    grau.grauGrafo = (int*)malloc(gf->quantVertices*sizeof(int));
    int i;
    for(i = 0; i <gf->quantVertices; i++){
        grau.grauGrafo[i] = 0;
    }
	if(gf->eh_digrafo){
		int j;
		for(j = 0; j < gf->quantVertices; j++){
			grau.vetor[j].entrada = SaberEntrada(gf, j);
			grau.vetor[j].saida = saberSaida(gf, j);
		}
	}else{
		int i;
        for( i =0; i < gf->quantVertices; i++){
            NO_ADJ *aux;
            for(aux = gf->lista[i]; aux != NULL; aux=aux->prox){
                grau.grauGrafo[i]++;
            }
        }
	}

    return grau;
	
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
bool achou;
void dfsAux(GrafoLista *gf, Vertice atual, Vertice destino, bool *vetVisitado){
    vetVisitado[atual] = true;
    NO_ADJ *aux;
    for(aux=gf->lista[atual]; aux != NULL; aux=aux->prox){
        if(aux->vertice == destino){
            achou = true;
        }
        if(!achou && !vetVisitado[aux->vertice]){
            dfsAux(gf, aux->vertice, destino, vetVisitado);
        }
    }

}
/* 
nova dfs para achar se contem ligação de fonte para destino
 */
bool dfs(GrafoLista *gf, Vertice fonte, Vertice destino){
    achou = false;
    bool *vetVisitado = (bool*)malloc(gf->quantVertices*sizeof(bool));
    int i;
    for(i = 0; i <gf->quantVertices; i++){
        vetVisitado[i] = false;
    }
    dfsAux(gf, fonte, destino, vetVisitado);
    
    return achou;
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
void bubbleSortKruskal(ArestaKruskal *vetor, int tamanho){
    int i, j;
    for(i = 0; i < tamanho - 1; i++){
        for(j = 0; j < tamanho - i - 1; j++){
            if(vetor[j].peso > vetor[j + 1].peso){
                ArestaKruskal temp = vetor[j];
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
serve pra grafos com pesos negativos
nao servem para digrafo
*/
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

bool marcado(int *vetorMarcado, int procurado, int tamanhoVetor){
    int i;
    bool achou = false;
    for(i = 0; i < tamanhoVetor; i++){
        if(vetorMarcado[i] == procurado){
            achou = true;
            break;
        }
    }
    return achou;
}


ArestaKruskal* retornarListaAresta(GrafoLista *gf){
    int cont = 0;
    ArestaKruskal *listaAresta = (ArestaKruskal*)malloc(tamanhoGrafo(gf)*sizeof(ArestaKruskal));
    int *vetorMarcado = (int*)malloc(gf->quantVertices*sizeof(int));
    int i;
    for(i = 0; i < gf->quantVertices; i++){
        vetorMarcado[i] = -1;
    }
    NO_ADJ *aux;
    for(i = 0; i < gf->quantVertices; i++){
        for(aux=gf->lista[i]; aux != NULL; aux=aux->prox){
            if(!marcado(vetorMarcado, aux->vertice, gf->quantVertices)){
                listaAresta[cont].fonte = i;
                listaAresta[cont].destino = aux->vertice;
                listaAresta[cont].peso = aux->peso;
                cont++;
            }
        }
        vetorMarcado[i] = i;
    }
    return listaAresta;

}


//Kruskal -> gera uma AGM
GrafoLista* kruskal(GrafoLista *gf){
    GrafoLista *set = criarGrafo(gf->quantVertices, gf->eh_digrafo, gf->eh_com_peso);
    ArestaKruskal *arestas = retornarListaAresta(gf);
    bubbleSortKruskal(arestas, tamanhoGrafo(gf));
    int tamArestas = tamanhoGrafo(gf);
    int i;
    for(i = 0; i < tamArestas; i++){
        bool achouLigacao = dfs(set, arestas[i].fonte, arestas[i].destino);
        if(!achouLigacao){
            inserirAresta(set, arestas[i].fonte, arestas[i].destino, arestas[i].peso, false);
        }
    }
    return set;
}
GrafoLista* criarGrafoPorArquivo(char *nomeArquivo){
    FILE *arq = fopen(nomeArquivo, "r");
    //verificar se arq == null pra erro
    char stringArquivo[100];
    fgets(stringArquivo, sizeof(stringArquivo), arq);
    char *sub1 = strtok(stringArquivo, " \n");
    int numVertice, numArestas = 0;
    int cont = 0;
    int indiceAresta = 0;
    int arestaFonte, arestaDestino, peso;
    bool ehDrigrafo = false;
    bool ehComPeso = false;
    while(sub1){
        if(strcmp(sub1, "Vertices") != 0){
            numVertice = atoi(sub1);
        }
        sub1 = strtok(NULL, " \n");
    }
    while(fgets(stringArquivo, sizeof(stringArquivo), arq) != NULL){
        if(cont == numVertice){
            //printf("%s", stringArquivo);
            if(strcmp("*Arcs\n", stringArquivo) == 0){
                ehDrigrafo = true;
            }else if(strcmp("*Edges\n", stringArquivo) == 0){
                ehDrigrafo = false;
            }
        }else if(cont >= numVertice + 1){
            numArestas++;
        }
        cont++;
    }
    fclose(arq);
    ArestaKruskal *listaArestas = (ArestaKruskal*)malloc(numArestas * sizeof(ArestaKruskal));
    FILE *arq2 = fopen(nomeArquivo, "r");
    char stringArquivo2[1000];
    cont = 0;
    int contAux = 0;
    while(fgets(stringArquivo2, sizeof(stringArquivo2), arq2) != NULL){
        if(cont >= numVertice + 2){
            char *px = strtok(stringArquivo2, " \n");
           while(px){
                contAux++;
                if(contAux == 1){
                    arestaFonte = atoi(px) - 1;
                }
                if(contAux == 2){
                    arestaDestino = atoi(px) - 1;
                }
                if(contAux == 3){
                    peso = atoi(px);
                    ehComPeso = true;
                }else{
                    ehComPeso = false;
                    peso = 0;
                }
                px = strtok(NULL, " \n");
           }
            listaArestas[indiceAresta].fonte = arestaFonte;
            listaArestas[indiceAresta].destino = arestaDestino;
            listaArestas[indiceAresta].peso = peso;
            indiceAresta++;
            contAux = 0;            
            
        }
        cont++;
    }
    printf("ehDigrafo: %d\n", ehDrigrafo);
    printf("numArestas: %d\n", numArestas);
    printf("numVertice: %d\n", numVertice);
    fclose(arq2);
    int i;
    for(i = 0; i < numArestas; i++){
        printf("Aresta %d\n", i+1);
        printf("Fonte: %d\n", listaArestas[i].fonte);
        printf("Destino: %d\n", listaArestas[i].destino);
        printf("Peso: %d\n", listaArestas[i].peso);
        printf("=================================\n");
    }
    GrafoLista *gf = criarGrafo(numVertice, ehDrigrafo, ehComPeso);
    for(i = 0; i < numArestas; i++){
        inserirAresta(gf, listaArestas[i].fonte, listaArestas[i].destino, listaArestas[i].peso, ehDrigrafo);
    }
    return gf;
}






#endif