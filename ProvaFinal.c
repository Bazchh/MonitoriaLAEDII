#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// trocar pela quantidade de vertices da sua matriz/grafo
#define tamanho_matriz 2356
int min_e_max(int n, int n1);
int grau_do_maior_vertice(int **matriz);
void mostra_matriz(int **matriz);
void ler_arquivo(char *nome_arquivo, int **matriz);
int main()
{
    int maior_grau;
    int **matriz = (int **)malloc(tamanho_matriz * sizeof(int *));
    int i;
    for (i = 0; i < tamanho_matriz; i++)
        matriz[i] = (int *)malloc(tamanho_matriz * sizeof(int));
    ler_arquivo("dadosmatriz.txt", matriz);
    //   mostra_matriz(matriz);

    maior_grau = grau_do_maior_vertice(matriz);
    printf("\nO vertice com maior grau eh: %i", maior_grau);
}

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

void mostra_matriz(int **matriz)
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

int grau_do_maior_vertice(int **matriz)
{
    int i, j, maior_grau, aux = 0, vertice_com_maior_grau;
    for (i = 0; i < tamanho_matriz; i++)
    {
        for (j = 0; j < tamanho_matriz; j++)
        {
            if (matriz[i][j] == 1)
            {
                aux++;
            }
        }
        if (aux > maior_grau)
        {
            maior_grau = aux;
            vertice_com_maior_grau = i;
        }
        aux = 0;
    }
    return vertice_com_maior_grau;
}


