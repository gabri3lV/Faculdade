#include <stdio.h>
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main(){
    ifstream arquivo("cenagrafica.txt");
    if(!arquivo.is_open()){
        cout << "Erro! Arquivo não existe!";
        return 1;
    }
    float lado, raio, lado1, lado2, lado3, altura, base, area, volume = 0;
    float area_total = 0;
    float volume_total = 0;
    string objeto;
    arquivo >> objeto;
    while(arquivo >> objeto && objeto != "fim"){
        cout << "rodando" << endl; 
        if(objeto == "cubo"){
            arquivo >> lado;
            area = 6 * lado * lado;
            volume = lado * lado * lado;
        }
    }
    volume_total += volume;
    area_total += area;
    printf("%f", volume_total);
    printf("%f", area_total);
    arquivo.close();
    return 0;
}