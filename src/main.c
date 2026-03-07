#include "../includes/restaum.h"

static void preencher_matriz(matriz, linhas, colunas)
{
    
}




int main(void)
{
    int linhas = 7;
    int colunas = 7;

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