#include <stdio.h>
#include <stdlib.h>
#define MAX 50
#define ENCAD 10

int lePrecos(int arr[], float mat[][5]) {
	char tipo;
	int i=0;
	float p0, p1, p2, p3, p4;
	FILE *precos;
	precos = fopen("ENCADERNACAO.TXT", "r");

	if (precos == NULL) {
		printf("\n\nERRO AO ABRIR ARQUIVO DE PRECOS DE ENCADERNACAO\n\n");
		exit(-1);
	}

	while (fscanf(precos, " %c %f %f %f %f %f", &tipo, &p0, &p1, &p2, &p3, &p4) == 6 ) {
		arr[i] = tipo;
		mat[i][0] = p0;
		mat[i][1] = p1;
		mat[i][2] = p2;
		mat[i][3] = p3;
		mat[i][4] = p4;
		i++;
	}
	return i;
	fclose(precos);
}

void processaPedidos() {
	FILE *pedidos;
	pedidos = fopen("PEDIDOS.TXT", "r");

	if (pedidos == NULL) {
		printf("\n\nERRO NA ABERTURA DO ARQUIVO DE PEDIDOS\n\n");
		exit(-1);
	}



}



void main() {
	int quant, i, j, tiposEncad[ENCAD];
	float precosEncad[MAX][5];

	quant = lePrecos(tiposEncad, precosEncad);


	for (i = 0; i < quant; i++) {
			printf("\n%c ", tiposEncad[i]);
		for (j = 0; j < 5; j++) {
			printf("%10.2f ", precosEncad[i][j]);
		}
	}
	printf("\n\n");
}