#include <stdio.h>
#include <stdlib.h>


//Nessa questão, temos que separar numero por numero do nosso numero inteiro passado como parametro
//o jeito mais facil de fazer isso, é pegando o resto do inteiro por 10, o que faz com que peguemos o resto da divisão do n
//por exemplo, se fizemos 7631 % 10, ficará 763,1 e o nosso programa vai armazenar com uma atribuição
//dessa operação o resto, o numero após a virgula, neste caso o numero 1
//Depois, seguimos a mesma logica quando fazemos 7631/10, que dá 763,1, mas neste caso o  programa armazena a parte inteira, 763
//e continuamos o processo até que n seja 0
int somaDeInteiro(int n){
    int soma = 0, aux;
    
    while(n > 0){
        soma += n%10;
        n = n /10; 
    }
    return soma;
}

int main(){

somaDeInteiro(7631);

}