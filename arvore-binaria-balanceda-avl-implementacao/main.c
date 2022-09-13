#include <stdio.h>
#include "arvoreAVL.h"

void testarAvoreAVL(){
    
    No * raiz = criarArvoreAVL(raiz);
    
    printf("\nInserir nós 10, 20, 30, 40, 50, 60, 70, 80 e balancear: \n");
    raiz = inserirAVL(10, raiz);
    raiz = inserirAVL(20, raiz);
    raiz = inserirAVL(30, raiz);
    raiz = inserirAVL(40, raiz);
    raiz = inserirAVL(50, raiz);
    raiz = inserirAVL(60, raiz);
    raiz = inserirAVL(70, raiz);
    raiz = inserirAVL(80, raiz);
    
    imprimir(0, raiz);
    printf("\n\n\n\nRemover nós 40, 10, 30 e balancear: \n");
    
    raiz = removerAVL(40, raiz);
    raiz = removerAVL(10, raiz);
    raiz = removerAVL(60, raiz);

    imprimir(0, raiz);
    printf("\n");
}

int main(){
    
    testarAvoreAVL();
    
    return 0;
}
