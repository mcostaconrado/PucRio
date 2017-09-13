#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <random>
#include <assert.h>
#include "functions.h"

using namespace std;

void CalculateNorm(double* x, int sizeX, double* ret) { //ok
	double sum = 0;

	for (int i = 0; i < sizeX; i++) {
		sum += pow(x[i], 2);
	}
	*ret = sqrt(sum);
}

double* Projection_Symmetric(double* x, int sizeX) {
	double aux;
	double  *ret;
	ret = new double[sizeX + 1];
	assert(ret != NULL);

	for (int i = 0; i < sizeX; i++) {
		ret[i] = x[i];
	}

	CalculateNorm(x, sizeX, &aux);
	ret[sizeX] = sqrt(1 - pow(aux, 2));
	return ret;
}


double* Projection_Asymmetric1(double* x, int sizeX) {
	double aux;
	double *ret = new double[sizeX + 2];
	assert(ret != NULL);

	for (int i = 0; i < sizeX; i++) {
		ret[i] = x[i];
	}
	CalculateNorm(x, sizeX, &aux);
	aux = pow(aux, 2);
	ret[sizeX] = sqrt(1 - aux);
	ret[sizeX + 1] = 0;
	return ret;
}

double* Projection_Asymmetric2(double* x, int sizeX) {
	double aux;
	double *ret = new double[sizeX + 2];
	assert(ret != NULL);

	for (int i = 0; i < sizeX; i++) {
		ret[i] = x[i];
	}
	CalculateNorm(x, sizeX, &aux);
	aux = pow(aux, 2);
	ret[sizeX] = 0;
	ret[sizeX + 1] = sqrt(1 - aux);
	return ret;
}


/*void GetSphericalRandomVector_Alpha(int sizeAlpha, double* ret) {
	ret = (double*)malloc(sizeAlpha * sizeof(double));

	for (int i = 0; i < sizeAlpha; i++) {
	//	ret[i] = normal_distribution(0, 1);
	}
}*/

void InnerProduct(double* x, double* y, int sizeXY, double* ret) {
	*ret = 0;
	for (int i = 0; i < sizeXY; i++) {
		*ret = *ret+x[i] * y[i];
	}
}

void Sign(double x, double* ret) {
	if (x >= 0) 
		*ret = 1;
	else
		*ret = -1;
}

void Sign01(double x, double* ret) {
	if (x >= 0)
		*ret = 1;
	else 
		*ret = 0;
}