#include<stdio.h>
#include<stdlib.h>

int main(){
    int *vetor;
    int n = 10; //tamanho do vetor
    vetor = (int *) malloc(n * sizeof(int));
    for(int i = 0; i < 10; i++){
        vetor[i] = i * 10;
        printf("%d, ", vetor[i]);
    }
    free(vetor);
    return 0;
}