#include <stdio.h>
#include <stdlib.h>
#include "debugmalloc.h"

typedef struct Matrix{
	int szeles;
	int magas;
	int** adat;
}Matrix;

void nullaz(Matrix* matrix){
	for (int i = 0; i < matrix->magas; i++){
		for (int j = 0; j < matrix->szeles; j++){
			matrix->adat[i][j] = 0;
		}
	}
}

Matrix beolvas(char* fileName){
	FILE* file = fopen(fileName, "r");
	Matrix matrix = {0,0,NULL};
	fscanf(file, "%d %d", &matrix.szeles, &matrix.magas);
	matrix.adat = malloc(sizeof(int*)*matrix.magas);
	for (int i = 0; i < matrix.magas; i++){
		matrix.adat[i] = malloc(sizeof(int)*matrix.szeles);
	}
	for (int i = 0; i < matrix.magas; i++){
		for (int k = 0; k < matrix.szeles; k++){
			fscanf(file, "%d", &matrix.adat[i][k]);
		}
	}
	return matrix;
}

void free_Matrix(Matrix matrix){
	for (int i = 0; i < matrix.magas; i++){
		free(matrix.adat[i]);
	}
	free(matrix.adat);
}

int main(){
	Matrix matrix = beolvas("test.txt");
	for (int i = 0; i < matrix.magas; i++){
		for (int k = 0; k < matrix.szeles; k++){
			printf("%d", matrix.adat[i][k]);
		}
	}
	free_Matrix(matrix);	
	return 0;
}
