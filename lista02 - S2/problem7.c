#include <stdio.h>
#include <stdlib.h>

int main()
{
    int qnt[5], i, j;
    i = 0;
    //Neste problema, eu resolvi armazenar os valores para cada linha que vamos ter 
    //de asteriscos em um vetor
    for (j = 0; j < 5; j++)
    {
        printf("\nInsira um numero: ");
        scanf("%i", &qnt[j]);
    }
    //Depois disso, vou ler cada valor no vetor
    for (j = 0; j < 5; j++)
    {
        //Para cada valor lido, vou realizar outro laço com o valor dentro daquela posição do vetor e 
        //a cada incremento eu coloca um asterisco na linha, quando acabo, dou uma quebra de linha e vou para
        //a proxima posição do vetor com o valor seguinte
       for (i = 0; i < qnt[j]; i++)
        {
            printf(" * ");
        }
        printf("\n");
    }
        
    
}