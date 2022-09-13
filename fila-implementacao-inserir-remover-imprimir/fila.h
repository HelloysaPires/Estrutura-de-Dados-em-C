#ifndef FILA_H
#define FILA_H

struct no{
    int dado;
    struct no *prox;
};

void inserirNaFila(int dado,  struct no **fila);

void removerDaFila(struct no **fila);

void imprimirFila(struct no **fila);

#endif