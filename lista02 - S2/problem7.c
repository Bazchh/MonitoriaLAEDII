#include <stdio.h>
#include <stdlib.h>

int main()
{
    int qnt, i, j;
    i = 0;

    for (j = 0; j < 5; j++)
    {
        printf("\nInsira um numero: ");
        scanf("%i", &qnt);
        for (i = 0; i < qnt; i++)
        {
            printf(" * ");
        }
    }
}