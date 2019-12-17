//Anthony Porporino
//260863300
//COMP206 Assignment 4

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

//define constants
#define SIZE 101
#define ROWS 5
#define COLS 5

void fillMatrix(int matrix[ROWS][COLS]);

void printMatrix(int matrix[ROWS][COLS]);

void transposeMatrix(int matrix[ROWS][COLS]);

void multiplyMatrix(int m1[2][COLS],
               int m2[ROWS][COLS],
             int resultMatrix[ROWS][COLS]);

int main() {
    int matrix[ROWS][COLS];

    fillMatrix(matrix);
    printMatrix(matrix);

    transposeMatrix(matrix);
    printMatrix(matrix);

    int matrix2[2][COLS]={0,1,2,3,4,5,6,7,8,9};
    int matrixResult[ROWS][COLS];

    multiplyMatrix(matrix2, matrix, matrixResult);
    printMatrix(matrixResult);

    return 0;
}

/*This method will randomly fill a ROWS by COLS matrix*/
void fillMatrix(int matrix[ROWS][COLS]){

	sleep(1);				//sleep for 1 second so time is different when script runs program
	srand(time(NULL)); 		// randomize seed with time now
	//enter loop
	for (int i=0; i<ROWS; i++){
		for (int j=0; j<COLS; j++){
			//do rand % SIZE so that random number is always between 1 and 100
			matrix[i][j] = rand() %SIZE;
		}
	}
}

/*This method will print a ROWS by COLS matrix*/
void printMatrix(int matrix[ROWS][COLS]){
	for (int i=0; i<ROWS; i++){
		for (int j=0; j<COLS; j++){
			//print each element in matrix
			printf("%d		",matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/*This method will transpose the inputed matrix*/
void transposeMatrix(int matrix[ROWS][COLS]){
	//matrix[i][j] = *(*(matrix + i) + j)
	for (int i=0; i<ROWS; i++){

		for (int j=i; j<COLS; j++){	// key is that j=i because do not want to change the value of columns that have just been changed
			//temporary storage of int
			int temp = *(*(matrix + i) + j);
			*(*(matrix + i) + j) = *(*(matrix + j) + i);
			*(*(matrix + j) + i) = temp;
		}
	}
}

/*This matrix will multiply the first two matrix inputs and store result in last matrix input*/
void multiplyMatrix(int m1[2][COLS],
               int m2[ROWS][COLS],
             int resultMatrix[ROWS][COLS]){

	for (int i=0; i<2; i++){
		for (int j=0; j<COLS; j++){
			resultMatrix[i][j] = 0;
			for (int a=0; a<COLS; a++){
				//result matrix is sum of rows*columns
				resultMatrix[i][j] += (m1[i][a]*m2[a][j]);
			}
		}
	}
	//fill the rest of matrix with 0's because we are not sure what is in them
	for (int i =2; i < 5; i++){
		for (int j = 0; j <5; j++){
			resultMatrix[i][j] = 0;
		}
	}
}

