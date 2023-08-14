#include <stdio.h>

int main (){
    char c; //Variavel do tipo caractere para armazenar valores inteiros
    int i = 0; //Index para armazenar valores inteiros e atribuir a variavel do tip char "c"
    int count = 0;//Variavel contadora para executar uma quebra de linha a cada 10 caracteres impressos

    //Laço de repetição para imprimir os caracteres com valor da tabela ASCII de 0 a 127
    do{
    c = i;   //Atribuindo valor atual do index a variavel do tipo char "c"
    printf(" %c", c);//Impressão para valor atual atribuido a variavel "c"
    count++;//Somando +1 a variavel contadora que executa a quebra de linha
    
    //Estrutura condicional que executa uma quebra de linha a cada 10 caracteres impressos
    if(count == 9){
        printf("\n");
        count = 0;//Redefinição do valor para a variavel contadora que executa a quebra de linha
    }
    i++;//Incremento do index "i" 
    }while(i <= 127); //Condição de para do laço de repetição

}