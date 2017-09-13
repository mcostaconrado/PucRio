#include <math.h>
#include <stdio.h>

float multiplica_credito(float v[], int n, int cred) {
	float soma = 0;
	for (int i = 0; i < n; i++) {
		soma += v[i] * cred;
	}
	return soma;
}

float media_ponderada(float v2[], int n2, float v4[], int n4, float v6[], int n6) {
	float soma2 = multiplica_credito(v2, n2, 2);
	float soma4 = multiplica_credito(v4, n4, 4);
	float soma6 = multiplica_credito(v6, n6, 6);
	float soma = soma2 + soma4 + soma6;
	return soma / (n2 * 2 + n4 * 4 + n6 * 6);
}


void main() {
	float DoisCred[100], QuatroCred[100], SeisCred[100];
	int Dois=0, Quatro=0, Seis=0;
	float nota = 0;

	printf("Informe as notas de 2 creditos: ");

	while (nota >= 0) {
		scanf("%f", &nota);
		if (nota >= 0) {
			DoisCred[Dois] = nota;
			Dois++;
		}
	}
	
	nota = 0;

	printf("Informe as notas de 4 creditos: ");

	while (nota >= 0) {
		scanf("%f", &nota);
		if (nota >= 0) {
			QuatroCred[Quatro] = nota;
			Quatro++;
		}
	}

	nota = 0;
	printf("Informe as notas de 6 creditos: ");

	while (nota >= 0) {
		scanf("%f", &nota);
		if (nota >= 0) {
			SeisCred[Seis] = nota;
			Seis++;
		}
	}

	printf("\n\nSEU CR ->> %.1f.\n\n", media_ponderada(DoisCred, Dois, QuatroCred, Quatro, SeisCred, Seis));
}