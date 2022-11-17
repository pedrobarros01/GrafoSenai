#include<stdio.h>
#include "ListaGrafos.h"


int main(){
    GrafoLista *gf1 = criarGrafoPorArquivo("arquivo.txt");
    imprimeLista(gf1);
    printf("\n");
    GrafoLista *gf2 = criarGrafo(3, true, false);
    inserirAresta(gf2, 0, 1, 0, true);
    inserirAresta(gf2, 0, 2, 0, true);
    inserirAresta(gf2, 1, 2, 0, true);
    imprimeLista(gf2);
    return 0;
}
