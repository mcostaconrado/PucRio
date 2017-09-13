#include <assert.h>
#include <stdio.h>
#include "ConjCirc.h"

int
main(void)
{
	Ponto *p1 = ponto_cria(0., 0.);
	Ponto *p2 = ponto_cria(-1., 2.);
	Ponto *p3 = ponto_cria(1., 1.);
	Ponto *p4 = ponto_cria(3., 2.);
	Ponto *p6 = ponto_cria(100., 100.);
	Ponto *p5 = ponto_cria(1., 3.);
	Ponto *p7 = ponto_cria(1., 1.);

	Circulo *c1 = circulo_cria(p1, 1.);
	Circulo *c2 = circulo_cria(p2, 2.);
	Circulo *c3 = circulo_cria(p3, 1.);
	Circulo *c4 = circulo_cria(p4, 1.);
	Circulo *c5 = circulo_cria(p5, 8.);
	Circulo *c6 = circulo_cria(p6, 1.);
	Circulo *c7 = circulo_cria(p7, 3.);

	ConjCirc *S1, *S2, *S3, *S4;

	S1 = cj_cria();
	assert(cj_insere(S1, c1));
	assert(!cj_insere(S1, c1));

	assert(cj_insere(S1, c2));
	assert(!cj_insere(S1, c2));

	assert(cj_insere(S1, c3));
	assert(!cj_insere(S1, c3));

	assert(cj_insere(S1, c4));
	assert(!cj_insere(S1, c4));

	assert(cj_insere(S1, c5));
	assert(!cj_insere(S1, c5));

	assert(!cj_remove(S1, c6));
	assert(!cj_remove(S1, c7));

	printf("*** S1\n");
	cj_imprime(S1);

	printf("\n*** S2 = S1 cap p1\n");
	S2 = cj_contem(S1, p1);
	cj_imprime(S2);
	assert(!cj_insere(S2, c1));
	assert(!cj_remove(S2, c2));
	assert(!cj_remove(S2, c3));
	assert(!cj_remove(S2, c4));
	assert(!cj_insere(S2, c5));
	assert(!cj_remove(S2, c6));
	assert(!cj_remove(S2, c7));

	printf("\n*** S3 = S1 cap p5\n");
	S3 = cj_contem(S1, p5);
	cj_imprime(S3);
	assert(!cj_remove(S3, c1));
	assert(!cj_remove(S3, c2));
	assert(!cj_remove(S3, c3));
	assert(!cj_remove(S3, c4));
	assert(!cj_insere(S3, c5));
	assert(!cj_remove(S3, c6));
	assert(!cj_remove(S3, c7));

	printf("\n*** S4 = S3 cap p6\n");
	S4 = cj_contem(S3, p6);
	cj_imprime(S4);
	assert(!cj_remove(S4, c1));
	assert(!cj_remove(S4, c2));
	assert(!cj_remove(S4, c3));
	assert(!cj_remove(S4, c4));
	assert(!cj_remove(S4, c5));
	assert(!cj_remove(S4, c6));
	assert(!cj_remove(S4, c7));

	cj_destroi(S1);
	cj_destroi(S2);
	cj_destroi(S3);
	cj_destroi(S4);

	circulo_destroi(c1);
	circulo_destroi(c2);
	circulo_destroi(c3);
	circulo_destroi(c4);
	circulo_destroi(c5);
	circulo_destroi(c6);
	circulo_destroi(c7);

	return 0;
}
