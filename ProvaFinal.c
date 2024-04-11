#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//trocar pela quantidade de vertices da sua matriz/grafo
#define tamanho_matriz 2356
void ler_arquivo(char *nome_arquivo, int **matriz)
{
    FILE *arch;
    char linha[tamanho_matriz];
    char *token;
    int i = 0, j = 0;
    arch = fopen(nome_arquivo, "r");
    while (fgets(linha, tamanho_matriz, arch))
    {
        token = strtok(linha, " ");
        j = 0;
        while (j < tamanho_matriz)
        {

            matriz[i][j] = atoi(token);
            token = strtok(NULL, " ");
            j++;
        }
        i++;
        if (i >= tamanho_matriz)
        {
            break;
        }
    }
    fclose(arch);
}

void mostraMatriz(int **matriz)
{
    int i, j;

    for (i = 0; i < tamanho_matriz; i++)
    {
        for (j = 0; j < tamanho_matriz; j++)
        {

            printf(" %i ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main()
{

    int **matriz = (int **)malloc(tamanho_matriz * sizeof(int *));
    int i;
    for (i = 0; i < tamanho_matriz; i++)
        matriz[i] = (int *)malloc(tamanho_matriz * sizeof(int));
    ler_arquivo("dadosmatriz.txt", matriz);
    mostraMatriz(matriz);
}