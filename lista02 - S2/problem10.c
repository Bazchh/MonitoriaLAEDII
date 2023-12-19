#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, qnt;
    float seq = 0;
    float n;
    printf("\nInsira a quantidade de termos da sequencia: ");
    scanf("%i", &qnt);
    for(i = 0; i < qnt; i++){
     n = 1.0/(2*i+1);
     if(i % 2 == 0){
        seq += (n);
        printf("+ %.1f ", n);
     }  else {
        seq -= (n);
        printf("- %.1f ", n);
        
     }
    }
    seq *= 4;

    printf("\nResultado: %.1f", seq);
}