#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria.h"

int main()
{
    No * raiz = NULL;
    No * busca;
    
    raiz = inserir(50, raiz);
    raiz = inserir(20, raiz);
    raiz = inserir(100, raiz);
    raiz = inserir(30, raiz);
    
    inserirSemRetorno(19, &raiz);
    inserirSemRetorno(70, &raiz);
    inserirSemRetorno(40, &raiz);
    inserirSemRetorno(95, &raiz);
    
    inserirIterativo(25, &raiz);
    inserirIterativo(43, &raiz);
    inserirIterativo(67, &raiz);
    inserirIterativo(92, &raiz);

    imprimirOrdemInsercao(raiz);
    printf("\n");
    imprimirCrescente(raiz);
    printf("\n");
    imprimirDecrescente(raiz);
    printf("\n");
    
    busca = buscar(40, raiz);
    if (busca != NULL) printf("Valor %d encontrado!\n", busca->valor);
    
    printf("%d\n", alturaArvore(raiz));
    printf("%d\n", quantidadeNos(raiz));
    printf("%d\n", quantidadeFolhas(raiz));
    printf("%d\n", quantidadeFolhasEsquerda(raiz));
    printf("%d\n", quantidadeFolhasDireita(raiz));
    
    raiz = removerNo(19, raiz);
    imprimirOrdemInsercao(raiz);
    printf("\n");
    
    raiz = removerNo(40, raiz);
    imprimirOrdemInsercao(raiz);
    printf("\n");
    
    raiz = removerNo(30, raiz);
    imprimirOrdemInsercao(raiz);
    printf("\n");
    
    return 0;
}
