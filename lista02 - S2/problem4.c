#include <stdio.h>
#include <stdlib.h>
//Neste problema, inicialmente sabemos que um numero é primo se só pode ser divido por 1 e por ele mesmo
//Dada estas circunstancias, pensemos o seguinte: o que acontece se dividirmos um numero qualquer pela sua metade superior ou entre o numero e acima da sua metade?
//Por exemplo, se dividirmos 6 por 4, teriamos 1,5. Dado nossa condição de numero primo, podemos chegar a mais uma conclusão neste programa
//Neste programa, teremos que percorrer de 1 até o numero a qual estamos verificando se é ou não primo
//Mas se o numero verificado não é divisivel por nenhum numero inteiro entre 1 e sua metade, isso significa que ele é um numero primo
//Então em termos de melhoria e performance do programa, só precisamos verificar a condição de primo até a metade do numero em questão 
int main(){
    int i, j, count; //Variavel i e j para percorrermos os laços de repetição
    //A variavel count serve para verificar se um numero é ou nao um numero primo
    //Iniciamos ele com 1. Caso entre 2 e a metade do numero verificado haja algum numero
    //Que consegue dividi-lo, mudamos o count para 0, indicando que aquele numero não é primo
    //Caso o valor não seja mudado até o fim da verificação, o numero é sim um numero primo

    for(i = 1; i < 100; i++){
        count = 1;
        //Laço que verifica se um numero qualquer entre 1 e 100 é primo
        for(j = 2; j <= i / 2; j++){
           //Se i for divisivel por j, então ele não é um numero primo, mudamos o valor de count
            if(i % j == 0){
                count = 0;
                break;
            }

        }

    if(count == 1){
        printf("\t%i", i);
    }
        
    }
}