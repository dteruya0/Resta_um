#include "../includes/restaum.h"

static void preencher_matriz(matriz, linhas, colunas)
{
    for(int i = 0; i < colunas; i++)
    {
        for(int j = 0; j < linhas; j++)
        {
            if(j == 0 || j == 8 || i == 0 || i == 8)
                b[i][j] = -1;
            else if (i == 4 && j == 4)
                b[i][j] == 0;
            else if (i >= 3 && i <= 7 && j >= 3 && j <= 7)
                b[i][j] = 1;
            else
                b[i][j] = -1;
        }
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
        backtracking();
    }
    free_matriz(matriz, linhas);
    return 0;
}