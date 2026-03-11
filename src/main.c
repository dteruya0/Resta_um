#include "../includes/restaum.h"

static void preencher_matriz(int **b, int linhas, int colunas)
{
    for(int i = 0; i < colunas; i++)
    {
        for(int j = 0; j < linhas; j++)
        {
            if(j == 0 || j == 8 || i == 0 || i == 8)
                b[i][j] = -1;
            else if (i == 4 && j == 4)
                b[i][j] = 0;
            else if ((i >= 3 && i <= 5) || (j >= 3 && j <= 5))
                b[i][j] = 1;
            else
                b[i][j] = -1;
        }
    }
}


void    print_matriz(int **b, int h, int w)
{
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            if(b[i][j] == -1)
                printf(" # ");
            else
                printf(" %d ", b[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    int linhas = 9;
    int colunas = 9;

    int **matriz = criando_matriz(linhas, colunas);
    if (!matriz)
        free_matriz(matriz, linhas);
    else
    {
        preencher_matriz(matriz, linhas, colunas);
        print_matriz(matriz, linhas, colunas);
    }
    free_matriz(matriz, linhas);
    return 0;
}