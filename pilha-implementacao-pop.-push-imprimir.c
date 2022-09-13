#include <stdio.h>
#include <stdlib.h>

struct no{
    int dia, mes, ano;
    struct no * prox;
};

void push(int dia, int mes, int ano, struct no **pilha){ //empilhar
    
    struct no *novo = malloc (sizeof(struct no));
    
    if(*pilha == NULL){
        
        novo->dia = dia;
        novo->mes = mes;
        novo->ano = ano;
        novo->prox = NULL;
        *pilha = novo;
        
    }else{
        novo->dia = dia;
        novo->mes = mes;
        novo->ano = ano;
        novo->prox = *pilha;
        *pilha = novo;
    }
    
}

void pop(struct no **pilha){ // desempilhar
    struct no *novo = malloc (sizeof(struct no));
    novo = *pilha; 
    novo = novo->prox;
    
    free(*pilha);
    *pilha = novo;
}

void imprimirPilha(struct no **pilha){  // imprimir pilha
    struct no *novo = malloc (sizeof(struct no));
    novo = *pilha;
    
        while(novo->prox != NULL){
            printf("%d/%d/%d\n", novo->dia, novo->mes, novo->ano);
            novo = novo->prox;
        }
            printf("%d/%d/%d\n", novo->dia, novo->mes, novo->ano);
}


int main()
{   int dia, mes, ano;
    struct no *pilha = NULL;
    
    for(int i = 0; i<3;i++){
        printf("Digite o dia, mes e ano: ");
        scanf("%d/%d/%d", &dia, &mes, &ano);
        push(dia, mes, ano, &pilha);
    }
    
    printf("\n");
    imprimirPilha(&pilha);
    
    pop(&pilha);
    
    printf("\n");
    imprimirPilha(&pilha);

    return 0;
}
