#include <stdio.h>
#include <stdlib.h>

#define MAX 30

int qualMedalha(char c) {
	int i;
	char medalhas[3] =	{ 'o', 'p', 'b' };

	for (i = 0; i < 3; i++) {
		if (medalhas[i] == c) {
			return i + 1;
		}
	}
}

int zeraLinha(int m[][5], int i) {
	int j;
	for (j = 1; j<5; j++) {
		m[i][j] = 0;
	}

}

void preenche(int m[MAX][5]) {

	int escola, modalidade, i, j, quant = 0;
	char medalha;

	FILE *entrada;
	entrada = fopen("medalhas.txt", "r");

	if (entrada == NULL) {
		printf("ERRO NA LEITURA DE ARQUIVO DE MEDALHAS.");
		exit(-1);
	}


	while (fscanf(entrada, "%d %d %c", &escola, &modalidade, &medalha) == 3) {
		for (i = 0; i <= quant; i++) {
			if (m[i][0] == escola){
				m[i][qualMedalha(medalha)] += 1;
				i = quant + 2;
			}

			if (i == quant + 1) {//escola nao cadastrada ainda.
				m[i][0] = escola;
				for (j = 1; j < 5; j++) {
					m[i][j] = 0;
				}
				m[i][qualMedalha(medalha)] ++;
			}
		}

		for (i = 0; i <= quant; i++) {
			m[i][4] = m[i][1] * 5 + m[i][2] * 3 + m[i][3];
		}
	}
	fclose(entrada);
}

void exibe(int m[MAX][5]) {
	int i, j;
	for (i = 0; i < MAX; i++) {
		printf("\n");
		for (j = 0; j < 5; j++) {
			printf("%d  ", m[i][j]);
		}
	}
}


void main() {
	int i, m[MAX][5];

	preenche(m[MAX][5]);
	exibe(m[MAX][5]);
}