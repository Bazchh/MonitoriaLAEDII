#include <stdio.h>
#include <stdlib.h>


int main(){
    int n = 5, i, j, fat;
    //Variavel n indica até qual numero devemos calcular o fatorial
    //fat armazena o calculo do fatorial de um numero qualquer
    
    for(i = 1; i <= n; i++){
        fat = 1; 
        //Aqui poderia ser feito incrementando também o laço, fiz dessa forma devido a estetica
        // ex 5! = 5 * 4 * 3 * 2 * 1
        //Este laço inicia o j no i que é o numero em questão a qual estamos calculando o fatorial
        //Então eu decremento ele enquanto for maior que 1 e a cada decremento eu faço o calculo do fatorial
        for(j = i; j > 1; j--){
            fat *= j;
        }
        printf("\n%i", fat);
         }
}