#include<stdio.h>
#include<stdlib.h>

/*
generate a copy of an array, appending it with an additional element a
array: input, the original array
len: intput, the length of the original array
a: input, the element to be appended. 
return: a int pointer, pointing to the copy array. 
*/
int *slice(int *array, int start, int end){
    int *newarray = malloc((end-start)*sizeof(int));
    for (int i = start; i < end; i++)
    {
        newarray[i-start] = array[i];
    }
    return newarray;
}

/*
generate a sliced copy of an array, including only elements from array[start] to array[end-1].
array: input, the original array
start, end: inputs, the start and end index of the slice. 
return: a int pointer, pointing to the sliced copy. 
*/
int *append(int *array, int len, int a){
    int *newarray = malloc((len+1)*sizeof(int));
    for (int i = 0; i < len; i++){
        newarray[i] = array[i];
    }
    newarray[len] = a;
    return newarray;
}

void main(){
    printf("----------- homework 2 output------------\n");
    //create a test case
    int array[] = {1,2,3,4,5,6,7};
    int len = 7;
    //call your append function
    int *newarray = append(array,len,8);

    //print out the appended array.
    for (int i = 0; i < len+1; i++){
        printf("%d ", newarray[i]);
    }
    printf("\n");

    //DO NOT FORGET TO FREE THE MEMORY!
    free(newarray);

    printf("\n----------- homework 3 output ------------\n");
    int start = 1, end = 3; 
    //call your slice function
    newarray = slice(array, start, end);

    //print out the sliced array.
    for (int i = 0; i < end-start; i++){
        printf("%d ", newarray[i]);
    }
    printf("\n");
    //DO NOT FORGET TO FREE THE MEMORY!
    free(newarray);
}