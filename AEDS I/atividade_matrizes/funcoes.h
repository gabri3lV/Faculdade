#ifndef FUNCOES_H
#define FUNCOES_H

typedef int TMatriz[128][128];

int transposta(TMatriz m1, int nl1, int nc1, TMatriz m2, int nl2, int nc2, TMatriz m3, int *nl3, int *nc3, int escolha);
int soma(TMatriz m1, int nl1, int nc1, TMatriz m2, int nl2, int nc2, TMatriz m3, int *nl3, int *nc3);
int multiplicacao(TMatriz m1, int nl1, int nc1, TMatriz m2, int nl2, int nc2, TMatriz m3, int *nl3, int *nc3);
double mediamatriz1(TMatriz m1, int nl1, int nc1);
int printamatriz(TMatriz m3, int *nl3, int *nc3);

#endif /* FUNCOES_H */

