#include <stdio.h>

void  insertionSort(int * array, int tamanhoArray){
    
    int copia, indice;
    
    for(int i = 1; i < tamanhoArray; i++){
        copia = array[i]; 
        indice = i;  
        
        while(indice > 0 && array[indice-1] > copia){
            array[indice] = array[indice-1];
            indice--; 
        }
        
        array[indice] = copia;
    }
}

void imprimeArray(int * array, int tamanhoArray){
    
    for(int i=0; i<tamanhoArray; i++){
        printf("%d ",  array[i]);
    }
    printf("\n");
}

int main()
{
    int array[] = {5, 7, 1, 3, 9};
    
    
    printf("Vetor original: ");
    imprimeArray(array, 5);
    
    printf("Vetor ordenado: ");
    insertionSort(array, 5);
    imprimeArray(array, 5);
    
    return 0;
}

