#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define N 10

typedef struct Time {
	char nome[256];
	int pontos;
	int vitorias;
} Time;

void aloca_time(Time *v[N]) {
	int i;
	Time *t;
	for (i = 0; i<N; i++) {
		t = (Time*)malloc(sizeof(Time));
		printf("\n\n\tTIME 01:");
		printf("\n\nNome: ");
		scanf("%s", &t->nome);
		printf("\nPontos: ");
		scanf("%i", &t->pontos);
		printf("\nVitorias: ");
		scanf("%i", &t->vitorias);
		v[i] = t;
	}
}

int verifica(Time *t1, Time *t2) { // A FUNÇÃO RETORNA -1 SE O TIME 1 GANHAR, E 1 SE O TIME DOIS GANHAR
	if (t1->pontos == t2->pontos)
		if (t1->vitorias == t2->vitorias)
			return strcmp(t1->nome, t2->nome);
		else if (t1->vitorias > t2->vitorias)
			return -1;
		else
			return 1;
	else if (t1->pontos > t2->pontos)
		return -1;
	else
		return 1;
}

void ordena(Time *v[]) {
	int i, j, k;
	Time *t;
	
	for (j = 0; j < N - 1; j++) {
		k = j;
		for (i = j + 1; i < N; i++) {
			if (verifica(v[i], v[k]) == -1)
				k = i;
		}
		if (k != j) {
			t = v[j];
			v[j] = v[k];
			v[k] = t;
		}
	}

	/* BUBBLE SORT
	
	int i, j, trocou, n=N;
	Time *t;
	do {
		trocou = 0;
		for (i = 0, j = 1; j < n; i++, j++) {
			if (verifica(v[i], v[j]) == 1) {
				t = v[i];
				v[i] = v[j];
				v[j] = t;
				trocou = 1;
			}
		}
		n--;
	} while (trocou);*/

}

void imprime(Time *v[N]) {
	int i = 0;
	printf("POSICAO\tTIME\t\t\tPONTOS\tVITORIAS\n");
	for (i = 0; i<N; i++) {
		printf("\n%i\t%s\t\t%i\t%i", i+1, v[i]->nome, v[i]->pontos, v[i]->vitorias);
	}
}

void destroi(Time *v[N]) {
	int i;
	for (i = 0; i<N; i++) {
		free(v[i]);
	}
}


void main() {
	Time v1 = { "Flamengo", 71, 20 };
	Time v2 = { "Botafogo", 59, 17 };
	Time v3 = { "Fluminense", 50, 13 };
	Time v4 = { "Avai     ", 50, 13};
	Time v5 = { "Sport    ", 47, 13 };
	Time v6 = { "Sao Paulo", 52, 14 };
	Time v7 = { "Atletico Mg", 62, 17 };
	Time v8 = { "Palmeiras", 80, 24 };
	Time v9 = { "Coritiba", 46, 11 };
	Time v10 = { "Atletico Pr", 57, 17 };
	Time *v[N] = { &v1, &v2, &v3 , &v4, &v5, &v6, &v7, &v8, &v9, &v10};


	printf("\nSEM ORDENACAO\n\n");
	imprime(v);

	ordena(v);

	printf("\n\n\nCOM ORDENACAO\n");

	printf("\n\n");

	imprime(v);

	printf("\n\n");
	
	
}