#include "../includes/restaum.h"

void    free_matriz(int **matriz, int linhas)
{
    for(int i = 0; i < linhas; i++)
    {
        if(matriz[i])
            free(matriz[i]);
    }
    if (matriz)
        free(matriz);
}