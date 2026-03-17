#include <stdio.h>
#include <stdlib.h>
#include "../includes/restaum.h"

long long passos = 0;

void moverCima(int n, int t[n][n], int linha, int coluna){
    t[linha][coluna] = 0;
    t[linha - 1][coluna] = 0;
    t[linha - 2][coluna] = 1;
}

void moverBaixo(int n, int t[n][n], int linha, int coluna){
    t[linha][coluna] = 0;
    t[linha + 1][coluna] = 0;
    t[linha + 2][coluna] = 1;
}

void moverDireita(int n, int t[n][n], int linha, int coluna){
    t[linha][coluna] = 0;
    t[linha][coluna + 1] = 0;
    t[linha][coluna + 2] = 1;
}

void moverEsquerda(int n, int t[n][n], int linha, int coluna){
    t[linha][coluna] = 0;
    t[linha][coluna - 1] = 0;
    t[linha][coluna - 2] = 1;
}

void desfazCima(int n, int t[n][n], int linha, int coluna){
    t[linha][coluna] = 1;
    t[linha - 1][coluna] = 1;
    t[linha - 2][coluna] = 0;
}

void desfazBaixo(int n, int t[n][n], int linha, int coluna){
    t[linha][coluna] = 1;
    t[linha + 1][coluna] = 1;
    t[linha + 2][coluna] = 0;
}

void desfazDireita(int n, int t[n][n], int linha, int coluna){
    t[linha][coluna] = 1;
    t[linha][coluna + 1] = 1;
    t[linha][coluna + 2] = 0;
}

void desfazEsquerda(int n, int t[n][n], int linha, int coluna){
    t[linha][coluna] = 1;
    t[linha][coluna - 1] = 1;
    t[linha][coluna - 2] = 0;
}

int resolveRestoUm(int n,int t[n][n], char p[31][40], int ip)
{

    // Artificio Pra Mostrar Que O Programa Não Travou.

    passos ++;

    if (passos % 100000 == 0) {
        printf("\rResolvendo");
        if (ip % 4 == 1) printf(".   ");
        else if (ip % 4 == 2) printf("..  ");
        else if (ip % 4 == 3) printf("... ");
        else printf("    ");
        fflush(stdout);
    }

    // Caso Base, 31 passos e só uma peça no centro.

    int centro = (n - 1) / 2;

    if(ip == 31){
    if (t[centro][centro]){
        printf("\n");
        for(int i = 0; i < 31; i++){
            printf("%s\n", p[i]);
        }
        return 1;
    }
    return 0; // Volta pra ultima chamada
}

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

            // Pra Cima!!    Origem         Apagado             Destino
            if(i >= 2 && t[i][j] == 1 && t[i - 1][j] == 1 && t[i - 2][j] == 0){
                moverCima(n, t, i, j);
                sprintf(p[ip], "Linha %d, Coluna %d CIMA", i, j);
                if (resolveRestoUm(n, t, p, ip + 1))
                    return 1;
                desfazCima(n, t, i, j);
            }

            // Pra Baixo!!        Origem          Apagado             Destino
            if(i+ 2 < n && t[i][j] == 1 && t[i + 1][j] == 1 && t[i + 2][j] == 0){
                moverBaixo(n, t, i, j);
                sprintf(p[ip], "Linha %d, Coluna %d BAIXO", i, j);
                if (resolveRestoUm(n, t, p, ip + 1))
                    return 1;
                desfazBaixo(n, t, i, j);
            }

            // Pra Direita!!      Origem          Apagado             Destino
            if(j + 2 < n && t[i][j] == 1 && t[i][j + 1] == 1 && t[i][j + 2] == 0){
                moverDireita(n, t, i, j);
                sprintf(p[ip], "Linha %d, Coluna %d DIREITA", i, j);
                if (resolveRestoUm(n, t, p, ip + 1))
                    return 1;
                desfazDireita(n, t, i, j);
            }

            //Pra Esquerda!!   Origem         Apagado             Destino
            if(j - 2 >= 0 && t[i][j] == 1 && t[i][j - 1] == 1 && t[i][j - 2] == 0){
                moverEsquerda(n, t, i, j);
                sprintf(p[ip], "Linha %d, Coluna %d ESQUERDA", i, j);
                if (resolveRestoUm(n, t, p, ip + 1))
                    return 1;
                desfazEsquerda(n, t, i, j);
            }
        }
    }
    return 0;
}
