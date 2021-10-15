#include <stdio.h>

int test_circle(int x1, int x2, int r){
    if(x1*x1 + x2*x2 < r*r){
        return 0; 
    }
    else if(x1*x1 + x2*x2 == r*r){
        return 1;
    }else{
        return 2;
    }
}

int count(int n, int t){
    if(n<t){
        return 0; // if n<t, no need to count. 
    }else{
        if(n%t ==0){
            return count(n-1, t) + 1;
        }else{
            return count(n-1, t);
        }
    }
}

void main(){
    // testing 
    if(10>5){
        printf("expression true!\n");
    }
    // homework 2
    printf("%d\n", test_circle(1,1,2));
    printf("%d\n", test_circle(3,4,5));
    printf("%d\n", test_circle(100,100,1));

    // homework3
    printf("---------------------------\n");
    printf("%d\n", count(10, 4));
}