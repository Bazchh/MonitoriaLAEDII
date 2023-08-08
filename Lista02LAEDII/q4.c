#include <stdio.h>
#include <stdlib.h>

int isPerfect(int n){
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

r = isPerfect(n);

if(r == n){
    printf("\n%i é um número perfeito", n);
} else {
     printf("\n%i não é um número perfeito", n);
}


}