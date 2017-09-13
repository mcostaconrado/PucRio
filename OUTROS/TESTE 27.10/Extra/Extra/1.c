#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MERC 5
#define VEND 10
#define cls system ("cls");


void precoMercadorias(float precos[], int codigos[]) {
	int i;
	for (i = 0; i<MERC; i++) {
		printf("\n\n\nInforme o codigo da mercadoria: \n-> ");
		scanf("%d", &codigos[i]);
		printf("\nInforme o valor unitario da mercadoria %d:\n-> ", codigos[i]);
		scanf("%f", &precos[i]); //[cod - 1]
	}
	cls
}

int verificaCod(int a, int codigos[]) {
	int i;

	while (a!=codigos[0] && a != codigos[1] && a != codigos[2] && a != codigos[3] && a != codigos[4]){
		printf("\nVALOR INVALIDO, DIGITE NOVAMENTE: ");
		scanf("%d", &a);
	}
	for (i = 0; i < MERC; i++) {
		if(a==codigos[i]){
			a = i;
		}
	}
	return a;
}

void preencheVenda(float ValorVendidoVendedor[], int quantVendidaVendedor[], float precoMerc[], int vendidasMaisCem[], int maiorQuantVenda[], int codMaisVendidaVendedor[], int codigos[]) {
	int cod = 10, merc, quant = 0;

	while (cod % 10 == 0 && cod <= 100 && cod > 9) {
		merc = 1;
		printf("\n\n\nInforme o codigo do vendedor ");
		scanf("%d", &cod);
		if (cod % 10 == 0 && cod <= 100 && cod > 0) {
			printf("\n\n\nInforme o codigo da mercadoria e a quantidade vendida:\n-> ");
			scanf("%d", &merc);
			merc = verificaCod(merc, codigos);
			printf("\n-> ");
			scanf("%d", &quant);
			ValorVendidoVendedor[cod / 10 - 1] += precoMerc[merc] * quant;
			quantVendidaVendedor[cod / 10 - 1] += quant;
			if (quant > maiorQuantVenda[cod / 10 - 1]) {
				maiorQuantVenda[cod / 10 - 1] = quant;
				codMaisVendidaVendedor[cod / 10 - 1] = codigos[merc];
			}
			if (quant > 100) {
				vendidasMaisCem[merc] += 1;
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

void exibeMaisCem(int v[], int codigos[]) {
	int i;
	printf("\n\n\n\tMERCADORIA\tQT. DE VENDAS DE MAIS DE 100 UNIDADES");
	for (i = 0; i<MERC; i++) {
		printf("\n\t  %d\t\t\t    %d", codigos[i], v[i]);
	}
}

void exibeMaisVendida(int v[]) {
	int i;
	printf("\n\n\n\tVENDEDOR\t  MERCADORIA MAIS VENDIDA");
	for (i = 0; i < VEND; i++) {
		if (v[i] == 0) {
			printf("\n\t  %d\t\t\tSEM VENDAS", (i + 1) * 10);
		}
		else {
			printf("\n\t  %d\t\t\t    %d", (i + 1) * 10, v[i]);
		}
	}
}

void main() {
	int unidadesVendedor[VEND], vendidasMaisCem[MERC], maiorQuantVenda[VEND], codMaisVendidaVendedor[VEND], codigosMerc[MERC];
	float valorUnitMedio[VEND], valorTotalVend[VEND], precosMercadorias[MERC], *maiorUnit, maior = 0;
	maiorUnit = &maior;

	preencheZero(unidadesVendedor, VEND);
	preencheZeroF(valorTotalVend, VEND);
	preencheZero(vendidasMaisCem, MERC);
	preencheZeroF(valorUnitMedio, VEND);
	preencheZero(codMaisVendidaVendedor, VEND);
	preencheZero(maiorQuantVenda, VEND);

	precoMercadorias(precosMercadorias, codigosMerc);
	preencheVenda(valorTotalVend, unidadesVendedor, precosMercadorias, vendidasMaisCem, maiorQuantVenda, codMaisVendidaVendedor, codigosMerc);
	valorUnitarioVendedor(valorTotalVend, unidadesVendedor, valorUnitMedio, maiorUnit);
	maioresVendedores(valorUnitMedio, maiorUnit);
	exibeMaisCem(vendidasMaisCem, codigosMerc);
	exibeMaisVendida(codMaisVendidaVendedor);

	printf("\n\n");

}