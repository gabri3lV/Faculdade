/*
Atividade 7 - AEDS I | Operações com Matrizes
Aluno: Gabriel Vilela Araújo
R.A: 2023.2.08.001
Descrição: O programa tem como objetivo realizar operações com matrizes, onde o usuário escolhe
a operação que deseja realizar. As operações disponíveis são: soma, transposta, multiplicação e média
dos valores da primeira matriz. As matrizes são geradas aleatoriamente com valores inteiros de 0 a x, onde x é
o valor inserido pelo usuário. 
*/

#include <cstdlib>
#include <iostream>
#include "funcoes.h"
using namespace std;

int linha1, linha2, linha3 = 0;
int coluna1, coluna2, coluna3 = 0;
int escolha = 0;
int intervalo1, intervalo2 = 0;
int retorno;
TMatriz m1;
TMatriz m2;
TMatriz m3;
char opcao;

int main() {
    // Pedindo a dimensão das matrizes e o intervalo de valores
    cout << "Insira o número de linhas da primeira matriz" << endl;
    cin >> linha1;
    cout << "Insira o número de colunas da primeira matriz" << endl;
    cin >> coluna1;
    cout << "Insira o número de linhas da segunda matriz" << endl;
    cin >> linha2;
    cout << "Insira o número de colunas da segunda matriz" << endl;
    cin >> coluna2;
    cout << "Insira o limite máximo do intervalo de valores de 0 a x da primeira matriz" << endl;
    cin >> intervalo1;
    cout << "Insira o limite máximo do intervalo de valores de 0 a x da segunda matriz" << endl;
    cin >> intervalo2;
    
    // Chamando a função para gerar as matrizes antes de entrar no menu
    geramatrizes(m1, linha1, coluna1, m2, linha2, coluna2, intervalo1, intervalo2);
    cout << "Matrizes geradas!" << endl;
    cout << "Matriz 1" << endl;
    printamatriz(m1, &linha1, &coluna1);
    cout << "---------------------------" << endl;
    cout << "Matriz 2" << endl;
    printamatriz(m2, &linha2, &coluna2);
    
    do {
        // Menu para o usuário escolher a operação
        cout << "------------------------------------------------------------\n";
        cout << "\tESCOLHA UMA OPÇÃO" << endl;
        cout << "'a' - SOMA DAS DUAS MATRIZES" << endl;
        cout << "'b' - MATRIZ TRANSPOSTA" << endl; 
        cout << "'c' - MULTIPLICAÇÃO DAS DUAS MATRIZES" << endl;
        cout << "'d' - MÉDIA DOS NÚMEROS DA PRIMEIRA MATRIZ" << endl;
        cout << "'s' - SAIR DO MENU" << endl;
        cout << "------------------------------------------------------------\n";
        cin >> opcao;
        
        switch(opcao){
            case 'a': 
                // Soma
                cout << "teste" << endl;
                retorno = soma(m1, linha1, coluna1, m2, linha2, coluna2, m3, &linha3, &coluna3);
                cout << "passou do retorno" << endl;
                if(retorno == 1){
                    cout << "É impossível realizar a soma dessas matrizes! Escolha as dimensões novamente." << endl;
                }
                printamatriz(m3, &linha3, &coluna3);
                break;
            case 'b': 
                // Transposta
                cout << "Matriz transposta!" << endl;
                cout << "Informe qual matriz você deseja a transposta. Digite '1' ou '2'" << endl;
                cin >> escolha;
                transposta(m1, linha1, coluna1, m2, linha2, coluna2, m3, &linha3, &coluna3, escolha);
                printamatriz(m3, &linha3, &coluna3);
                break;
            case 'c': 
                // Multiplicacao
                cout << "Multiplicação das matrizes!" << endl;
                retorno = multiplicacao(m1, linha1, coluna1, m2, linha2, coluna2, m3, &linha3, &coluna3);
                if(retorno == 1){
                    cout << "É impossível realizar a multiplicação dessas matrizes! Escolha as dimensões novamente." << endl;
                }
                printamatriz(m3, &linha3, &coluna3);
                break;
            case 'd': 
                // Media da Matriz 1
                cout << "Média dos valores da matriz 1!" << endl;
                cout << mediamatriz1(m1, linha1, coluna1) << endl;
                break;
        }
    }while(opcao != 's');
    
    return 0;
}

