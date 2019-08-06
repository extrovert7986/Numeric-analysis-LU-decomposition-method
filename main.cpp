
#include<stdio.h>
#include<stdlib.h>
#include"LU_decomposition.h"

const int N = 3;

void main() {
	double** A = (double**)malloc(N*sizeof(double*));
	for (int i = 0; i < N; i++)A[i] = (double*)calloc(N , sizeof(double));
	A[0][0] = 2; A[0][1] = 8;  A[0][2] = 9;
	A[1][0] = 4; A[1][1] = 19; A[1][2] = 17;
	A[2][0] = 0; A[2][1] = -3; A[2][2] = 5;
	
	double** r = LU_decomposition_Doolittle_method(A, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%lf ", r[i][j]);
		}
		printf("\n");
	}
	system("pause");
}