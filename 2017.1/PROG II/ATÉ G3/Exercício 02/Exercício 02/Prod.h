#include <stdio.h>
#include <stdlib.h>

#ifndef PROD_H
#define PROD_H


typedef struct Prod Prod;

Prod* prod_cria(char[15], int, float);
void prod_destroi(Prod*);
void prod_exibe(Prod*);
int prod_estoque_vazio(Prod*);

#endif