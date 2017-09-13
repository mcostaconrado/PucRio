#include <stdio.h>	
#include <stdlib.h>
#include <assert.h>
#include <string.h>


typedef struct Empregado {
	int id;
	char nome[41];
	double salario;
}Empregado;

int insere_or_cres(Empregado **v, int n, int max, int id, char *nome, double salario) {
	Empregado *p;
	int posicao;

	p = (Empregado*)malloc(sizeof(Empregado));

	if (n == max || p == NULL) {
		return 0;
	}

	p->id = id;
	strcpy(p->nome, nome);
	p->salario = salario;

	posicao = 0;
	for (int i = 0; i < max; i++) {

		if (v[i]->id == id) {
			v[i]->salario = salario;
			return -1;
		}

		if (v[i]->salario > salario) { // _ _ _ _ _
			posicao = i+1;
		}
		else {
			i = max;
		}
	}

	for (int i = n; i >=posicao-1; i--) {
		if (i == posicao)
			v[i] = p;
		else
			v[i] = v[i-1];
	}
	return 1;
}

void main() {
	Empregado p1 = { 2, "Conrado", 200 };
	Empregado p2 = { 3, "Conrado", 300 };
	Empregado p3 = { 10, "Conrado", 400 };
	Empregado *p[] = { &p1, &p2, &p3 };

	printf(" %lf ", p[0]->salario);
	printf("%i", insere_or_cres(p, 3, 4, 6, "Conrado", 300));
}