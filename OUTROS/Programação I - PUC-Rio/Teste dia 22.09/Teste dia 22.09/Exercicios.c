#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846264338327950288419716939937510

//FUNÇÕES:

// NÚMERO 2
/*
double calcDesc(double valor, double percentual) {
	double desconto;
	desconto = valor*percentual / 100;
	return desconto;
}
*/

// NÚMERO 6
/*
double areaRet (double alt, double comp){
	double area;
	area = alt*comp;
	return area;
}

double areaCirc(double r){
	double area;
	area = PI*r*r;
	return area;
}

double areaCil(double r, double h){
	double area, compCirc;
	compCirc = 2*PI*r;
	area = 2*areaCirc(r) + areaRet(h, compCirc);
	return area;
}*/

// NÚMERO 8
/*
double calculaCiclo(int diasNasc, int diasCiclo) {
	double amplitude;
	amplitude = sin(2 * PI * diasNasc / diasCiclo);
	return amplitude;
}

void ciclosMensagens(double fisico, double emocional, double intelectual) {
	double F, E, I;
	F = round(fisico * 100); 
	E = round(emocional * 100);
	I = round(intelectual * 100);
	printf("\n\nF:%.0lf%%  E:%.0lf%%  I:%.0lf%%", F, E, I);
	if (F <= 0) {
		printf("\n\nALERTA PARA O CICLO FISICO!!!");
	}
	if (E <= 0) {
		printf("\n\nALERTA PARA O CICLO EMOCIONAL!!!");
	}
	if (I <= 0) {
		printf("\n\nALERTA PARA O CICLO INTELECTUAL!!!");
	}
	return;
}

int diasJulianos(int dd, int mm, int aaaa) {
	int A, B, C, D, E;
	int dia, mes, ano;
	dia = dd;
	mes = mm;
	ano = aaaa;
	double juliano;
	if (mes < 3) {
		ano = aaaa - 1;
		mes = mm + 12;
	}
	A = ano / 100;
	B = A / 4;
	C = 2 - A + B;
	D = (int) (365.25*(ano + 4716));
	E = (int) (30.6001 * (mes + 1));
	juliano = D + E + dia + 0.5 + C - 1524.5;
	return juliano;
}
*/

//NÚMERO 9
/*
NÃO TEM FUNÇÕES
*/

// NÚMERO 10


int main(void){
	//MAIN DA 2
	/*
	double montante, precoUnidade, valorAtual, porcentagem;
	int unidades;

	printf("\nInforme o valor de cada unidade: R$");
	scanf("%lf", &precoUnidade);
	printf("\nInforme quantas unidades foram compradas: ");
	scanf("%d", &unidades);

	montante = precoUnidade*unidades;
	valorAtual = montante;

	if (unidades > 15) {
		valorAtual -= calcDesc(valorAtual, 10);
	}
	if (montante > 100) {
		valorAtual -= calcDesc(valorAtual, 20);
	}

	if (valorAtual == montante) {
		printf("\n\nValor total da compra: R$%.2lf.\n\n\n", valorAtual);
	}
	else {
		printf("\n\nValor total da compra: R$%.2lf.\nValor com o desconto: R$%.2lf.\n\n\n", montante, valorAtual);
	}
	return 0;
	*/

	//MAIN DA 6
	/* 
	double rd, h;
	double areaTanque, litros, latas, preco;

	printf("\nInforme, respectivamente, o raio e a altura do cilindro: ");
	scanf_s("%lf %lf", &rd, &h);

	areaTanque = areaCil(rd, h);

	litros = areaTanque/3;
	latas = ceil(litros/5);

	preco = latas*20;
	printf("\n\nSerao necessarias %.0lf latas, com total de R$%.2lf\n\n", latas, preco);

	return 0;
	*/

	//MAIN DA 8
	/*
	int dNasc, mNasc, aNasc;
	int dProva, mProva, aProva;
	int diasNasc;

	printf("Insira a data do seu nascimento (sem barras): ");
	scanf_s("%d %d %d", &dNasc, &mNasc, &aNasc);

	printf("Insira a data da prova (sem barras): ");
	scanf_s("%d %d %d", &dProva, &mProva, &aProva);

	diasNasc = diasJulianos(dNasc, mNasc, aNasc) - diasJulianos(dProva, mProva, aProva);

	ciclosMensagens(calculaCiclo(diasNasc, 23), calculaCiclo(diasNasc, 28), calculaCiclo(diasNasc, 33));
	printf("\n\n");
	return 0;
	*/

	//MAIN DA 9
	/*
	double prestacao, taxa, parcela;
	int atraso;
	taxa = 0;

	printf("\nInsira o valor da prestacao: R$");
	scanf_s("%lf", &prestacao);
	printf("\n\nInsira a quantidade de dias de atraso: ");
	scanf_s("%d", &atraso);

	if (atraso > 10) {
		printf("\n\nInsira a taxa de juros, em %%: ");
		scanf_s("%lf", &taxa);
	}

	parcela = prestacao + (prestacao * (taxa / 100) * atraso);

	printf("\n\nA parcela a ser paga tera valor de R$%.2lf.\n\n", parcela);
	*/

	//MAIN DA 10

}
