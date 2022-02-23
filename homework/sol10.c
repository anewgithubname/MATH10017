#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>

struct matrix
{
    int numrow;
    int numcol;
    int *elements;
};
typedef struct matrix Matrix;

/*
Takes 2D index i, j of a matrix M, return the linearized index
e.g. I have a 2D index 1,2 of a 3 by 4 matrix M, the linearized index should be 1*3+2 = 5
*/
int idx(int i, int j, Matrix M)
{
    return i * M.numcol + j;
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
    Matrix M = {numrow, numcol, calloc(numrow * numcol, sizeof(int))};

    for (int i = 0; i < M.numrow; i++)
    {
        for (int j = 0; j < M.numcol; j++)
        {
            M.elements[idx(i, j, M)] = getc(f);
        }
    }

    fclose(f);
    return M;
}

/**
 * Visualize the image stored in array a.
 */
void visualize(int numrow, int numcol, int a[])
{
    // this code is adapted from the tutorial code: 
    // https://github.com/anewgithubname/MATH10017/blob/main/lecs/tutorial.pdf
    for (int i = 0; i < numrow; i++)
    {
        for (int j = 0; j < numcol; j++)
        {
            if( a[i*numcol+j] < 85){
                printf(" ");
            }else if(a[i*numcol+j] >= 85 && a[i*numcol+j] <= 170){
                printf("I");
            }else{
                printf("M");
            }
        }
        printf("\n");
    }
}
/*
 * pairwise_dist
 *
 * Store the distance between row i of Matrix A and
 * row j of Matrix B in i-j entry of Matrix C.
 */
void pairwise_dist(Matrix A, Matrix B, Matrix C)
{
    // Loop over each row of A and B, and compute the distance between rows. 
    // This code is similar to the matrix multiplication code we studied here: 
    // https://github.com/anewgithubname/MATH10017/blob/main/homework/sol4.c
    for (int i = 0; i < A.numrow; i++)
    {
        for (int j = 0; j < B.numrow; j++)
        {
            C.elements[idx(i, j, C)] = 0;
            for (int k = 0; k < A.numcol; k++)
            {
                C.elements[idx(i, j, C)] +=
                    (A.elements[idx(i, k, A)] - B.elements[idx(j, k, B)]) 
                    * (A.elements[idx(i, k, A)] - B.elements[idx(j, k, B)]);
            }
        }
    }
}

/*
 * find_minimum
 *
 * Return index of (first) minimum element of an integer array.
 */
int find_minimum(int len, int array[len]){
    // this code is adapted from
    // https://github.com/anewgithubname/MATH10017/blob/main/homework/sol5.c
    int min = INT_MAX; 
    int idx = -1; 
    for (int i = 0; i < len; i++)
    {
        if(array[i] < min){
            min = array[i];
            idx = i; 
        }
    }
    
    return idx; 
}

/*
 * minimum5
 *
 * Store the indices of the 5 smallest elements of array in top.
 */
void minimum5(int len, int array[len], int top[5]){
    // find minimum for 5 times, and each time, 
    // replace the minimum with INT_MAX. 
    // This code is adapted from https://github.com/anewgithubname/MATH10017/blob/main/homework/sol5.c
    int top_index = find_minimum(len, array);
    top[0] = top_index;
    array[top_index] = INT_MAX;

    top_index = find_minimum(len, array);
    top[1] = top_index;
    array[top_index] = INT_MAX;
    
    top_index = find_minimum(len, array);
    top[2] = top_index;
    array[top_index] = INT_MAX;

    top_index = find_minimum(len, array);
    top[3] = top_index;
    array[top_index] = INT_MAX;

    top_index = find_minimum(len, array);
    top[4] = top_index;
    array[top_index] = INT_MAX;
}

void main()
{
    Matrix X = read_matrix("./X.matrix");
    printf("N: %d, M: %d\n", X.numrow, (int) sqrt(X.numcol));

    Matrix T = read_matrix("./T.matrix");
    printf("L: %d\n", T.numrow);

    Matrix Y = read_matrix("./Y.matrix");
    int s = 0;
    for (int i = 0; i < Y.numrow; i++)
    {
        if(Y.elements[idx(i,0,Y)] == 1)
            s++;
    }
    printf("There are %d images that are digit 1.\n" , s);
    
    printf("press enter to continue, ctrl+c to quit.\n"); 
    printf("(You do not need to pause in YOUR submission. \n");
    printf("Here it is only added for the demonstration purpose.)\n"); getchar(); 

    Matrix D = {X.numrow, T.numrow, calloc(X.numrow * T.numrow, sizeof(int))};
    pairwise_dist(X, T, D);
        
    /*
     * For each column in the distance matrix D,
     *
     * 1) copy the column to "col"
     *
     * 2) visualize the image
     *
     * 3) store the indices of the 5 nearest neighbors of the column in "top"
     *
     * 4) count the number of neighbors labelled 1, and predict 1 if the number is >= 3.
     *
     */
    for(int j = 0; j<T.numrow; j++){
        printf("for test image %d: \n", j);
        int nn[5] = {0};
        int col[D.numrow];
        // copy j-th column of D to col
        for(int i = 0; i<D.numrow; i++){
            col[i] = D.elements[idx(i, j, D)];
        }

        // copy image from row j to T to flat array and visualize
        int t[T.numcol];
        for(int i = 0; i<T.numcol; i++){
            t[i] = T.elements[idx(j, i, T)];
        }
        visualize(28, 28, t);

        // find indices (in X) of 5 nearest neighbors (nn)
        minimum5(D.numrow, col, nn);
        printf("Labels of 5 images that are nearest to the test image %d: \n", j);
        for(int i = 0; i<5; i++){
            printf("%d ", Y.elements[idx(nn[i], 0, Y)]);
        }
        printf("\n");

        // make prediction
        int s = 0;
        for(int i = 0; i<5; i++){
            if(Y.elements[idx(nn[i], 0, Y)] == 1){
                s++;
            }
        }
        if(s >= 3){
            printf("Prediction is 1\n");
        }
        else{
            printf("Prediction is NOT 1\n");
        }
        printf("press enter to continue, ctrl+c to quit.\n");
        getchar();
    }

    free(X.elements);
    free(T.elements);
    free(Y.elements);
}
