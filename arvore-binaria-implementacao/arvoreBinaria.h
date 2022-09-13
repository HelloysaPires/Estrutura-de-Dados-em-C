#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

typedef struct no{
    int valor;
    struct no * esquerda;
    struct no * direita;
} No;

No * inserir(int, No *);

void inserirSemRetorno(int, No **);

void inserirIterativo(int, No ** );

No * buscar(int, No *);

int alturaArvore(No *);

int quantidadeNos(No *);

int quantidadeFolhas(No *);

int quantidadeFolhasEsquerda(No *);

int quantidadeFolhasDireita(No *);

No * removerNo(int, No *);

void imprimirOrdemInsercao(No *); 

void imprimirCrescente(No *);

void imprimirDecrescente(No * );

#endif