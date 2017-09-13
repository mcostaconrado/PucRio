#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "ponto.h"

struct Ponto{
	double x;
	double y;
};

Ponto *ponto_cria (double x, double y){
	Ponto *p = (Ponto*) malloc(sizeof(Ponto));
	assert(p!=NULL);
	p->x = x;
	p->y = y;
	return p;
}



void ponto_destroi (Ponto *p){
	free(p);
}

void ponto_obtem(Ponto *p, double *x, double *y){
	*x = p->x;
	*y = p->y;
}

double ponto_distancia (Ponto *p, Ponto *q){
	return sqrt(pow(p->x-q->x,2) + pow(p->y-q->y,2));
}

/*

void ponto_atribui(Ponto *p, double x, double y){
	p->x = x;
	p->y = y;
}



int ponto_compara(Ponto *p, Ponto *q){
	if (p->x == q->x && p->y == q->y)
		return 1;
	return 0;
}

Ponto * ponto_clona (Ponto *p){
	Ponto *q = ponto_cria(p->x, p->y);
	return q;
}

void ponto_imprime (Ponto *c){
	printf("\nx: %lf\ny: %lf", c->x, c->y);
}

*/