
/* 
 * File:   main.cpp
 * Author: Santiago
 *
 * Created on 19 de junho de 2024, 16:38
 */

#include <cstdlib>
#include <iostream>
#include "operacoes.h" // biblioteca criada

using namespace std;

/*
 * Projeto feito para operar matrizes, ultilizando funções em bibliotecas.h
 */


using namespace std;

int main(int argc, char const *argv[]){
    //Definindo matrize -------------------
    float m1[4][4] = //matriz 1
    {
        {1, 2, 3, 4},
        {4, 5, 6, 9},
        {7, 6, 5, 4},
        {4, 9, 1, 0}
    };

    float transposta[4][4]; // matriz transposta

    float m3[4][4]; // resultado soma
    float m4[4][4]; // resultado multiplicação
    //---------------------------------------------

    //Exibindo matriz -----------------------------
    cout << "Matriz 1:" << endl;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            cout << m1[i][j] << " ";
        }
        cout << endl;
    }

    //fazendo operações-------------------------------------

    transporMat (m1, transposta);
    somaTransposta(m1, transposta, m3);
    multTransposta(m1, transposta, m4);

    //---------------------------------------------------------------
    
    
    int opcao; // variavel de seleção
    while (opcao != 0){ //repetir menu ate aperta 0
        //menu de operações com a matriz 
        cout << "Escolha uma opção:" << endl;
        cout << "1 - Matriz Transposta" << endl;
        cout << "2 - Somar com a trasposta" << endl;
        cout << "3 - Multiplicação com a trasposta" << endl;
        cout << "4 - Valor medio da Matriz" << endl;
        cout << "0 - Sair" << endl;
        cin >> opcao; 
        //switch das operações
        switch (opcao){
            case 1:
                cout << "Matriz transposta:" << endl;
                for (int i = 0; i < 4; i++){
                    for (int j = 0; j < 4; j++){
                        cout << transposta[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << "Digite 0 para sair ou outro numero para voltar ao menu: ";
                cin >> opcao;
                break;
            case 2:
                cout << "Soma com a transposta:" << endl;
                for (int i = 0; i < 4; i++){
                    for (int j = 0; j < 4; j++){
                        cout << m3[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << "Digite 0 para sair ou outro numero para voltar ao menu: ";
                cin >> opcao;
                break;
            case 3:
                cout << "Multiplicação com a transposta:" << endl;
                for (int i = 0; i < 4; i++){
                    for (int j = 0; j < 4; j++){
                        cout << m4[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << endl;
                cout << "Digite 0 para sair ou outro numero para voltar ao menu: ";
                cin >> opcao;
                break;
            case 4:
                cout << "Valor medio da Matriz: ";
                printf ("%0.2f", valorMedio(m1));
                cout << "Digite 0 para sair ou outro numero para voltar ao menu: ";
                cin >> opcao;
                break;
            case 0:
                break;

        }
    }

    return 0;
}



