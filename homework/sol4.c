#include <stdio.h>

/*
This function prints out all elements in a matrix A
nr, number of rows in A
nc, number of columns in A
A, the matrix to be printed out.
*/
void print_matrix(int nr, int nc, double A[nr][nc]){
    //TODO: Write your code below
    for(int i = 0; i < nr; i++){
        for(int j = 0; j < nc; j++){
            printf("%.2f ", A[i][j]);
        }
        printf("\n");
    }
}

/*
This function carries out matrix multiplication C = A*B
nrowA, number of rows in A, 
ncolA, number of columns in A, 
...
A[nrowA][ncolA], matrix A
B[nrowB][ncolB], matrix B
C[nrowA][ncolB], outcome matrix C. 
*/
void mult(int nrowA, int ncolA, int nrowB, int ncolB, 
              double A[nrowA][ncolA], 
              double B[nrowB][ncolB], 
              double C[nrowA][ncolB]){

    for(int i = 0; i < nrowA; i++){
        for(int j = 0; j < ncolB; j++){
            C[i][j] = 0;
            for(int k = 0; k < ncolA; k++){
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
}

/*
This function flattens a 2D array A into a 1D array a_f. 
nr: number of rows in A
nc: number of columns in A
A: the 2D array
a_f: the 1D array that stores the flattened outcome. 
*/
void flatten(int nr, int nc, double A[nr][nc], double a_f[]){
    //TODO: Write your code below
    for(int i = 0; i< nr; i++){
        for(int j = 0; j < nc; j++){
            a_f[i*nc + j] = A[i][j];
        }
    }
}

/*
This function retrieves the value from a flattened 1D array 
as if it retrieves the value from an unflattened 2D array
*/
double get_elem(int nc, double a_f[], int i, int j){
    //TODO: Write your code below
    return a_f[i*nc+j];
}

void main(){
    printf("homework 1 ----------\n");
    double A[2][2] = {{1,2},{3,4}};
    print_matrix(2,2,A);

    printf("homework 2 ----------\n");
    double B[2][3] = {{5,6,7},{8,9,10}};
    double C[2][3] = {{0,0,0},{0,0,0}};

    mult(2,2,2,3,A,B,C);
    print_matrix(2,3,C);

    printf("homework 3 ----------\n");
    double a_f[2*3] = {0,0,0,0,0,0};

    flatten(2, 3, B, a_f);
    for (int i = 0; i < 6; i++)
    {
        printf("%f\n", a_f[i]);
    }
    
    printf("homework 4 ----------\n");
    printf("%f\n", get_elem(3,a_f,0,1));
}