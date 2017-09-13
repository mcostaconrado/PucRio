#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi 3.14159265
#define SIZE 100

void calc_circulo(double r, double *circ, double *area) {
	*area = pi*r*r;
	*circ = 2 * pi*r;
}

int calc_raizes(double a, double b, double c, double *x1, double *x2) {
	double delta;
	delta = b*b - 4 * a*c;

	if (delta >= 0) {
		if (delta == 0) {
			*x1 = -b / (2 * a);
			*x2 = *x1;
			return 1;
		}

		*x1 = (-b + sqrt(delta)) / (2 * a);
		*x2 = (-b - sqrt(delta)) / (2 * a);
		return 2;
	}

	return 0;
}


void obtem_maior_menor(int v[], int n, int *maior, int *menor) {
	int i;
	*maior = v[0], *menor = *maior;

	for (i = 1; i < n; i++) {
		v[i] > *maior ? *maior = v[i] : v[i] < *menor ? *menor = v[i]:0;
	}
}

double obtem_maior( double M[][3], int *i, int*j) {
	int k, l;
	double maior = M[0][0];
	*i = 0; *j = 0;

	for (k = 0; k < 3; k++) {
		for (l = 0; l < 3; l++) {
			if (M[k][l] > maior); {
				maior = M[k][l];
				*i = k;
				*j = l;
			}
		}
	}
	return maior;
}


void main() {
	double M[][3] = { {1,2,3}, {4,5,6}, {7,8,1} };
	int a, b;
	double c;

	c = obtem_maior(M, &a, &b);
	printf("%f, %d, %d", c, a, b);

}