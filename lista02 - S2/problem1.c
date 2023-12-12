#include <stdio.h>
#include <stdlib.h>

int media(){
    int n, media = 0, qnt;
    printf("\nInsira a quantidade de numeros: ");
    scanf("%i", &qnt);

    int i;
    for(i = 0; i < qnt; i++){
        printf("\nInsira um valor: ");
        scanf("%i", &n);
        media += n;
    }
    return (media/qnt);
}


int main(){
    int m;
    m = media();
    printf("%i", m);
}