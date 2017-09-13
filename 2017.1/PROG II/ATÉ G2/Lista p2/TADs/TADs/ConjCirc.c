#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "ConjCirc.h"

struct ConjCirc{
	Circulo *c;
	ConjCirc *prox;
};

ConjCirc * cj_cria(){
	ConjCirc* p;
	p = (ConjCirc*)malloc(sizeof(ConjCirc));
	assert(p!=NULL);
	return p;
}

void cj_destroi (ConjCirc*p){
	ConjCirc* aux;

	if (p->prox != NULL){
		aux = p->prox;
		free(p);
		cj_destroi(aux);
	}
	else{
		free(p);
	}
}

ConjCirc * cj_insere(ConjCirc *p, Circulo *c){
	ConjCirc* aux = p;
	ConjCirc* novo;

	int achou = 0;

	for (; p->prox != NULL && !achou; ){
		if (p->c = c)
			achou = 1;
		p = p->prox;
	}

	if (!achou){
		novo = cj_cria();
		novo->c = c;
		novo->prox  = aux;
		return novo;
	}
	return aux;	 
}

int cj_contem(ConjCirc*c, Ponto *p) {
	ConjCirc *nova, *aux=c;
	nova = cj_cria();
	while (aux != NULL) {
		if (circulo_interior(aux->c, p)) {
			nova = cj_insere(nova, c);
		}
		aux = aux->prox;
	}
	return nova;
}

void cj_imprime(ConjCirc *c) {
	double x, y, r;
	if (c != NULL) {
		circulo_obtem(c->c, &x, &y, &r);
		printf("x: %lf\ny: %lf\nRaio: %lf\n\n", x,y,r);
		cj_imprime(c->prox);
	}
}