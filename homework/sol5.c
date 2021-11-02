#include <stdio.h>

int find_minimum(int len, double array[len]){
    double min = 999; 
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

void find_top3(int len, double array[len], double top[3]){
    int top_index = find_minimum(len, array);
    top[0] = array[top_index];
    array[top_index] = 999;

    top_index = find_minimum(len, array);
    top[1] = array[top_index];
    array[top_index] = 999;
    
    top_index = find_minimum(len, array);
    top[2] = array[top_index];
}

// write your function here 
void swap(int *a, int *b){
    int t = 0; 
    if(a>b){
        t = *b; 
        *b = *a; 
        *a = t; 
    }
}

void main(){
    // homework 1
    printf("homework 1--------------\n");
    double vec[] = {0.2, 0.5, .3,.001,.1};
    printf("The index of the smallest is: %d\n",  find_minimum(5, vec));

    // homework 2
    printf("\nhomework 2--------------\n");
    double top3[] = {999,999,999};
    find_top3(5, vec, top3);
    printf("Three smallest values are %.5f %.5f %.5f\n", top3[0],top3[1],top3[2]);

    // homework 3
    printf("\nhomework 3--------------\n");
    int a = -9999; int *pa = &a;
    *pa = 1; 
    printf("%d \n", a);

    int a1 = 3, a2 = 2; 

    //call your function here
    //you cannot swap values of a1 and a2 here. 
    //you must call a function to swap values for you.
    swap(&a1, &a2);

    printf("%d %d\n", a1, a2); 
    // displays "2 3"
}
