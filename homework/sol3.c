#include <stdio.h>
#include <math.h>

double calc_length(double vec[], int len){
    int i = 0; 
    double s = 0; 

    while(i<len){
        s = s + vec[i]*vec[i]; 
        i = i + 1; 
    }
    
    s = sqrt(s); 
    return s; 
}

int compare_vec(int vec1[], int vec2[], int len){
    int i = 0; 
    int diff = 0; 

    for(i = 1; i< len; i++){
        if(vec1[i] != vec2[i]){
            diff = vec1[i] - vec2[i];
            // check slides for the usage of "break;"
            // or simply "return diff;" 
            break; 
        }
    }

    return diff;
}

void main(){
    double vec[] = {1.0, 2.0, 3.0};
    int len = 3; 
    printf("%f\n", calc_length(vec, len));

    int vec1[] = {1.0, 2.0, 3.0};
    int vec2[] = {1.0, 3.0, 3.0};
    printf("------------------\n");
    printf("%d\n", compare_vec(vec1, vec2, 3));
}