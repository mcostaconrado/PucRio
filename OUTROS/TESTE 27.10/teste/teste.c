#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MERC 5
#define VEND 10
#define cls system ("cls");


void precoMercadorias(float v[]) {
	int i, cod;
	for (i = 0; i<MERC; i++) {
		/*printf("\n\n\nInforme o codigo da mercadoria: \n-> ");
		scanf_s("%d", &cod);*/
		printf("\nInforme o valor unitario da mercadoria %d:\n-> ", i+1);
		scanf_s("%f", &v[i]); //[cod - 1]
	}
	cls
}

int verificaCod(float a) {
	while (a < 1 || a>5 || ceil(a) != floor(a)){
		printf("\nVALOR INVALIDO, DIGITE NOVAMENTE: ");
		scanf("%d", a);
	}
	return a;
}

void preencheVenda(float ValorVendidoVendedor[], int quantVendidaVendedor[], float precoMerc[], int vendidasMaisCem[], int maiorQuantVenda[], int codMaisVendidaVendedor[]) {
	int cod = 10, merc, quant = 0;

	while (cod % 10 == 0 && cod <= 100 && cod > 9) {
		merc = 1;
		printf("\n\n\nInforme o codigo do vendedor ");
		scanf_s("%d", &cod);
		if (cod % 10 == 0 && cod <= 100 && cod > 0) {
			printf("\n\n\nInforme o codigo da mercadoria e a quantidade vendida:\n-> ");
			scanf_s("%d", &merc);
			merc = verificaCod(merc);
			printf("\n-> ");
			scanf_s("%d", &quant);
			ValorVendidoVendedor[cod / 10 - 1] += precoMerc[merc - 1] * quant;
			quantVendidaVendedor[cod / 10 - 1] += quant;
			if (quant > maiorQuantVenda[cod / 10 - 1]) {
				maiorQuantVenda[cod / 10 - 1] = quant;
				codMaisVendidaVendedor[cod / 10 - 1] = merc;
			}
			if (quant > 100) {
				vendidasMaisCem[merc - 1] += 1;
			}
		}
		cls
	}
}

void preencheZero(int v[], int a) {
	int i;
	for (i = 0; i<a; i++) {
		v[i] = 0;
	}
}

void preencheZeroF(float v[], int a) {
	int i;
	for (i = 0; i<a; i++) {
		v[i] = 0;
	}
}

void valorUnitarioVendedor(float valorTot[], int unidTot[], float unitarioVendedor[], float *maior) {
	int i;
	printf("\n\n\tVENDEDOR\tVALOR UNITARIO MEDIO");
	for (i = 0; i<VEND; i++) {
		if (unidTot[i] != 0) {
			unitarioVendedor[i] = valorTot[i] / unidTot[i];
			if (unitarioVendedor[i] > *maior) {
				*maior = unitarioVendedor[i];
			}
		}
		else {
			unitarioVendedor[i] = 0;
		}
		printf("\n\t  %d\t\t   R$%.2f", (i + 1) * 10, unitarioVendedor[i]);
	}
}

void maioresVendedores(float v[], float *a) {
	int i;
	printf("\n\n\n  ->MAIOR VALOR UNITARIO MEDIO: R$%.2f\n  ->PELO(S) VENDEDOR(ES): ", *a);
	for (i = 0; i<VEND; i++) {
		if (v[i] == *a) {
			printf("%d  ", (i + 1) * 10);
		}
	}
}

void exibeMaisCem(int v[]) {
	int i;
	printf("\n\n\n\tMERCADORIA\tQT. DE VENDAS DE MAIS DE 100 UNIDADES");
	for (i = 0; i<MERC; i++) {
		printf("\n\t  %d\t\t\t    %d", i + 1, v[i]);
	}
}

void exibeMaisVendida(int v[]) {
	int i;
	printf("\n\n\n\tVENDEDOR\t  MERCADORIA MAIS VENDIDA");
	for (i = 0; i < VEND; i++) {
		if (v[i] == 0) {
			printf("\n\t  %d\t\t\tSEM VENDAS", (i + 1) * 10, v[i]);
		}
		else {
			printf("\n\t  %d\t\t\t    %d", (i + 1) * 10, v[i]);
		}
	}
}

void main() {
	int unidadesVendedor[VEND], vendidasMaisCem[MERC], maiorQuantVenda[VEND], codMaisVendidaVendedor[VEND];
	float valorUnitMedio[VEND], valorTotalVend[VEND], precosMercadorias[MERC], *maiorUnit, maior = 0;
	maiorUnit = &maior;

	preencheZero(unidadesVendedor, VEND);
	preencheZeroF(valorTotalVend, VEND);
	preencheZero(vendidasMaisCem, MERC);
	preencheZeroF(valorUnitMedio, VEND);
	preencheZero(codMaisVendidaVendedor, VEND);
	preencheZero(maiorQuantVenda, VEND);

	precoMercadorias(precosMercadorias);
	preencheVenda(valorTotalVend, unidadesVendedor, precosMercadorias, vendidasMaisCem, maiorQuantVenda, codMaisVendidaVendedor);
	valorUnitarioVendedor(valorTotalVend, unidadesVendedor, valorUnitMedio, maiorUnit);
	maioresVendedores(valorUnitMedio, maiorUnit);
	exibeMaisCem(vendidasMaisCem);
	exibeMaisVendida(codMaisVendidaVendedor);

	printf("\n\n");

}