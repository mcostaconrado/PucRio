#include<stdlib.h>
#include <stdio.h>
#include <random>
#include <math.h>
#include <iostream>
#include "functions.h"
#define sizeX 2

using namespace std;

void main() {
	double x[sizeX] = { 0.4, 0.3 };
	double y[sizeX] = { 0.4, 0.3 };
	double *arr;
	double norm;
	int i;

	/*

	CalculateNorm(x, sizeX, &norm);
	cout << norm << endl;

	*/ //teste da funcao CalculateNorm().

	/*
	arr = Projection_Symmetric(x, 2);

	for (int i = 0; i <= sizeX; i++) {
		cout << arr[i] << " ";
	}
	*/ // teste da funcao Projectio_Symmetric().

	/* arr = Projection_Asymmetric1(x, sizeX);

	for (int i = 0; i <= sizeX + 1; i++) {
		cout << arr[i] << " ";
	}*/// teste da funcao Projection_Asymmetric1();

	/*arr = Projection_Asymmetric2(x, sizeX);

	for (int i = 0; i <= sizeX + 1; i++) {
		cout << arr[i] << " ";
	}*/ // teste da funcao Projection_Asymmetric2();

}

