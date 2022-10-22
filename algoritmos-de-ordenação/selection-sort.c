#include <stdio.h>

void selectionSort(int * array, int tamanhoArray){
    int menor, copia;
    
   for(int i=0; i<tamanhoArray-1; i++){
       menor = i;
       for(int j=i; j<tamanhoArray; j++){
           if(array[j] < array[menor]){
               menor = j;
           }
       }
       
       copia = array[menor];
       array[menor] = array[i];
       array[i] = copia;
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
    selectionSort(array, 5);
    imprimeArray(array, 5);
    
    return 0;
}

