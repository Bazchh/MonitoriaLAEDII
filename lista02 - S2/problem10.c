#include <stdio.h>
#include <stdlib.h>
//Nessa questão, trabalhamos com a lei de formação de sequencias, primeiro devemos observar e tentar
//identificar um padrão na sequencia com base no primeiro termo e nos seguintes
//em relação a sequencia, consideramos sempre com indexação a partir de 0, ou seja, n - 1

int main(){
    int i, qnt; //De forma dinamica, podemos inserir a quantidade de numeros da sequencia
    float seq = 0;//Vai armazenar o valor da sequencia num todo
    float n; //Vai armazenar os numeros da sequencia
    printf("\nInsira a quantidade de termos da sequencia: ");
    scanf("%i", &qnt);
    for(i = 0; i < qnt; i++){
     n = 1.0/(2*i+1); //Aqui calculamos os termos da sequencia, como somente o numero de baixo está mudando fica mais facil determinar 
     //uma formula para essa sequencia

     //Para concluir, o sinal dos valores se alternam, se verificarmos bem, quando o indice é divisivel por 2
     //o numero é positivo, caso contrario, é negativo
     if(i % 2 == 0){
        seq += (n);
        printf("+ %.1f ", n);
     }  else {
        seq -= (n);
        printf("- %.1f ", n);
        
     }
    }
    seq *= 4;

    printf("\nResultado: %.1f", seq);
}