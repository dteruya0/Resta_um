#ifndef RESTAUM_H
#define RESTAUM_H
/*
Nome: Calvin Altino Santos
RA: 10723926
Nome: Diego Teruya
RA: 10723404
Nome: Gabriel Goes Taka
RA: 10723533
Nome: João Vitor Firmino de Almeida
RA: 10723778
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void    print_matriz(int b[9][9], int h, int w);
int resolveRestoUm(int n,int t[n][n], char p[31][40], int ip);
void moverCima(int n, int t[n][n], int linha, int coluna);
void moverBaixo(int n, int t[n][n], int linha, int coluna);
void moverDireita(int n, int t[n][n], int linha, int coluna);
void moverEsquerda(int n, int t[n][n], int linha, int coluna);



#endif