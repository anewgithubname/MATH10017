#include <stdio.h>

int find_maximum(int len, int array[len]){
    int min = -999; 
    int idx = -1; 
    for (int i = 0; i < len; i++)
    {
        if(array[i] > min){
            min = array[i];
            idx = i; 
        }
    }
    
    return idx; 
}

void swap(int a[], int i, int j){
    int temp = a[i]; 
    a[i] = a[j]; 
    a[j] = temp; 
}
// the for loop version sort. 
void sort(int len, int array[]){
    for (int i = 1; i <= len-1; i++)
    {
        printf("iteration %d:\n", i);
        int max_idx = find_maximum(len-i + 1, array); 
        printf("the index of the %d-th maximum %d\n", i, max_idx);
        printf("swap %d and %d-th element\n", max_idx, len - i);
        swap(array, max_idx, len - i);
        printf("after swapping \n");
        for(int j = 0; j < len; j++){
            printf("%d ", array[j]);
        }
        printf("\n\n");
    }
}

// the recursive version sort.
void sort_rec(int len, int array[]){
    int max_idx = find_maximum(len, array); 
    swap(array, max_idx, len - 1);
    for(int j = 0; j < 6; j++){
        printf("%d ", array[j]);
    }
    printf("\n");
    if(len>1){
        sort_rec(len-1, array);
    }
}

void main(){
    int len = 6; 
    int array[] = {5, 3, 2, 1, 2,  4}; 
    
    printf("before sorting\n");
    for(int i = 0; i < len; i++){
        printf("%d ", array[i]);
    }
    printf("\n\n");

    sort(len, array); 
    // sort_rec(len, array);
}