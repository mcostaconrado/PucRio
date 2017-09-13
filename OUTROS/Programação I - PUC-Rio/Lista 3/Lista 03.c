#include <stdio.h>
#include <math.h>

#define PI 3.1415

//FUNÇÕES

// QUESTÕES DE PROVA

// QUESTÃO 1

/* 
double vazaoRio (double largura, double profundidade, double velocidade){
	double vazao;
	vazao = largura*largura*profundidade*velocidade;
	return vazao;	
}

double notaRio(double largura, double profundidade, double velocidade){
	double nota, vazao;
	vazao = vazaoRio(largura, profundidade, velocidade);
	if (largura < 15 || profundidade < 6){
		nota = 0;
	}
	else if (largura <= 30){
		if ( vazao < 5000){
			nota = 5 + vazao/2700;
		}
		else{
			nota = 5 + vazao/2500;
		}
	}
	else{
		nota = 5 + vazao / 2000;
	}
	return nota;
}
*/


void main(void){

	// EXERCÍCIOS

	// MAIN DA 1

	/*

	int cor;
	double distancia;

	printf("\nInforme a cor do sinal (1 para vermelho, 2 para amarelo ou 3 para verde): ");
	scanf_s("%i", &cor);
	

	if (cor == 1){
		printf("\n\nPare!\n\n");
	}
	else if (cor == 2){
		printf("\n\nInsira a distancia do cruzamento: ");
		scanf_s("%lf", &distancia);
		if (distancia <= 5){
			printf("\n\nPare!\n\n");
		}
		else {
			printf("\n\nPasse com cuidado!\n\n");
		}
	}
	else if (cor == 3){
		printf("\n\nPasse!\n\n");
	}
	
	*/

	//MAIN DA 2

	/*

	double indice;
	printf("\nInsira o indice de poluicao: ");
	scanf_s("%lf", &indice);

	if (indice >= 0.5) {
		printf("\n\nAs industrias de todos os grupos devem suspender suas atividades!\n\n");
	}
	else if (indice >= 0.4){
		printf("\n\nAs industrias do 1 e 2 grupos devem parar as atividades!\n\n");
	}
	else if (indice  >= 0.3){
		printf("\n\nAs empresas do 1 grupo devem parar as atividades!\n\n");
	}

	*/

	//EXERCÍCIOS DE PROVA!!

	//1

	/*
	double profundidade, largura, velocidade, vazao;
	double nota;

	printf("\nInsira, respectivamente, a profundidade e a largura do rio, em metros:\n->");
	scanf_s("%lf %lf", &profundidade, &largura);
	printf("\n\nInsira a velocidade do rio, em litros por segundo:\n->");
	scanf_s("%lf", &velocidade);

	nota = notaRio(largura, profundidade, velocidade);

	printf("\n\nO rio tem nota %.1lf.\n\n", nota);
	if (nota >= 7){
		printf("Alternativa viavel!");
	}*/

	// 2:

	int codigo, quantidade, tipo, subtipo;
	double custo, venda;
	printf("\nInforme o codigo do produto:\n-> ");
	scanf_s("%d", &codigo);
	printf("\n\nInforme a quantidade em estoque:\n-> ");
	scanf_s("%d", &quantidade);

	if (codigo % 2 == 0) {
		custo = quantidade*codigo*0.15;
	}
	else {
		custo = quantidade*codigo*0.04;
	}


	if (codigo > 1000 && codigo < 1999) {
		tipo = 1;
		printf("Informe qual o tipo de alimento (1- Carnes, 2- Laticinios, 3- Verduras)\n-> ");
		scanf_s("%d", &subtipo);
		if (subtipo == 1) {
			venda = custo*1.1;
		}
		else if (subtipo == 2) {
			venda = custo*1.2;
		}
		else if (subtipo == 3) {
			venda = custo*1.08;
		}
	}
	else if (codigo > 2000 && codigo < 2999) {
		tipo = 2;
		venda = custo*1.3;
	}


	printf("\n\nO valor de custo total e de R$%.2lf", custo);

	if (quantidade > 100) {
		venda *= .95;
		printf("\n\nDesconto: R$%.2lf", venda*.05);
	}

	printf("\n\nO valor de venda total e de R$%.2lf\n\n", venda);
}