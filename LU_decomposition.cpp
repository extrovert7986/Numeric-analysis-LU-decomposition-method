/*
  This program decompose target matrix A into 
  2 matrices L and U by using Doolittle method.

  Input array of square matrix A
        size N of matrix A
  Output a matrix with form
    U11 U12 ... U1n
    L21 U22 ... U2n
  [  .  L32 ...  .  ]
     .   .       .
    Ln1 Ln2 ... Unn

  Where U** represents entry in upper matrix
  and   L** represents entry in lower matrix
*/

#include<stdio.h>
#include<stdlib.h>

double** LU_decomposition_Doolittle_method(double** A,int N) {
	//initialize
	double **output = (double**)malloc(N * sizeof(double*));
	for (int row = 0; row < N; row++)
		output[row] = (double*)calloc(N, sizeof(double));
	
	//Doolittle method
	double sum;
	for (int i = 0; i < N; i++) {
		//output[i][i] = 1.0;
		//compute i-th row
		for (int col = i; col < N; col++) {
			sum = 0.0;
			for (int j = 0; j < i; j++)sum += output[i][j] * output[j][col];
			output[i][col] = A[i][col] - sum;
		}
		for (int row = i + 1; row < N; row++) {
			sum = 0.0;
			for (int j = 0; j < i; j++)sum += output[row][j] * output[j][i];
			output[row][i] = (A[row][i] - sum) / output[i][i];
		}
	}

	return output;
}