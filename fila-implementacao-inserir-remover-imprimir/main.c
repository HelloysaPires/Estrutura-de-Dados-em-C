#include <stdio.h>
#include "fila.h"

int main()
{
    struct no *fila = NULL;
    int dado;
    
    for(int i=0; i<4; i++){
        printf("Insira o dado: ");
        scanf("%d", &dado);
        inserirNaFila(dado, &fila);
    }
    
    printf("\n");
    imprimirFila(&fila);
    
    removerDaFila(&fila);
    
    printf("\n");
    imprimirFila(&fila);
    

    return 0;
}
