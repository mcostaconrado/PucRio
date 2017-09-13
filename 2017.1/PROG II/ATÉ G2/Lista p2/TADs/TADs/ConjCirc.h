#ifndef CONJCIRC_H
#define CONJCIRC_H
#include "circulo.h"

typedef struct ConjCirc ConjCirc;

ConjCirc *cj_cria ();
void cj_destroi (ConjCirc *);
ConjCirc *cj_insere(ConjCirc*, Circulo*);
ConjCirc *cj_remove(ConjCirc*, Circulo*);
int cj_contem(ConjCirc*, Ponto *);
void cj_imprime(ConjCirc*);

#endif