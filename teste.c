#include<stdio.h>
#include "lista.h"
int main(){
    LISTA *lista = cria_lista();
    insere_listase(lista, 0, 1);
    insere_listase(lista, 1, INT_MAX);
    insere_listase(lista, 2, INT_MAX);
    insere_listase(lista, 3, INT_MAX);
    insere_listase(lista, 4, INT_MAX);
    atualizarDistancias(lista, 1, 1);
    imprime_listase(lista);
    destroi_listase(lista);
    return 0;
}