#include <stdio.h>
 
int main() {
    int N;
    scanf("%d", &N);
    int x[N];
    for(int i = 0; i < N; i++){
        scanf("%d", &x[i]);
    }
    int minor = x[0];
    int minorIndex = 0;
    for(int i = 1; i < N; i++){
        if(x[i] < minor){
            minor = x[i];
            minorIndex = i;
        }
    }
    printf("Menor valor: %d \n", minor);
    printf("Posicao: %d ", minorIndex);
    return 0;
}