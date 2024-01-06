#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;
    //Neste programa, basicamente devemos verificar se o resto de divisão de um numero por 7 é zero
    //em caso verdadeiro, ele é multiplo de 7
    for(i = 1; i <= 100; i++){
        if(i % 7 == 0){
            printf("%i", i);
        }
    }
}