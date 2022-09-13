#ifndef ARVOREAVL_H
#define ARVOREAVL_H

typedef struct no{
    int valor;
    struct no * esquerda;
    struct no * direita;
    int altura;
} No;

No * criarArvoreAVL(No *);

int maiorAltura(int, int);

int alturaNo(No *);

int calcularBalanceamento(No *);

No * rotacaoEsquerda(No *);

No * rotacaoDireita(No *);

No * rotacaoDireitaEsquerda(No *);

No * rotacaoEsquerdaDireira(No *);

No * balancear(No *);

No * inserirAVL(int, No *);

No * removerAVL(int, No *);

void imprimir(int, No *);

#endif