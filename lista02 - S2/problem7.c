#include <stdio.h>
#include <stdlib.h>

int main()
{
    int qnt[5], i, j;
    i = 0;

    for (j = 0; j < 5; j++)
    {
        printf("\nInsira um numero: ");
        scanf("%i", &qnt[j]);
    }
    for (j = 0; j < 5; j++)
    {
       for (i = 0; i < qnt[j]; i++)
        {
            printf(" * ");
        }
        printf("\n");
    }
        
    
}