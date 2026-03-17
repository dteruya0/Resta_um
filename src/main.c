#include "../includes/restaum.h"

static void preencher_matriz(int b[9][9], int linhas, int colunas)
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


void    print_matriz(int b[9][9], int h, int w)
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
    char p[31][40];
    int ip = 0;
    int matrix[9][9];


    preencher_matriz(matrix, linhas, colunas);
    resolveRestoUm(9, matrix, p, ip);

    return 0;
}