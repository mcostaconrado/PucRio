#include <stdio.h>
#define seta printf("-> ");

float desconto(float montante, int bebidas, int pratos) {
	float final;
	int idade;
	final = montante;
	if (montante > 300) {
		final = final * 0.75;
	}
	else if (montante > 100) {
		printf("Insira sua idade:\n"); seta;
		scanf_s("%d", &idade);
		if (idade > 50) {
			final = final * 0.85;
		}
	}
	return final;
}

int vale(int montante, int bebidas, int pratos) {
	int desconto = 0;
	if (montante > 400) {
		desconto = 100;
	}
	else if (montante > 150) {
		if (pratos >= 3) {
			if (bebidas >= 6) {
				desconto = 50;
			}
			else {
				desconto = 30;
			}
		}
		else {
			if (bebidas >= 6) {
				desconto = 20;
			}
		}
	}
	else {
		if (bebidas != 0 && pratos != 0) {
			desconto = 10;
		}
	}
	return desconto;
}

int main() {
	int pratos, bebidas;
	float montante, desc, valeDesc;

	printf("Informe o valor da conta\n-> R$");
	scanf_s("%f", &montante);
	printf("Informe a quantidade de bebidas e de pratos, respectivamente:\n-> ");
	scanf_s("%d", &bebidas);
	seta;
	scanf_s("%d", &pratos);
	desc = 0;
	desc = desconto(montante, bebidas, pratos);
	valeDesc = vale(montante, bebidas, pratos);
	printf("vale desc %i desconto %f ", valeDesc, desc);
	printf("\nValor a pagar: R$%.2f\n", montante - desc );
	if (valeDesc != 0) {
		printf("\nVale desconto para a proxima compra: R$%d\n\n", valeDesc);
	}
}