#include <stdio.h>
#include <stdlib.h>


int main(){
    
    int i;
    printf("CELSIUS \tFarenheit\n"); //OBS: /t serve para tabulação
    //Basicamente nesta questão, devemos utilizar o metodo de conversão de Farenheit para Celsisu para
    //Cada valor do laço com o i iniciando em 30 e terminando em 50
    for(i = 30; i <= 50; i++){
        printf(" %i   \t  = \t   %i\n",i, (i+32));
    }
    
}