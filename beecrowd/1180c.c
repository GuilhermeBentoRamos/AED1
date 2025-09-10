#include<stdio.h>
#include<stdlib.h>

int main(){
    int *x;
    int N;
    scanf("%d", &N);
    x = (int *) malloc(N * sizeof(int));
    if(x == NULL)return 1;
    int *curr, *minor;
    scanf("%d", &x[0]);
    curr = &x[0];
    minor = curr;
    for(int i = 1; i < N; i++){
        curr = &x[i];
        scanf("%d", curr);
        minor = (*curr < *minor) ? curr : minor;
    }
    printf("Menor valor: %d\n", *minor);
    int minorIndex = minor - x;
    printf("Posicao: %d\n", minorIndex);
    free(x);
}