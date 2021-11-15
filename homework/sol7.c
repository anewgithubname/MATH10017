#include <stdio.h>
#include <stdlib.h>

// TODO: define your matrix structure here.
/* syntax:
struct name{
    datatype variable1;
    datatype variable2;
    datatype variable3;
};
*/

struct matrix
{
    int numrow;
    int numcol;
    int transpose;
    int *elements;
};

// TODO: define Matrix an alias to your matrix structure.
// hint: typedef ...
typedef struct matrix Matrix;

/*
Takes 2D index i, j of a matrix M, return the linearized index
e.g. I have a 2D index 1,2 of a 3 by 4 matrix M, the linearized index should be 1*4+2 = 6
*/
int idx(int i, int j, Matrix M)
{
    if(M.transpose == 1){
        return j * M.numrow + i;
    }else{
        //TODO: write your code here
        return i * M.numcol + j;
    }
}

/*
Read a matrix from file.
filename: the file that contains the matrix.
*/
Matrix read_matrix(char *filename)
{
    FILE *f = fopen(filename, "rb");
    // read int variables to the file.
    int numrow = getw(f);
    int numcol = getw(f);
    Matrix M = {numrow, numcol, 0, calloc(numrow * numcol, sizeof(int))};

    // TODO: read the matrix from file.
    for (int i = 0; i < numrow; i++)
    {
        for (int j = 0; j < numcol; j++)
        {
            M.elements[idx(i, j, M)] = fgetc(f);
        }
    }

    // DO NOT FORGET!!
    fclose(f);

    // TODO: return the matrix you have just read from the file
    // return ???
    return M;
}

/*
Write matrix M to file
M: the matrix to be written
filename: name of the file to be created.
*/
void write_matrix(Matrix M, char *filename)
{
    FILE *f = fopen(filename, "wb");
    // write int variables to the file.
    putw(M.numrow, f);
    putw(M.numcol, f);

    // TODO: Write elements of the matrix to the file.
    for (int i = 0; i < M.numrow; i++)
    {
        for (int j = 0; j < M.numcol; j++)
        {
            fputc(M.elements[idx(i, j, M)], f);
        }
    }

    // DO NOT FORGET!!
    fclose(f);
}

/*
Computer matrix multiplication A*B, and store the result in C.
*/
void multiply(Matrix A, Matrix B, Matrix C)
{
    // TODO modify the matrix multiplication code you have written
    //  in lab 4, so that it works on matrix structures A, B and C

    // https://github.com/anewgithubname/MATH10017/blob/main/homework/sol4.c
    for (int i = 0; i < A.numrow; i++)
    {
        for (int j = 0; j < B.numcol; j++)
        {
            // C[i][j] = 0;
            C.elements[idx(i,j,C)]=0;
            for (int k = 0; k < A.numcol; k++)
            {
                //  C[i][j] = C[i][j] + A[i][k] * B[k][j];
                 C.elements[idx(i,j,C)] += 
                    A.elements[idx(i,k,A)] * B.elements[idx(k,j,B)];
            }
        }
    }
}

// Matrix transpose(Matrix M){
//     Matrix MT = {M.numcol, M.numrow, calloc(M.numcol * M.numrow, sizeof(int)) };

//     for (int i = 0; i < M.numrow; i++)
//     {
//         for (int j = 0; j < M.numcol; j++)
//         {
//             MT.elements[idx(j,i,MT)] = M.elements[idx(i,j,M)];
//         }
//     }
//     return MT;
// }

Matrix transpose(Matrix M){
    // Matrix MT = {M.numcol, M.numrow, calloc(M.numcol * M.numrow, sizeof(int)) };

    // for (int i = 0; i < M.numrow; i++)
    // {
    //     for (int j = 0; j < M.numcol; j++)
    //     {
    //         MT.elements[idx(j,i,MT)] = M.elements[idx(i,j,M)];
    //     }
    // }
    // return MT;

    Matrix MT = {M.numcol, M.numrow, 1, M.elements};
    return MT; 
}

// do not change
void print_matrix(Matrix A);
void fill_matrix(Matrix A);
int is_the_same(Matrix A, Matrix B);

void main()
{
    printf("------- testing matrix IO --------\n");
    Matrix A = read_matrix("A.matrix");
    write_matrix(A, "A0.matrix");
    Matrix A0 = read_matrix("A0.matrix");

    if (is_the_same(A, A0))
    {
        printf("Test OK!\n");
    }
    else
    {
        printf("Something is wrong with your IO code!\n");
    }
    // DO NOT FORGET!
    free(A.elements);
    free(A0.elements);

    printf("\n------- matrix multiplication --------\n");
    //TODO, read A and B from matrix files
    // compute C=A*B, and write C to a matrix file C.matrix 
    // using the functions you just wrote.
    A = read_matrix("A.matrix");
    Matrix AT = transpose(A);
    print_matrix(AT);printf("\n");
    
    Matrix B = read_matrix("B.matrix");
    print_matrix(B);printf("\n");

    Matrix C = {A.numrow, B.numcol, 0, calloc(A.numrow * B.numcol, sizeof(int))};

    multiply(AT,B,C);
    print_matrix(C);printf("\n");

    write_matrix(C, "C.matrix");
    free(A.elements);
    free(B.elements);
    free(C.elements);
}

// do not change.
void print_matrix(Matrix A)
{
    for (int i = 0; i < A.numrow; i++)
    {
        for (int j = 0; j < A.numcol; j++)
        {
            printf("%2d ", A.elements[idx(i, j, A)]);
        }
        printf("\n");
    }
}

void fill(Matrix A)
{
    for (int i = 0; i < A.numrow; i++)
    {
        for (int j = 0; j < A.numcol; j++)
        {
            A.elements[idx(i, j, A)] = i * A.numcol + j + 1;
        }
    }
}

int is_the_same(Matrix A, Matrix B)
{
    for (int i = 0; i < A.numrow; i++)
    {
        for (int j = 0; j < A.numcol; j++)
        {
            if (A.elements[idx(i, j, A)] != B.elements[idx(i, j, B)])
            {
                return 0;
            }
        }
    }
    return 1;
}