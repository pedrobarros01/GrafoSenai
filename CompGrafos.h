#ifndef COMPGRAFOS_H
#define COMPGRAFOS_H
#include<stdlib.h>
#include<stdbool.h>
typedef int Vertice;
typedef double Peso;
typedef struct NO_ADJ {
    Vertice vertice;
    Peso peso;
    NO_ADJ *prox;
} NO_ADJ;
typedef NO_ADJ** listaAdj;
typedef struct GrafoLista {
    int quantVertices;
    bool eh_digrafo;
    bool eh_com_peso;
    listaAdj lista;
} GrafoLista;

GrafoLista* criarGrafo(int quantVertices, bool eh_digrafo, bool eh_com_peso){
    GrafoLista *gf = (GrafoLista*)malloc(sizeof(GrafoLista));
    if(gf == NULL){
        return NULL;
    }
    gf->eh_digrafo = eh_digrafo;
    gf->quantVertices = quantVertices;
    gf->eh_com_peso = eh_com_peso;
    gf->lista = (listaAdj)malloc(gf->quantVertices * sizeof(listaAdj));
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
bool inserirAresta(GrafoLista *gf, int origem, int destino, Peso peso){
    if(!temVertice(origem, gf) || !temVertice(destino, gf)){
        return false;
    }
    NO_ADJ *novo_no = (NO_ADJ*)malloc(sizeof(NO_ADJ));
    novo_no->vertice = destino;
    novo_no->peso = -1;
    if(gf->eh_com_peso){
        novo_no->peso = peso;
    }
    //caso for grafo
    gf->lista[origem] = novo_no;
    novo_no->prox = gf->lista[origem];
    NO_ADJ *novo_no_destino = (NO_ADJ*)malloc(sizeof(NO_ADJ));
    novo_no->vertice = origem;
    novo_no->peso = -1;
    if(gf->eh_com_peso){
        novo_no->peso = peso;
    }
    gf->lista[destino] = novo_no_destino;
    novo_no_destino->prox = gf->lista[destino];

    
    //caso for digrafo
    gf->lista[origem] = novo_no;
    novo_no->prox = gf->lista[origem];
    //continuo dps isso daqui
    return true;

}

#endif