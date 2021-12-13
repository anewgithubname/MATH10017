#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

struct matrix
{
    int numrow;
    int numcol;
    int *elements;
};
typedef struct matrix Matrix;

// pass by value, WON'T work!!!
void zeros_1(Matrix m){
    m.numrow = 2;
    m.numcol = 2;
    m.elements = calloc(m.numrow * m.numcol, sizeof(int));
}

// pass by reference, works! 
void zeros_2(Matrix *pm){
    pm->numrow = 2;
    pm->numcol = 2;
    pm->elements = calloc(pm->numrow * pm->numcol, sizeof(int));
}

void print_matrix(Matrix m){
    int i, j;
    for (i = 0; i < m.numrow; i++)
    {
        for (j = 0; j < m.numcol; j++)
        {
            printf("%d ", m.elements[i * m.numcol + j]);
        }
        printf("\n");
    }
}

void main(){
    Matrix m1 = {2, 2, calloc(2 * 2, sizeof(int))}; 
    print_matrix(m1); //OK! This is how we did it in Lab 7. 

    printf("---- another way to initialize the matrix ---- \n");
   Matrix m2;
    // zeros_1(m2);
    // print_matrix(m2); 
    // if you run the above two lines, your progam crashes! 
    // zeros_1 function modifies only a copy of m2 created inside of zeros_1.
    // m2 in the main function is not modified, hence contains garbage values.
    
    zeros_2(&m2); //OK! This is not how we initialize the matrix in Lab 7, but it is OK. 
    print_matrix(m2); 

    free(m1.elements);
    free(m2.elements);
}