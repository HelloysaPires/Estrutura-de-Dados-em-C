#include <stdio.h>
#include <stdlib.h>
#include "arvoreAVL.h"

No * criarArvoreAVL(No * raiz){
    return NULL;
}
int maiorAltura(int x, int y){  
    return (x > y) ? x : y;
}

int alturaNo(No * arvore){
    if (arvore == NULL) return -1;
    else return arvore->altura;
}

int calcularBalanceamento(No * arvore){
    if(arvore) return (alturaNo(arvore->esquerda) - alturaNo(arvore->direita));
    else return 0;
}

No * rotacaoEsquerda(No * raiz){
    
    No * subArvoreDireita = raiz->direita;
    No * esquerdaDaSubArvoreDireita = subArvoreDireita->esquerda;
    
    subArvoreDireita->esquerda = raiz;
    raiz->direita = esquerdaDaSubArvoreDireita;
    
    raiz->altura = maiorAltura(alturaNo(raiz->esquerda), alturaNo(raiz->direita)) + 1;
    subArvoreDireita->altura = maiorAltura(alturaNo(subArvoreDireita->esquerda), alturaNo(subArvoreDireita->direita)) + 1;
    
    
    return subArvoreDireita;
}

No * rotacaoDireita(No * raiz){
    
    No * subArvoreEsquerda = raiz->esquerda;
    No * direitaDaSubArvoreEsquerda = subArvoreEsquerda->direita;
    
    subArvoreEsquerda->direita = raiz;
    raiz->esquerda = direitaDaSubArvoreEsquerda;
    
    raiz->altura = maiorAltura(alturaNo(raiz->esquerda), alturaNo(raiz->direita)) + 1;
    subArvoreEsquerda->altura = maiorAltura(alturaNo(subArvoreEsquerda->esquerda), alturaNo(subArvoreEsquerda->direita)) + 1;
    
    return subArvoreEsquerda;
}
    
No * rotacaoDireitaEsquerda(No * raiz){
    
    raiz->direita = rotacaoDireita(raiz->direita);
    return rotacaoEsquerda(raiz);
}

No * rotacaoEsquerdaDireira(No * raiz){
    
    raiz->esquerda = rotacaoEsquerda(raiz->esquerda);
    return rotacaoDireita(raiz);
}

No * balancear(No * raiz){
    int i = calcularBalanceamento(raiz);
    
    if(i<-1 && calcularBalanceamento(raiz->direita) <=0) raiz = rotacaoEsquerda(raiz);
    else if(i>1 && calcularBalanceamento(raiz->esquerda) >=0) raiz = rotacaoDireita(raiz);
    else if(i>1 && calcularBalanceamento(raiz->esquerda) <0) raiz = rotacaoEsquerdaDireira(raiz);
    else if(i<-1 && calcularBalanceamento(raiz->direita) > 0) raiz = rotacaoDireitaEsquerda(raiz);
    
    return raiz;
    
}

No * inserirAVL(int valor, No * raiz){
    
    if(raiz == NULL){
        No * aux = malloc(sizeof(No));
        aux->valor = valor;
        aux->direita = NULL;
        aux->esquerda = NULL;
        aux->altura = 0;
        
        return aux;
    }
    else{
        if( valor < raiz->valor) raiz->esquerda = inserirAVL(valor, raiz->esquerda);
        else raiz->direita = inserirAVL(valor, raiz->direita); 
    }
    
    raiz->altura = maiorAltura(alturaNo(raiz->esquerda), alturaNo(raiz->direita)) + 1;
    
    return balancear(raiz);
}

No * removerAVL(int valor, No * raiz){
    
    if(raiz == NULL) return NULL; 
    
    else{
        if(raiz->valor == valor) { 
           if( raiz->esquerda == NULL && raiz->direita == NULL) { 
              free(raiz);
              return NULL;
           }
           else{ 
            
                if( raiz->esquerda == NULL && raiz->direita != NULL) {
                    No * aux = raiz->direita;
                    free(raiz);
                    return aux;
                }
                else if( raiz->esquerda != NULL && raiz->direita == NULL) { 
                    No * aux = raiz->esquerda;
                    free(raiz);
                    return aux;          
               }
                else{ 
                  
                  No * aux = raiz->esquerda;
                  while(aux->direita != NULL) aux = aux->direita; 
                  
                  
                  raiz->valor = aux->valor;   
                  aux->valor = valor;
                  
                  raiz->esquerda = removerAVL(valor, raiz->esquerda); 
                  return raiz;
               }
           }
       }
        else{  
           if(raiz->valor > valor) raiz->esquerda = removerAVL(valor, raiz->esquerda);
           else raiz->direita = removerAVL(valor, raiz->direita);

       }
       
       raiz->altura = maiorAltura(alturaNo(raiz->esquerda), alturaNo(raiz->direita)) + 1;
    
       return balancear(raiz);
   }
    
}

void imprimir(int nivel, No *raiz){

    if(raiz){
        
       imprimir(nivel + 1, raiz->direita);
       printf("\n");
        
       for(int i = 0; i<nivel; i++) printf("\t");
       
       printf("%d", raiz->valor);
       imprimir(nivel + 1, raiz->esquerda);
    }
    
}
