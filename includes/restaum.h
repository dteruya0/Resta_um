#ifndef RESTAUM_H
#define RESTAUM_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int **criando_matriz(int b, int a);
void    print_matriz(int b[9][9], int h, int w);
int resolveRestoUm(int n,int t[n][n], char p[31][40], int ip);
void moverCima(int n, int t[n][n], int linha, int coluna);
void moverBaixo(int n, int t[n][n], int linha, int coluna);
void moverDireita(int n, int t[n][n], int linha, int coluna);
void moverEsquerda(int n, int t[n][n], int linha, int coluna);



#endif