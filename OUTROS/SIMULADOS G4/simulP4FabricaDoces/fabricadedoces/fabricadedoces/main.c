#include <stdio.h>
#include <stdlib.h>

#define MESES 6
#define MAX 20

void zeraVetor(float v[], int qtd) {
	int i;
	for (i = 0; i < qtd; i++) {
		v[i] = 0;
	}
}
void deducoes(float bruto, float *inss, float *ir) {
	float aliquota, deduzir;
	*ir = 0;

	if (bruto > 2668.15) {
		*inss = 293.50;
	}
	else {

		if (bruto <= 800.45) {
			aliquota = 7.65;
		}
		else if (bruto <= 900){
			aliquota = 8.65;
		}
		else if (bruto <= 1334.07) {
			aliquota = 9;
		}
		else {
			aliquota = 11;
		}
		*inss = (1 - .01*aliquota) * bruto;
	}

	aliquota = 0;

	if (bruto - *inss > 2512.08) {
		deduzir = 502.58;
		aliquota = 27.5;
	}
	else if (bruto - *inss >= 1257.13) {
		deduzir = 188.57;
		aliquota = 15;
	}

	*ir = aliquota*(bruto - *inss) - deduzir;
}


void salarioFuncionarios(float m[][MESES], int qtd, float v[]) {
	int i, j;
	float inss, ir;
	zeraVetor(v, qtd);
	
	for (i = 0; i < qtd; i++) {
		for (j = 0; j < MESES; j++) {
			deducoes(m[i][j], &inss, &ir);
			v[i] += m[i][j] - inss - ir;
		}
	}
}


void distribuiBonus(int matriculas[], float semestrais[], int qtd) {
	int i, mat;
	float soma=0, bonus;

	FILE *destaques;
	destaques = fopen("destaques.txt", "r");

	if (destaques == NULL) {
		printf("ERRO NA  ABERTURA DE DESTAQUES.TXT");
		exit(-1);
	}

	for (i = 0; i < qtd; i++) {
		soma += semestrais[i];
	}

	bonus = soma*.03;
	while (fscanf(destaques, "%d", &mat) == 1) {
		for (i = 0; i < qtd; i++) {
			if (mat == matriculas[i]) {
				semestrais[i] += bonus;
				i = qtd;
			}
		}
	}
	fclose(destaques);
}

void armazenaInfos(int matriculas[], float brutos[][MESES], int *quant) {
	int w = 0;
	*quant = 0;
	FILE *entrada;
	entrada = fopen("salarios.txt", "r");

	if (entrada == NULL) {
		printf("\n\nERRO NA ABERTURA DO ARQUIVO DE MATRICULAS E SALARIOS\n\n");
		exit(-1);
	}

	while (fscanf(entrada, "%i", &matriculas[*quant]) == 1) {
		for (w = 0; w < MESES; w++) {
			while (fscanf(entrada, "%f", &brutos[*quant][w]) == 1) {
				*quant = *quant + 1;
			}
		}
	}	
	fclose(entrada);
}


void apresentaDados(int matriculas[], float brutos[][MESES], int quant, float liquidos[] ) {
	int i, j;

	for (i = 0; i < quant; i++) {
		printf("\n%d", matriculas[i]);
		for (j = 0; j < MESES; j++) {
			printf("%10.2f", brutos[i][j]);
			printf("%10.2f", liquidos[i]);
		}
	}
}


void main() {
	int matriculas[MAX], quant;
	float brutos[MAX][MESES], liquidos[MAX];

	armazenaInfos(matriculas, brutos, &quant);
	salarioFuncionarios(brutos, quant, liquidos);
	distribuiBonus(matriculas, liquidos, quant);
	apresentaDados(matriculas, brutos, quant, liquidos);
}