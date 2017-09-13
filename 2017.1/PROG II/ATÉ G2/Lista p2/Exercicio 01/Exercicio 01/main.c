#include <stdio.h>	
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void ordena(int *v) {
	int i, j, trocou=1;
	int aux;
	while (trocou){
		for (i = 0, j = 1; i < j && v[j] != -1; j++, i++) {
			trocou = 0;
			if (v[i] > v[j]) {
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;
				trocou = 1;
			}
		}	
	}
}

void ordena_vetor_ponteiros(int **v){
	int i;
	for (i = 0; v[i] != NULL; i++) {
		ordena(v[i]);
	}
}

void imprime_vetor_ponteiros(int **v) {
	int i, j;
	for (i = 0; v[i] != NULL; i++) {
		printf("\n");
		for (j = 0; v[i][j] != -1; j++) {
			printf("%i ", v[i][j]);
		}
		printf("\n");
	}
}

int busca(int *v, int x) {
	for (int i = 0; v[i] < x; i++)
		if (v[i] == x)
			return 1;
	return 0;
}

int *interseccao(int **v) {
	int i, j;
	int atual;
	int v[];

	for (i = 1; v[i] != NULL; i++) {
		atual = v[0][i-1];
		for (j = 0; v[i][j] != -1; j++) {
			busca(v[i], atual)
	}

}




void main() {
	int v1[] = { 0, 2, 1, 10, 4, 9, -1 };
	int v2[] = { 0,3,4,2, 9, 5, -1 };
	int v3[] = { 1, 3, 2, 5, 6, 10, -1 };
	int *v[] = { &v1, &v2, &v3, NULL };


	imprime_vetor_ponteiros(v);
	ordena_vetor_ponteiros(v);
	imprime_vetor_ponteiros(v);


}