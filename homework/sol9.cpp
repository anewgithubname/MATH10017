#include <stdio.h>
#include <stdlib.h>

int random_number(){
    return rand() % 10;
}

class Matrix{
    int numrow;
    int numcol; 

    /* takes 2D matrix index i, j 
       convert it to a linearized index. 
       for example, 1,3 is converted to 1*numcol + 3.  
     */
    int idx(int i, int j) {
        return i*numcol + j;
    }

    float *elements;

public:
    /* Fill the matrix with a flattened matrix, stored in an array. 
    * nrow, number of rows
    * ncol, number of columns
    */
    void fill(int nrow, int ncol, float a[]){
        numrow = nrow;
        numcol = ncol;
        elements = (float*) malloc(numrow*numcol*sizeof(float));
        for(int i=0; i<numrow*numcol; i++)
            elements[i] = a[i];
    }

    int get_numrow() {
        return numrow;
    }

    int get_numcol() {
        return numcol;
    }

    /* Initialize the matrix with random values from 0-10
    nrow: input, number of rows
    ncol: input, number of cols;
    */
    void rand(int nrow, int ncol){
        // assign the fields
        numrow = nrow;
        numcol = ncol;
        //allocate space for the matrix
        elements = (float*) calloc(numrow*numcol, sizeof(float));
        //fill it with random numbers
        for (int i = 0; i < numrow; i++){
            for (int j = 0; j < numcol; j++){
                elements[idx(i,j)] = random_number();
            }
        }
    }
    /* Initialize the matrix with zeros.
    nrow: input, number of rows
    ncol: input, number of cols;
    */
    void zeros(int nrow, int ncol){
        // assign the fields
        numrow = nrow;
        numcol = ncol;
        // allocate memory space and fill it with zeros
        elements = (float*) calloc(numrow*numcol, sizeof(float));
    }

    // get i,j -th element 
    float get(int i, int j) {
        return elements[idx(i,j)];
    }

    // set i,j -th element
    void set(int i, int j, float val){
        elements[idx(i,j)] = val;
    }

    /*
    Print the matrix, %.3f for each element. 
    */
    void print(){
        for (int i = 0; i < numrow; i++)
        {
            for (int j = 0; j < numcol; j++)
            {
                printf("%.3f ", get(i,j));
            }
            printf("\n");
        }
    }

    /*
    Compute matrix multiplication C = AB, where A is the current matrix. 
    B: the other matrix
    return: C 
    */
    Matrix dot(Matrix B){
        Matrix C; C.zeros(numrow, B.numcol);
        
        if(numcol != B.numrow){
            printf("Error: Matrix dimensions do not match.\n");
            return C;
        }
        
        for (int i = 0; i < numrow; i++)
        {   
            for (int j = 0; j < B.numcol; j++)
            {
                //compute i,j-th element 
                float s = 0;
                for (int k = 0; k < numcol; k++)
                {
                    s += get(i,k) * B.get(k,j);
                }
                C.set(i,j, s); 
            }   
        }
        return C; 
    }

    /*
        Free up the memory allocated by zeros, or rand. 
    */
    void free_mem(){
        free(elements);
    }

};

int main(){
    //elements we will put in the matrices. 
    //note the line breaking does NOT matter here. They are both 1D arrays. 
    float a[6] = {1,2,3,
                  4,5,6};
    float b[6] = {1,2,
                  3,4,
                  5,6};

    //Create and print two matrices
    Matrix A; 
    A.fill(2,3, a);
    printf("Matrix A:\n");
    A.print();

    printf("\n");

    Matrix B; 
    B.fill(3,2,b);
    printf("Matrix B:\n");
    B.print();

    printf("\n");

    //compute C = AB
    Matrix C = A.dot(B);
    printf("Matrix C = A*B:\n");
    C.print();

    printf("\n");

    // DO NOT FORGET TO FREE UP MEMORY!!
    A.free_mem();
    B.free_mem();
    C.free_mem();
}