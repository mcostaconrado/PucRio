#include <stdio.h>
#include <stdlib.h>
#define FACES 6
#define cls system("cls")

/*void ler(int *notafinal,  int *anuladas) {
	int i, nota;
	*notafinal = 0; *anuladas = 0;
	for (i = 0; i < QUEST; i++) {
		printf("\nInforme a nota da questao %d: ", i+1);
		scanf_s("%d", &nota);
		if (nota == 1) {
			*notafinal += 2;
		}
		else if(nota == 2){
			*notafinal += 5;
		}
		else if (nota == 3) {
			*notafinal += 10;
		}
		else {
			*anuladas +=1;
		}
		//cls;
	}
	//cls;
}

void main() {
	int notafinal, anuladas, cod, cod2;

	printf("Insira o codigo do passageiro: \n\n\t-> ");
	scanf_s("%d", &cod);
	while (cod != 0) {

		ler(&notafinal, &anuladas);
	
		printf("\nRESUMO DO PASSAGEIRO %d:", cod);
		printf("\n\nNOTA FINAL: %d", notafinal);
		printf("\n\nANULADAS: %d", anuladas);
		printf("\n\nInsira um numero para continuar: ");
		scanf_s("%d", &cod2);
		cls; 

		printf("Insira o codigo do passageiro: \n\n\t-> ");
		scanf_s("%d", &cod);
	}
	printf("\n\n\n\n");
}
*/

void zera(int n, int v[]) {
	int i;
	for (i= 0; i < n; i++) {
		v[i] = 0;
	}
}

int ocorr(int n, int v[]) {
	int face, tot=0;
	printf("Informe a face retirada: ");
	scanf_s("%d", &face);
	while (face > 0 && face <= FACES) {
		v[face - 1] += 1;
		tot++;
		printf("Informe a face retirada: ");
		scanf_s("%d", &face);
	}
	cls;
	return tot;
}

void exibe(int n, int v[], int lancamentos) {
	int i, facesv[FACES], viciados = 0;
	for (i = 0; i < n; i++){
		if (v[i] / lancamentos <= .15 || v[i] / lancamentos >= .18) {
			facesv[viciados] = i + 1;
			viciados++;
		}
	}
	if (viciados == 0) {
		printf("DADO NAO VICIADO");
	}
	else{
		printf("FACES VICIADAS: ");
		for (i = 0; i < viciados; i++) {
			printf(" %d ", facesv[i]);
		}
	}
}

void main() {
	int total;
	int i;
	int ocorrencias[FACES];
	zera (FACES, ocorrencias);
	total = ocorr(FACES, ocorrencias);

	exibe(FACES, ocorrencias, total);

}