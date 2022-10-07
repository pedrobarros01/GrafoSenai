#include<stdio.h>
#include "lista.h"
int main(){
    LISTA *lista = cria_lista();
    insere_listase(lista, 2);
    insere_listase(lista, 5);
    insere_listase(lista, 1);
    insere_listase(lista, 10);
    insere_listase(lista, 4);
    insere_listase(lista, 14);
    imprime_listase(lista);
    int menor = buscarMenor(lista);
    printf("menor = %d\n", menor);
    imprime_listase(lista);
    destroi_listase(lista);
    return 0;
}