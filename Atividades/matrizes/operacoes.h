/*
 * Biblioteca para operações com matrizes
 */

/* 
 * File:   operacoes.h
 * Author: Santiago
 *
 * Created on 19 de junho de 2024, 16:39
 */


#ifndef OPERACOES_H
#define OPERACOES_H

//Função para encontrar a transposta da matriz estatica 4x4
void transporMat(float matriz[4][4], float transposta[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            transposta[i][j] = matriz[j][i];
        }
    }
}

//Função para somar com a matriz transposta
void somaTransposta(float matriz[4][4], float transposta[4][4], float resultado[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            resultado[i][j] = matriz[i][j] + transposta[i][j];
        }
    }
}

//Função para multiplicar com a transposta
void multTransposta(float matriz[4][4], float transposta[4][4], float resultado[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                resultado[i][j] += matriz[i][k] * transposta[k][j];
            }
        }
    }
}

// Função para calcular o valor médio dos valores da primeira matriz.
float valorMedio(float matriz[4][4]) {
    float soma = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            soma += matriz[i][j];
        }
    }
    return soma / 16.0;
}

#endif

