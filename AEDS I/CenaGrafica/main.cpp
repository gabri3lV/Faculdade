/*************************************************
*              ATIVIDADE AEDS I                  *
* Autor:       Gabriel Vilela Araújo             *
* Matrícula:   2023.2.08.001                     *
* Objetivo:    Calcular a área e volume total    *
*              de uma cena que contém figuras    *
*              planas e bidimensionais. O        *
*              código faz uso de um arquivo      *
*              de texto chamado "cenagrafica.txt"*
*              que contém as informações das     *
*              figuras, como raio, lado,         *
*              altura, etc. Após fazer o         *
*              cálculo da área e do volume,      *
*              o código soma com o valor         *
*              atual do volume total e da        *
*              área total.                       *
*************************************************/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main(){
    
    ifstream arquivo("cenagrafica.txt");
    if(!arquivo.is_open()){
        cout << "Erro! Arquivo não existe" << endl;
        return 1;
    }
    float lado, raio, lado1, lado2, lado3, altura, base, area, volume, geratriz = 0;
    float area_total = 0;
    float volume_total = 0;
    string objeto;
    arquivo >> objeto;
    while(objeto != "FIM"){
        //CALCULANDO A ÁREA E VOLUME DO CUBO
        if(objeto == "cubo"){
            arquivo >> lado;
            area = 6 * lado * lado;
            volume = lado * lado * lado;
            area_total += area; //SOMANDO A ÁREA TOTAL ATUAL COM A ÁREA OBTIDA
            volume_total += volume; //SOMANDO O VOLUME TOTAL ATUAL COM O VOLUME OBTIDO
        }
        //CALCULANDO A ÁREA E VOLUME DA ESFERA
        if(objeto == "esfera"){
            arquivo >> raio;
            area = 4 * 3,14 * (raio*raio);
            volume = 4/3 * 3,14 * (raio*raio*raio);
            area_total += area;
            volume_total += volume;
        }
        //CALCULANDO A ÁREA DO QUADRADO
        if(objeto == "quadrado"){
            arquivo >> lado;
            area = lado * lado;
            area_total += area;        
        }
        //CALCULANDO A ÁREA DO CÍRCULO
        if(objeto == "circulo"){
            arquivo >> raio; 
            area = 3,14 * (raio * raio);
            arquivo >> altura;
            area_total += area;
        }
        //CALCULANDO A ÁREA E VOLUME DO RETÂNGULO
        if(objeto == "retangulo"){
            arquivo >> lado1 >> lado2 >> altura;
            area = lado1 * lado2;
            volume = lado1 * lado2 * altura;
            area_total += area;
            volume_total += volume;
        }
        //CALCULANDO A ÁREA E VOLUME DO PARALELEPÍPEDO
        if(objeto == "paralelepipedo"){
            arquivo >> lado1 >> lado2 >> lado3;
            area = lado1*lado2 + lado1*lado3 + lado2*lado3;
            volume = lado1*lado2*lado3;
            area_total += area;
            volume_total = volume;
        }
        //CALCULANDO A ÁREA E VOLUME DO CILINDRO
        if(objeto == "cilindro"){
            arquivo >> raio >> altura;
            area = 2 * 3,14 * raio * (raio + altura);
            volume = 3,14 * sqrt(raio);
            area_total += area;
            volume_total += volume;
        }
        //CALCULANDO A ÁREA E VOLUME DO CONE
        if(objeto == "cone"){
            arquivo >> raio >> altura >> geratriz;
            area = 3,14 * raio * (raio + geratriz);
            volume = 1/3 * altura * 3,14 * sqrt(raio);
            area_total += area;
            volume_total += volume;
        }
        //CALCULANDO A ÁREA DO TRIÂNGULO
        if(objeto == "triangulo"){
            arquivo >> base >> altura;
            area = (base * altura)/2;
            area_total += area;
        }
        arquivo >> objeto;
    }
    cout << "A área total de todas as figuras da cena é: " << area_total <<" m\u00B2." << endl;
    cout << "O volume total de todas as figuras da cena é: " << volume_total <<" m\u00B3."<< endl;
    arquivo.close();
    return 0;
}