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

void printMatrizArquivo(FILE *f, int n, int tab[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (tab[i][j] == -1)
                fprintf(f, "# ");
            else
                fprintf(f, "%d ", tab[i][j]);
        }
        fprintf(f, "\n");
    }
    fprintf(f, "\n");
}


void decodifica_matriz(int b[9][9], char p[31][40])
{
    FILE *f = fopen("saida.txt", "w");

    if (!f)
    {
        printf("Erro ao abrir arquivo\n");
        return;
    }
    printMatrizArquivo(f, 9, b);
    int movex, movey;
    char dir[20];

    for (int k = 0; k < 31; k++)
    {
        sscanf(p[k], "Linha %d, Coluna %d %s", &movex, &movey, dir);

        if (strcmp(dir, "BAIXO") == 0)
            moverBaixo(9, b, movex, movey);
        else if (strcmp(dir, "DIREITA") == 0)
            moverDireita(9, b, movex, movey);
        else if (strcmp(dir, "ESQUERDA") == 0)
            moverEsquerda(9, b, movex, movey);
        else if (strcmp(dir, "CIMA") == 0)
            moverCima(9, b, movex, movey);

        printMatrizArquivo(f, 9, b);
    }
    fclose(f);
}

int main(void)
{
    char p[31][40];
    int matrix[9][9];
    int matrix_original[9][9];


    preencher_matriz(matrix, 9, 9);
    if (resolveRestoUm(9, matrix, p, 0))
    {
        preencher_matriz(matrix_original, 9, 9);
        decodifica_matriz(matrix_original, p);
    }
    else
        printf("Sem solução\n");

    return 0;
}