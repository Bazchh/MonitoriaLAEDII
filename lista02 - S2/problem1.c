#include <stdio.h>
#include <stdlib.h>

//Função que calcula e retorna a media dos valores inseridos
int media(){
    int n, media = 0, qnt; //Variavel qnt armazena a quantidade de valores
    //Variavel media armazena a media
    //Variavel n serve para ler os numeros inseridos a cada scanf 
    printf("\nInsira a quantidade de numeros: ");
    scanf("%i", &qnt);

    int i;
    //Neste laço, incrementamos i de 0 até qnt - 1 e pedimo um novo numero a cada iteração
    //e o armazenamos na variavel media
    for(i = 0; i < qnt; i++){
        printf("\nInsira um valor: ");
        scanf("%i", &n);
        media += n;
    }
    //Retornando media
    return (media/qnt);
}

//Neste problema ele pede para que armazenemos valores inseridos pelo usuario e faça a media dos valores
int main(){

//Neste exemplo, eu criei uma variavel m do tipo inteira onde iremos armazenar o valor da media dos valores
//Que será retornado por uma função que faz todo o calculo
    int m;
    m = media(); //Aqui estou atribuindo o valor retornado pela função na variavel m
    printf("%i", m);
}