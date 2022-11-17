#include<stdio.h>
#include "ListaGrafos.h"

int main(){
    GrafoLista *gf1 = criarGrafoPorArquivo("arquivo.txt");
    GrafoLista* grafoPrim = prim(gf1, 0);
	GrafoLista* grafoKruskal = kruskal(gf1);
	printf("====PRIM=====\n");
	imprimeLista(grafoPrim);
	printf("====Kruskal=====\n");
	imprimeLista(grafoKruskal);	
    return 0;
}