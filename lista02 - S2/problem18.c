#include <stdio.h>
#include <stdlib.h>
//Nessa questão, um numero se diz perfeito quando os seus fatores (numeros pelo qual o dividem) somados, resultam nesse numero
//nesse caso, seguindo a logica, devemos verificar quais os fatores desse numero, retirando ele mesmo, de 1 até ele ou até a metade dele
int quadradoPerfeito(int n){
    int soma = 0, i;
    for (i = 1; i < n; i++){
        if( n % i == 0){
            soma+= i;
        }
    }

    if(soma == n){
        return soma;
    } 
}

int main(){
int n, r;

printf("\nInsira um número: ");
scanf("%i", &n);

r = quadradoPerfeito(n);

if(r == n){
    printf("\n%i é um número perfeito", n);
} else {
     printf("\n%i não é um número perfeito", n);
}


}