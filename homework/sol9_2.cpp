#include <stdio.h>
#include <stdlib.h>

int random_number(){
    return rand() % 10;
}

// This is the class we have written in the last lab.
// Jump to the line 156 to write the assignment. 
class Matrix{

//NOTE: I have now declared our variables as protected.
//This means that they can be accessed by any class that inherits from this class.
protected:
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

    void read_matrix(char *filename)
    {
        FILE *f = fopen(filename, "rb");
        // read int variables to the file.
        int numrow = getw(f);
        int numcol = getw(f);
        
        zeros(numrow, numcol);
        // TODO: read the matrix from file.
        for (int i = 0; i < numrow; i++)
        {
            for (int j = 0; j < numcol; j++)
            {
                elements[idx(i, j)] = getc(f);
            }
        }

        // DO NOT FORGET!!
        fclose(f);
        printf("Matrix read from file %s\n", filename);
    }


    /*
        Free up the memory allocated by zeros, or rand. 
    */
    void free_mem(){
        free(elements);
    }
 
};

class Image: public Matrix{
public:
    int height() {
        //TODO: return the height of the image
        return numrow;
    }

    int width() {
        //TODO: return the width of the image
        return numcol;
    }

    void visualize(){
        //TODO: visualize the image by printing out the matrix.
        for (int i = 0; i < height(); i++)
        {
            for (int j = 0; j < width(); j++)
            {
                if( elements[idx(i,j)] < 85){
                    printf(" ");
                }else if(elements[idx(i,j)] >= 85 && elements[idx(i,j)] <= 170){
                    printf("I");
                }else{
                    printf("M");
                }
            }
            printf("\n");
        }
    }
};

int main(){
    Image img;
    // "read_matrix" function is defined in the Matrix class. 
    // As a child class of Matrix, Image can access the "read_matrix" function.
    img.read_matrix("image.matrix");

    // "visualize" the image in "image.matrix"
    img.visualize();

   
    //DO NOT FORGET TO FREE THE MEMORY ALLOCATED BY CALLOC.
    img.free_mem();
}