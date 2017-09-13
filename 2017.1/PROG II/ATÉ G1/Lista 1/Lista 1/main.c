#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <math.h>
#include <string.h>

//23

/*
typedef struct Candidato {
	int matricula;
	char nome[81];
	int idade;
	double nota;
} Candidato;

Candidato* cria_candidato() {
	Candidato *c;

	c = (Candidato*) malloc(sizeof(Candidato));

	return c;
}

void preenche_candidato(Candidato *c) {
	printf("Matricula: ");
	scanf("%d", &c->matricula);
	printf("\nNome: ");
	scanf(" %s", &c->nome);
	printf("\nIdade: ");
	scanf("%d", &c->idade);
	printf("\nNota: ");
	scanf("%lf", &c->nota);
}

void exibe_candidatos(Candidato *v[], int n) {
	char nome[81];
	if (n >= 1) {
		printf("Matricula: %i", v[0]->matricula);
		printf("\nNome: %s", v[0]->nome );
		printf("\nIdade: %i", v[0]->idade);
		printf("\nNota: %lf", v[0]->nota);
		exibe_candidatos(&v[1], n - 1);
	}
}

Candidato *busca(Candidato *v[], int n, int mat) {
	if (n == 0)
		return NULL;
	if (n >= 1) {
		if (v[0]->matricula == mat)
			return &v[0];
		else
			return busca(&v[1], n - 1, mat);
	}
}

void main() {
}

*/

//24

/*
typedef struct Avaliacao {
	double vendas;
	int faltas;	

} Avaliacao;

typedef struct Vendedor {
	int inscricao;
	char nome[81];
	double salario;
	Avaliacao aval;
} Vendedor;

double calcula_extra(Avaliacao *aval) {
	int faltas = aval->faltas;
	double extra=0, vendas = aval->vendas;

	if (faltas >= 10 || vendas < 500)
		extra = -100;
	else if (vendas > 2000) {
		if (faltas < 2) {
			extra = 180;
		}
		else if (faltas <= 4) {
			extra = 150;
		}
	}
	else if (faltas > 4 || faltas <= 6 || vendas > 5000) {
		extra = 120;
	}
	return extra;
}

double calcula_total_folha(Vendedor v[], int n) {
	if (n == 1)
		return v[0].salario + calcula_extra(&v[0].aval);
	return v[0].salario + calcula_extra(&v[0].aval) + calcula_total_folha(&v[1], n - 1);
}

void main() {
	Vendedor v[2] = { {100, "conrado", 300, {2001, 1}}, { 100, "conrado", 400 ,{ 400, 12 } } };

	printf("Folha: R$%.2lf.\n", calcula_total_folha(v, 2));
}

*/


//22

typedef struct Termo {
	int coef;
	int grau;
} Termo;

Termo *cria_vetor_soma(Termo *v1, int sv1, Termo *v2, int sv2, int *m) {

	int i, j, tamanho = sv1, aux, n = 0;
	Termo *t;

	for (i = 0; i < sv2; i++) {
		aux = 0;
		for (j = 0; j < sv1; j++) {
			if (v2[i].grau == v1[j].grau) {
				aux++;
			}
		}
		if (aux == 0) {
			(*m)++;
		}
	}
}

void main() {
	char v[3] = { 'a', 'b', 'c' };
	int m;
	Termo v1[3] = { { 3,5 }, { 2,4 }, { 7,2 } };
	Termo v2[5] = { { 5,6 }, { 2,4 }, { 8,3 }, { 8,2 }, { 7,0 } };
	
	printf("%d", cria_vetor_soma(v1, 3, v2, 5, &m));
	

	//printf("%d", sizeof(v2)/(sizeof(Termo*)*3));// PERGUNTAR
}

