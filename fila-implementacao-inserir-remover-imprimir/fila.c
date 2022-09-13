#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void inserirNaFila(int dado,  struct no **fila){
     struct no *novo = malloc (sizeof(struct no));
     struct no *aux = malloc (sizeof(struct no));
     
    if(*fila == NULL){
        novo->dado = dado;
        novo->prox = NULL;
        
        *fila = novo;
    }else{
           novo = *fila;
         while(novo->prox != NULL){
           novo = novo->prox;
        }  
           aux->dado = dado;
           aux->prox = NULL;
           novo->prox = aux;
    }
}

void removerDaFila(struct no **fila){
    struct no *novo = malloc (sizeof(struct no));
    novo = *fila; 
    novo = novo->prox;
    
    free(*fila);
    *fila = novo;
}

void imprimirFila(struct no **fila){
    struct no *novo = malloc (sizeof(struct no));
    novo = *fila;
    
        while(novo->prox != NULL){
            printf("%d\n", novo->dado);
            novo = novo->prox;
        }
            printf("%d\n", novo->dado);
}



