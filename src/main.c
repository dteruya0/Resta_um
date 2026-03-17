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


void    decodifica_matriz(int b[9][9], int h, int w, char **p)
{
    int movex = atoi(p[k][6]);
    int movey = atoi(p[k][16]);
    char dir[20];
    while (int k = 0; k < 31; k++)
    {
        movex = atoi(p[k][6]);
        movey = atoi(p[k][16]);
        strcopy(dir, &p[k][18]);
        if (strcmp(dir, "BAIXO"))
        {
            b[movex + 1][movey] = 0;
            print_matriz(b, 9, 9);
        }
        else if (strcmp(dir, "DIREITA"))
        {
            b[movex][movey + 2] = 0;
            print_matriz;
        }
        else if(strcmpr(dir, "ESQUERDA"))
        {
            b[movex]b[movey - 2] = 0;
        }
    }
}

int main(void)
{
    int linhas = 9;
    int colunas = 9;
    char p[31][40];
    char **banana;
    int ip = 0;
    int matrix[9][9];


    preencher_matriz(matrix, linhas, colunas);
    banana = resolveRestoUm(9, matrix, p, ip);
    print_matriz(matrix, linhas, colunas, banana);

    return 0;
}