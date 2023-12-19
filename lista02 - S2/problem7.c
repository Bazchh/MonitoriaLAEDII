#include <stdio.h>
#include <stdlib.h>

int main(){
    int qnt, i;
    i = 0;
    printf("\nInsira um numero: ");
    scanf("%i", &qnt);

    for(i = 0; i < qnt; i++){
        printf(" * ");
    }
}