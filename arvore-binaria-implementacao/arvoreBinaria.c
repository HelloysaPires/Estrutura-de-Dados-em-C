#include <stdio.h>
#include <stdlib.h>
#include "arvoreBinaria.h"

No * inserir(int valor, No *raiz){
    
    if(raiz == NULL){
        No * aux = malloc(sizeof(No));
        aux->valor = valor;
        aux->direita = NULL;
        aux->esquerda = NULL;
        
        return aux;
    }
    else{
        if( valor < raiz->valor) raiz->esquerda = inserir(valor, raiz->esquerda);
        else raiz->direita = inserir(valor, raiz->direita); 
    
        return raiz;
    }
}

void inserirSemRetorno(int valor, No **raiz){
    
     if(*raiz == NULL){
        *raiz = malloc(sizeof(No));
       (*raiz)->valor = valor;
       (*raiz)->direita = NULL;
       (*raiz)->esquerda = NULL;
    }
    else{
        if( valor < (*raiz)->valor ) inserirSemRetorno(valor, &(*raiz)->esquerda);
        else inserirSemRetorno(valor, &(*raiz)->direita); 
    }
    
}

void inserirIterativo(int valor, No ** raiz){
    
    No * aux = *raiz;
    
    while(aux){
        
        if(valor < aux->valor) raiz = &aux->esquerda;
        else raiz = &aux->direita;
        
        aux = *raiz;
    }
    
    aux = malloc(sizeof(No));
    aux->valor = valor;
    aux->direita = NULL;
    aux->esquerda = NULL;
    
    *raiz = aux;
}

No * buscar(int valor, No * raiz){
    
    if(raiz){
        if(valor == raiz->valor) return raiz;
        else if(valor < raiz-> valor) return buscar(valor, raiz->esquerda);
        else return buscar(valor, raiz->direita);
    }
    return NULL;
}

int alturaArvore(No *raiz){
    
    if(raiz == NULL) return -1;
    else{
        int esq = alturaArvore(raiz->esquerda);
        int dir = alturaArvore(raiz->direita);
        return esq>dir ? esq + 1 : dir + 1 ;
    }
}

int quantidadeNos(No *raiz){
    return raiz == NULL ? 0 : quantidadeNos(raiz->esquerda) + quantidadeNos(raiz->direita) + 1;
}

int quantidadeFolhas(No *raiz){
    if(raiz == NULL) return 0;
    else if ((raiz->esquerda) == NULL && (raiz->direita) == NULL) return 1;
    else  return quantidadeFolhas(raiz->esquerda) + quantidadeFolhas(raiz->direita);
}

int quantidadeFolhasEsquerda(No *raiz){
    if(raiz == NULL) return 0;
    else if ((raiz->esquerda) == NULL) return 1;
    else  return quantidadeFolhas(raiz->esquerda);
}

int quantidadeFolhasDireita(No *raiz){
    if(raiz == NULL) return 0;
    else if ((raiz->direita) == NULL) return 1;
    else  return quantidadeFolhas(raiz->direita);
}

No* removerNo(int valor, No *raiz){
    
    if(raiz == NULL) return NULL; // raiz vazia
    
    else{
        if(raiz->valor == valor) { //valor achado
           if( raiz->esquerda == NULL && raiz->direita == NULL) { // no com valor achado NAO tem filhos
              free(raiz);
              return NULL;
           }
           else{ // no com valor achado TEM filhos
            
                if( raiz->esquerda == NULL && raiz->direita != NULL) { // tem UM filho: DIREITO
                    No * aux = raiz->direita;
                    free(raiz);
                    return aux;
                }
                else if( raiz->esquerda != NULL && raiz->direita == NULL) { // tem UM filho: ESQUERDO
                    No * aux = raiz->esquerda;
                    free(raiz);
                    return aux;          
               }
                else{ // tem DOIS filhos
                  
                  No * aux = raiz->esquerda; // ir para sub arvore a esquerda da "raiz" ( raiz = No com o valor que se deseja retirar)
                  while(aux->direita != NULL) aux = aux->direita; //achar o No mais a direita dessa sub arvore
                  
                  //trocar valor do No que se deseja retirar com o No encontrado
                  raiz->valor = aux->valor; //  
                  aux->valor = valor;
                  
                  raiz->esquerda = removerNo(valor, raiz->esquerda); // agora como o No que se quer retirar é um No com somente um filho 
                                                                    // ou sem filhos (devido a troca houve simplificação), é só fazer a chamada recursiva pra remover
                                                                    
                  return raiz;
               }
           }
       }
        else{ // percorrer a arvore até achar o valor procurado 
           if(raiz->valor > valor) raiz->esquerda = removerNo(valor, raiz->esquerda);
           else raiz->direita = removerNo(valor, raiz->direita);
        
           return raiz;
       }
   }
}


void imprimirOrdemInsercao(No * raiz){
    if(raiz){
        printf("%d ", raiz->valor);
        imprimirOrdemInsercao(raiz->esquerda);
        imprimirOrdemInsercao(raiz->direita);
    }
}

void imprimirCrescente(No * raiz){
    if(raiz){
        imprimirCrescente(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimirCrescente(raiz->direita);
    }
}

void imprimirDecrescente(No * raiz){
    if(raiz){
        imprimirDecrescente(raiz->direita);
        printf("%d ", raiz->valor);
        imprimirDecrescente(raiz->esquerda);
    }
}
