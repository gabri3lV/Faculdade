#include <cstdlib>
#include <iostream>
#include <time.h>
#include "funcoes.h"
using namespace std;

int transposta(TMatriz m1, int nl1, int nc1, TMatriz m2, int nl2, int nc2, TMatriz m3, int *nl3, int *nc3, int escolha){
    // Escolha do usuário
    if(escolha == 1){ // Transposta da matriz 1
        for(int i = 0; i < nl1; i++){
            for(int j = 0; j < nc1; j++){
                m3[i][j] = m1[j][i];
            }
        } 
    } else { // Transposta da matriz 2
        for(int i = 0; i < nl1; i++){
            for(int j = 0; j < nc1; j++){
                m3[i][j] = m2[j][i];
            }
        }
    }
    return 0;
}

int soma(TMatriz m1, int nl1, int nc1, TMatriz m2, int nl2, int nc2, TMatriz m3, int *nl3, int *nc3){
    // Verificando se é possível realizar a soma
    if(nl1 == nl2 && nc1 == nc2){
        for(int i = 0; i < nl1; i++){
            for(int j = 0; j < nc1; j++){
                m3[i][j] = m1[i][j] + m2[i][j];
            }
        }
        *nl3 = nl1;
        *nc3 = nc1;
    } else {
        return 1; // Erro! Não é possível realizar a soma
    }
    return 0;
}

int multiplicacao(TMatriz m1, int nl1, int nc1, TMatriz m2, int nl2, int nc2, TMatriz m3, int *nl3, int *nc3){
    // Verificando se é possível realizar a multiplicação
    if(nl1 == nc2 && nc1 == nl2){
        for(int i = 0; i < nl1; i++){
            for(int j = 0; j < nc2; j++){
                m3[i][j] = 0;
                for(int k = 0; k < nc1; k++){
                    m3[i][j] += m1[i][k] * m2[k][j];
                }
            }
        }
        // Atualizando as dimensões da matriz resultante
        *nl3 = nl1;
        *nc3 = nc2;
    } else {
        return 1;
    }
    return 0;
}

double mediamatriz1(TMatriz m1, int nl1, int nc1){
    int soma = 0;
    int div = nl1 * nc1;
    for(int i = 0; i < nl1; i++){
        for(int j = 0; j < nc1; j++){
            soma += m1[i][j];
        }
    }
    int media = soma/div;
    return media;
}

int printamatriz(TMatriz m, int *nl, int *nc){
    // Loop para printar a matriz
    for(int i = 0; i < *nl; i++){
        for(int j = 0; j < *nc; j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

void geramatrizes(TMatriz m1, int nl1, int nc1, TMatriz m2, int nl2, int nc2, int intervalo1, int intervalo2){

    srand(time(NULL));
    // Gerando a matriz1 até o intervalo que o usuário deseja
    for(int i = 0; i < nl1; i++){
        for(int j = 0; j < nc1; j++){
            m1[i][j] = rand() % (intervalo1 + 1);
        }
    }
    // Gerando a matriz2 até o intervalo que o usuário deseja
    for(int i = 0; i < nl2; i++){
        for(int j = 0; j < nc2; j++){
            m2[i][j] = rand() % (intervalo2 + 1);
        }
    }
}