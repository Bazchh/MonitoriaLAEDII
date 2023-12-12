#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int soma = 0, quadrados = 0, cubo = 0;
    int i, n;
    scanf("%i", &n);
    for(i = 1; i < n; i++){
        soma+= i;
        quadrados += pow(2,i);
        cubo += pow(3,i); 
    }
    printf("Soma: %i", soma);
    printf("\nQuadrados: %i", quadrados);
    printf("\nCubos: %i",cubo);
}