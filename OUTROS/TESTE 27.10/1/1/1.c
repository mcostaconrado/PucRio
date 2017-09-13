#include <stdio.h>
#define MAX 3
#define MOLDURA printf("\n\n====================================================================\n====================================================================\n")

void capturaNotas(int matricula[], float nota[]) {
	int i, mat = 1;
	for (i = 0; i < MAX; i++) {
		printf("\n\nDigite a matricula e a nota do aluno:\n-> ");
		scanf_s("%d", &matricula[i]);
		printf("-> ");
		scanf_s("%f", &nota[i]);
	}
}

float notaMax(float v[]) {
	float notaf = 0;
	int i;
	for (i = 0; i < MAX; i++) {
		if (v[i] >= notaf) {
			notaf = v[i];
		}
	}
	return notaf;
}

void substituiNota(float notaMax, float antigas[], float novas[]) {
	int i;
	for (i = 0; i < MAX; i++) {
		novas[i] = antigas[i] * 10 / notaMax;
	}
}

void mostraNotas(float antigas[], float novas[], int matricula[]) {
	int i;
	for (i = 0; i < MAX; i++) {
		printf("\n\n\t\tMATRICULA %d", matricula[i]);
		printf("\n\n\tNOTA ANTIGA: %.2f", antigas[i]);
		printf("\n\n\tNOTA ATUALIZADA: %.2f", novas[i]);
		MOLDURA;
	}
}

void main() {
	int matricula[MAX];
	float notas[MAX], novasNotas[MAX];
	int i = 0;

	capturaNotas(matricula, notas);
	
	substituiNota(notaMax(notas), notas, novasNotas);
	mostraNotas(notas, novasNotas, matricula);

	
	printf("\n\n");
	
}