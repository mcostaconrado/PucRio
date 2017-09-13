#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Prod.h"

typedef struct Prod {
	char nome[15];
	int estoque;
	float valor;
}Prod;

Prod* prod_cria(char nome[15], int qt, float valor ) {
	Prod *p = (Prod*) malloc(sizeof(Prod));
	p->estoque = qt;
	p->valor = valor;
	strcpy(p->nome, nome);
	return p;
}

void prod_destroi(Prod *p) {
	free(p);
}

void prod_exibe(Prod *p) {
	printf("%s\t %i\t %lf\n", p->nome, p->estoque, p->valor);
}

int prod_estoque_vazio(Prod *p) {
	if (p->estoque == 0)
		return 1;
	return 0;
}