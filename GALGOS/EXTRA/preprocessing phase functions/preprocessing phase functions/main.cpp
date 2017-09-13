#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <assert.h>

#define sizeX 10
#define sizeY 10
#define sizeZ 3
#define pattCoordX 3
#define pattCoordY 3
#define pattSizeX 4
#define pattSizeY 4
#define BIGGEST_WEIGHT_EVER 9

using namespace std;

int ** CreateCanonicalBase(int sZ) {
	int** canonicalBase = new int*[2 * sZ + 1];

	for (int i = 0; i < 2 * sZ + 1; i++)
		canonicalBase[i] = new int[sZ];

	
	for (int j = 0; j < sZ; j++) {
		canonicalBase[0][j] = 0;
	}

	
	for (int i = 1; i <= sZ; i++) {
		for (int j = 0; j < sZ; j++) {
			canonicalBase[i][j] = 0;
			canonicalBase[i][i-1] = 1;
		}
	}

	
	for (int i = sZ + 1; i < 2 * sZ + 1; i++) {
		for (int j = 0; j < sZ; j++) {
			canonicalBase[i][j] = 0;
			canonicalBase[i][i-sZ-1] = BIGGEST_WEIGHT_EVER;
		}
	}

	return canonicalBase;
}

int*** ConvertTo3DRepresentation(int** mat2D, int sX, int sY, int sZ) {
	int** canonicalBase = CreateCanonicalBase(sZ);
	int*** mat3D = new int**[sX];
	 
	for (int i = 0; i < sX; i++) {
		mat3D[i] = new int*[sY];
		for (int j = 0; j < sY; j++) {
			mat3D[i][j] = new int[sZ];
		}
	}

	for (int i = 0; i < sX; i++) {
		for (int j = 0; j < sY; j++) {
			mat3D[i][j] = canonicalBase[mat2D[i][j]];
		}
	}

	return mat3D;
}

int *** GetPatternFromTI(int *** matrix3D, int coordX, int coordY, int patSizeX, int patSizeY) {
	int auxX = coordX, auxY = coordY;
	int*** pattern = new int**[patSizeX];

	for (int i = 0; i < patSizeX; i++) {
		pattern[i] = new int*[patSizeY];
		for (int j = 0; j < patSizeY; j++) {
			pattern[i][j] = new int[sizeZ];
		}
	}

	for (int i = 0; i < patSizeX; i++) {
		auxY = coordY;
		for (int j = 0; j < patSizeY; j++) { 
			pattern[i][j] = matrix3D[auxX][auxY];
			auxY++;
		}
		auxX++;
	} 

	return pattern;
}

double* ConvertMatrix2DIntoVector(int **matrix2D, int sX, int sY) {
	int arrSize = sX*sY, aux=0;
	double *arr = new double[arrSize];

	for (int i = 0; i < sX; i++) {
		for (int j = 0; j < sY; j++) {
				arr[aux] = double(matrix2D[i][j]);
				aux++;
			}
		}

	return arr;
}

double* ConvertMatrix3DIntoVector(int ***matrix3D, int sX, int sY, int sZ) {
	int arrSize = sX*sY*sZ, aux = 0;
	double *arr = new double[arrSize];

	for (int i = 0; i < sX; i++) {
		for (int j = 0; j < sY; j++) {
			for (int k = 0; k < sZ; k++) {
				arr[aux] = double(matrix3D[i][j][k]);
				aux++;
			}
		}
	}

	return arr;
}


void main() {
	
	// teste da matriz canonica
	/* 
	int** mat2D = CreateCanonicalBase(sizeZ);

	for (int i = 0; i < 2 * sizeZ + 1; i++){
		for (int j = 0; j <sizeZ; j++) {
			cout << mat2D[i][j] << " ";
		}
		cout << endl;
	}

	*/

	double *arr3D, *arr2D;
	int*** mat3D;
	int*** pattern;
	int **mat2D;

	mat2D = new int*[sizeX];

	for (int i = 0; i < sizeX; i++) {
		mat2D[i] = new int[sizeY];
	}

	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizeY; j++) {
			mat2D[i][j] = rand() % (sizeZ * 2 + 1);
			cout << mat2D[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl << endl;

	arr2D = ConvertMatrix2DIntoVector(mat2D, sizeX, sizeY);

	for (int i = 0; i < sizeX*sizeY; i++) {
		cout << arr2D[i] << " ";
	}

	cout << endl << endl << endl;

	mat3D = ConvertTo3DRepresentation(mat2D, sizeX, sizeY, sizeZ);	

	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizeY; j++) {
			for (int k = 0; k < sizeZ; k++) {
				cout << mat3D[i][j][k]  << " ";
			}
			cout << "   ";
		}
		cout << endl;
	}

	cout << endl << endl;

	arr3D = ConvertMatrix3DIntoVector(mat3D, sizeX, sizeY, sizeZ);

	for (int i = 0; i < sizeX*sizeY*sizeZ; i++) {
		cout << arr3D[i] << " ";
	}

	pattern = GetPatternFromTI(mat3D, pattCoordX, pattCoordY, pattSizeX, pattSizeY);

	cout << endl << endl << endl;

	for (int i = 0; i < pattSizeX; i++) {
		for (int j = 0; j < pattSizeY; j++) {
			for (int k = 0; k < sizeZ; k++) {
				cout << pattern[i][j][k] << " ";
			}
			cout << "   ";
		}
		cout << endl;
	}
}