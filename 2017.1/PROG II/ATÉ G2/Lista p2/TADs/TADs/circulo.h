#ifndef CIRCULO_H
#define CIRCULO_H
#include "ponto.h"

typedef struct Circulo Circulo;

Circulo *circulo_cria (Ponto*, double);
void circulo_destroi (Circulo *);
void circulo_obtem(Circulo *, double *, double*, double*);
int circulo_interior (Circulo *, Ponto*);

/*int compara(Circulo *, Circulo *);
Circulo * clona (Circulo *);
void imprime (Circulo *);
double area (Circulo *);
*/
#endif