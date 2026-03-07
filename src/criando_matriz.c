#include "../includes/restaum.h"

int **criando_matriz(int linhas, int colunas)
{
    int **matriz = calloc(linhas, sizeof(int *));
    if(!matriz)
        return NULL;
    for(int i = 0; i < linhas; i++)
    {
        matriz[i] = calloc(colunas, sizeof(int));
        if(!matriz[i])
            return NULL;
    }
    return matriz;
}