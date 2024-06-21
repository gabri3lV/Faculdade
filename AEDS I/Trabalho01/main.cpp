/*
--- TRABALHO DE AEDS 1 ---
Nome: Gabriel Vilela Araújo
Matrícula: 2023.2.08.001
Objetivo: 
Desenvolver um programa em C++ para gerenciar um banco de dados de veículos, com funcionalidades para inclusão, busca e exclusão de registros.
O programa deve permitir a busca de veículos por placa, tipo, câmbio e faixa de valor, além de possibilitar a exclusão de veículos pelo usuário.
Deve também gerar relatórios que incluam:
- A quantidade e porcentagem de veículos de cada tipo (SUV, Hatch, Pickup, Sedan).
- A quantidade e porcentagem de veículos por tipo de combustível (Gasolina, Flex, Diesel).
- O veículo mais barato com motor 1.0.
- O veículo mais caro com direção hidráulica.
- A quantidade e média de quilometragem de veículos com mais de cinco anos de uso.
Este projeto tem como finalidade aplicar conceitos de estruturas de dados e manipulação de arquivos, aprimorando habilidades de programação em C++.
*/

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

typedef struct {
    string modelo;
    string marca;
    string tipo;
    string combustivel;
    string cambio;
    string direcao;
    string cor;
    string placa;
    string portas;
    string potencia;
    int ano;
    int km;
    int valor;
    bool valido; 
} Veiculo;

const int TAM = 1300;

int main(){
    int i = 0;
    int qtd = 0;
    Veiculo banco[TAM];
    string modelo, placa, valor, cambio, tipo, escolha, placa2;
    float SUV, HATCH, PICKUP, SEDAN, GAS, FLEX, DIES = 0; 
    SUV = HATCH = PICKUP = SEDAN = GAS = FLEX = DIES = 0;
    float financiamento, seguro;
    int val_min, val_max, qtdanos;
    val_min = val_max = qtdanos = 0;
    float mediakm, km;
    mediakm = km = 0;
    char opcao;
    int aux;
    aux = 0;
    
    // Leitura 
    ifstream leitura("BD_veiculos.txt");
    if (!leitura.is_open()) {
        cout << "Erro! Arquivo não existe" << endl;
        return 1;
    }
    
    leitura >> modelo;
    while(modelo != "FIM"){
        banco[i].modelo = modelo;
        leitura >> banco[i].marca;
        leitura >> banco[i].tipo;
        leitura >> banco[i].ano;
        leitura >> banco[i].km;
        leitura >> banco[i].potencia;
        leitura >> banco[i].combustivel;
        leitura >> banco[i].cambio;
        leitura >> banco[i].direcao;
        leitura >> banco[i].cor;
        leitura >> banco[i].portas;
        leitura >> banco[i].placa;
        leitura >> banco[i].valor;
        banco[i].valido = true;
        qtd++;
        i++;
        leitura >> modelo;
    }
    leitura.close();
    do {
        // Menu para o usuário escolher a operação
        cout << "------------------------------------------------------------\n";
        cout << "\tESCOLHA UMA OPÇÃO" << endl;
        cout << "'a' - INCLUIR VEÍCULO" << endl;
        cout << "'b' - BUSCAR VEÍCULO PELA PLACA E, SE QUISER, EXCLUIR" << endl; 
        cout << "'c' - BUSCAR VEÍCULO PELO TIPO" << endl;
        cout << "'d' - BUSCAR VEÍCULO PELO CÂMBIO" << endl;
        cout << "'e' - BUSCAR VEÍCULO POR UMA FAIXA DE VALOR" << endl;
        cout << "'f' - RELATÓRIO DO BANCO DE DADOS" << endl;
        cout << "'s' - SAIR DO MENU" << endl;
        cout << "------------------------------------------------------------\n";
        cin >> opcao;
        
        switch(opcao){
            case 'a': // Inclusão de veículos
                if (qtd < TAM) {
                    int i = 0;
                    while( i < qtd && banco[i].valido != false) {
                        i++;
                    } 
                    cout << "Incluindo veículo" << endl;
                    cout << "Digite o modelo do veículo" << endl;
                    cin >> banco[i].modelo;
                    cout << "Digite a marca do veículo" << endl;
                    cin >> banco[i].marca;
                    cout << "Digite o tipo do veículo" << endl;
                    cin >> banco[i].tipo;
                    cout << "Digite o ano do veículo" << endl;
                    cin >> banco[i].ano;
                    cout << "Digite quilometragem do veículo" << endl;
                    cin >> banco[i].km;
                    cout << "Digite a potência do motor do veículo" << endl;
                    cin >> banco[i].potencia;
                    cout << "Digite o combustível utilizado pelo veículo" << endl;
                    cin >> banco[i].combustivel;
                    cout << "Digite o câmbio do veículo" << endl;
                    cin >> banco[i].cambio;
                    cout << "Digite a direção do veículo" << endl;
                    cin >> banco[i].direcao;
                    cout << "Digite a cor do veículo" << endl;
                    cin >> banco[i].cor;
                    cout << "Digite a quantidade de portas que o veículo possui" << endl;
                    cin >> banco[i].portas;
                    cout << "Digite a placa do veículo" << endl;
                    cin >> banco[i].placa;
                    cout << "Digite o valor do veículo" << endl;
                    cin >> banco[i].valor;
                    banco[i].valido = true;
                    cout << "Veículo inserido com sucesso!" << endl;
                    if(i == qtd){
                        qtd++;
                    }
                } else {
                    cout << "O banco de dados está cheio." << endl;
                }
            break;
            case 'b': // Busca pela placa com opção de remoção
                cout << "Buscando pela placa do veículo" << endl;
                cout << "Digite a placa desejada" << endl;
                cin >> placa;
                for(i = 0; i < TAM; i++){
                    if(banco[i].placa == placa){
                        cout << "Placa encontrada!" << endl;
                        cout << "Informações do veículo: " << endl;
                        cout << "Modelo: " << banco[i].modelo << endl;
                        cout << "Marca: " << banco[i].marca << endl;
                        cout << "Tipo: " << banco[i].tipo << endl;
                        cout << "Ano: " << banco[i].ano << endl;
                        cout << "Quilometragem: " << banco[i].km << endl;
                        cout << "Potência: " << banco[i].potencia << endl;
                        cout << "Combustível: " << banco[i].combustivel << endl;
                        cout << "Câmbio: " << banco[i].cambio << endl;
                        cout << "Direção: " << banco[i].direcao << endl;
                        cout << "Cor: " << banco[i].cor << endl;
                        cout << "Portas: " << banco[i].portas << endl;
                        cout << "Placa: " << banco[i].placa << endl;
                        cout << "Valor: " << banco[i].valor << endl;
                        aux = i;
                    }
                }
                cout << "Deseja remover o veículo? SIM/NAO" << endl;
                cin >> escolha;
                if(escolha == "SIM"){
                    banco[aux].valido = false;
                    cout << "Veículo removido!" << endl;
                }
                break;
            case 'c': // Busca através do tipo 
                cout << "Buscando pelo tipo do veículo" << endl;
                cout << "Digite o tipo desejado" << endl;
                cin >> tipo;
                cout << "Veículos do tipo " << tipo << ":"<< endl;
                for(i = 0; i < TAM; i++){
                    if(banco[i].tipo == tipo){
                        cout << "Modelo: " << banco[i].modelo << " / Placa: " << banco[i].placa << endl; 
                    }
                }
                break;
            case 'd': // Busca através do câmbio
                cout << "Buscando pelo câmbio do veículo" << endl;
                cout << "Digite o câmbio desejado" << endl;
                cin >> cambio;
                cout << "Veículos que possuem o câmbio " << tipo << ":"<< endl;
                for(i = 0; i < TAM; i++){
                    if(banco[i].cambio == cambio){
                        cout << "Modelo: " << banco[i].modelo << " / Placa: " << banco[i].placa << endl; 
                    }
                }
                break;
            case 'e': // Busca através da faixa de valor
                cout << "Buscando pela faixa de valor do veículo" << endl;
                cout << "Digite o valor mínimo" << endl;
                cin >> val_min;
                cout << "Digite o valor máximo" << endl;
                cin >> val_max;
                cout << "Veículos que estão na faixa de preço de " << val_min << " até " << val_max << ":" << endl;
                for(i = 0; i < TAM; i++){
                    if(banco[i].valor <= val_max && banco[i].valor >= val_min){
                        cout << "Modelo: " << banco[i].modelo << " | Valor: " << banco[i].valor << " | Placa: " << banco[i].placa << endl;
                    }
                }
                break;
            case 'f': // Relatório
                cout << "Relatório do banco de dados" << endl;
                // Porcentagem de veículos nos tipos
                int barato = banco[0].valor; // Iniciando a variável "barato" para comparar ao fazer o 3° item do relatório
                int caro = banco[0].valor; // Para comparar ao fazer o 4° item do relatório
                for(i = 0; i < qtd; i++){ // Verificando a quantidade de carros de cada tipo
                    if(banco[i].tipo == "SUV"){
                        SUV++;
                    } else if(banco[i].tipo == "Hatch"){
                        HATCH++;
                    } else if(banco[i].tipo == "Pick-up"){
                        PICKUP++;
                    } else if(banco[i].tipo == "Sedã"){
                        SEDAN++;
                    }
                    // Porcentagem de veículos no combustível
                    if(banco[i].combustivel == "Gasolina"){
                        GAS++;
                    } else if(banco[i].combustivel == "Flex"){
                        FLEX++;
                    } else if(banco[i].combustivel == "Diesel"){
                        DIES++;
                    }
                    // O mais barato 1.0
                    if(banco[i].valor < barato && banco[i].potencia == "1"){
                        barato = banco[i].valor;
                        placa = banco[i].placa;
                    }
                    // O mais caro de câmbio hidráulico
                    if(banco[i].valor > caro && banco[i].cambio == "Hidráulica"){
                        caro = banco[i].valor;
                        placa2 = banco[i].placa;
                    }
                    // Quantidade de veículos com mais de 5 anos
                    if(banco[i].ano < 2019){
                        qtdanos++;
                        km += banco[i].km;
                    }

                }
                // Passando para porcentagem
                SUV = (SUV/qtd)*100;
                HATCH = (HATCH/qtd)*100;
                PICKUP = (PICKUP/qtd)*100;
                SEDAN = (SEDAN/qtd)*100;
                // Passando para porcentagem
                GAS = (GAS/qtd)*100;
                FLEX = (FLEX/qtd)*100;
                DIES = (DIES/qtd)*100;
                // Calculando o financiamento
                int taxa_calc = (1+0.03);
                int meses = -60;
                financiamento = (0.03 * barato)/ 1 - pow(taxa_calc, meses);
                // Calculando o seguro
                seguro = caro * 0.05; // Utilizei a taxa de 5% 
                // Calculando a média de km dos carros com mais de 5 anos
                mediakm = km/qtdanos;    

                // Saídas
                cout << "- A porcentagem de carros do tipo SUV é: " << SUV << "%." << endl;
                cout << "- A porcentagem de carros do tipo Hatch é: " << HATCH << "%." << endl;
                cout << "- A porcentagem de carros do tipo Pick-up é: " << PICKUP << "%." << endl;
                cout << "- A porcentagem de carros do tipo Sedã é: " << SEDAN << "%." << endl;
                cout << "- A porcentagem de carros que utilizam gasolina é: " << GAS << "%." << endl;
                cout << "- A porcentagem de carros que são FLEX é: " << FLEX << "%." << endl;
                cout << "- A porcentagem de carros que utilizam diesel é: " << DIES << "%." << endl;
                cout << "- O veículo mais barato 1.0 possui o valor de R$" << barato << " e sua placa é " << placa << ". Sua parcela em um financiamento de 60 meses é de R$" << financiamento << "." << endl;
                cout << "- O veículo mais caro de direção hidráulica possui o valor de R$" << barato << " e sua placa é " << placa << ". Seu seguro custa R$" << seguro << "." << endl;
                cout << "- A quantidade de veículos com mais de 5 anos é de " << qtdanos << " e a média de km de todos eles é " << mediakm << " quilômetros." << endl;
        };
    }while(opcao != 's');
  
    // Escrita - Usada no caso A, onde ocorre a inserção
    ofstream saida("BD_veiculos.txt");
    for(i = 0; i < qtd; i++){
        if(banco[i].valido){
            saida << banco[i].modelo << " ";
            saida << banco[i].marca << " ";
            saida << banco[i].tipo << " ";
            saida << banco[i].ano << " ";
            saida << banco[i].km << " ";
            saida << banco[i].potencia << " ";
            saida << banco[i].combustivel << " ";
            saida << banco[i].cambio << " ";
            saida << banco[i].direcao << " ";
            saida << banco[i].cor << " ";
            saida << banco[i].portas << " ";
            saida << banco[i].placa << " ";
            saida << banco[i].valor << endl;
        }
    }
    saida << "FIM";
    saida.close();
    
    return 0;
}