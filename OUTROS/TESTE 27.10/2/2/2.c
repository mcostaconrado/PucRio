#include <stdio.h>
#define NUMEROS 4
#define JOGADORES 1
#define MOLDURA printf("\n\n=======================================================================\n=======================================================================\n\n")

void preencheVetor(int v[]) {
	int i;
	for (i = 0; i < NUMEROS; i++) {
		printf("\n-> ");
		scanf_s("%d", &v[i]);
	}
}

int confereNumeros(int sorteados[]) {
	int i, certos = 0, apostados[NUMEROS];

	printf("Insira os numeros apostados:\n");
	preencheVetor(apostados);

	for (i = 0; i < NUMEROS; i++) {
		if (apostados[i] == sorteados[i]) {
			certos++;
		}
	}
	if (certos == NUMEROS) {
		return 1;
	}
	else {
		return 0;
	}
}

void main() {
	float premio;
	int i, j=0, sorteados[NUMEROS], matriculasVencedoras[JOGADORES], matricula=1;

	printf("Informe o premio total: ");
	scanf_s("%f", &premio);
	printf("\n\nInforme os numeros sorteados:\n");
	preencheVetor(sorteados);

	for (i = 0; i < JOGADORES; i++) {

		printf("\n\nInforme a matricula do jogador: ");
		scanf_s("%d", &matricula);
		if (matricula != 0) {
			if (confereNumeros(sorteados) == 1) {
				matriculasVencedoras[j] = matricula;
				j++;
			}
		}
		else {
			i = JOGADORES + 1;
		}
	}

	if (j != 0) {
		for (i = 0; i < j; i++) {
			printf("\nMatricula %d GANHOU", matriculasVencedoras[i]);
		}
		printf("\n\n%d APOSTADORES GANHARAM O PREMIO. CADA UM IRA RECEBER R$%.2f\n\n\n", j , premio / j);
	}
	else {
		printf("\n\nNINGUEM GANHOU!!\n\n");
	}
}