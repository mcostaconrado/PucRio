#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "circulo.h"
#define PI 3.14159265359


struct Circulo{
	Ponto *p;
	double r;
};

Circulo *circulo_cria (Ponto* p, double r){
	Circulo *c;
	c= (Circulo*)malloc(sizeof(Circulo));
	assert(c!=NULL);
	c->p = p;
	c->r = r;
	return c;
}

void circulo_destroi (Circulo *c){
	ponto_destroi(c->p);
	free(c);
}

void circulo_obtem(Circulo *c, double *r, double *x, double *y){
	*r = c->r;
	ponto_obtem(c->p, x, y);
}

int circulo_interior(Circulo *c, Ponto*p){
	if (ponto_distancia(c->p, p) > c->r)
		return 0;
	return 1;
}

/*

int circulo_compara(Circulo *c1, Circulo*c2){
	if (ponto_compara(c1->p,c2->p))
		if (c1->r == c2->r)
			return 1;
	return 0;
}

Circulo * circulo_clona (Circulo *c){
	Circulo *c2 = (Circulo*)malloc(sizeof(Circulo));
	c2->p = c->p;
	c2->r = c->r;
	return c2;
}

void circulo_imprime (Circulo *c){
	ponto_imprime(c->p);
	printf("\nRaio: %lf", c->r);
}

double circulo_area(Circulo *c){
	return PI*pow(c->r,2);
}

*/