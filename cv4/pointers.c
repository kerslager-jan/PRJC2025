#include <stdlib.h>
#include <stdio.h>

double* pole(size_t n){
    double* p = (double*)malloc(n * sizeof(double));
    return p;
}

void fillRand(double* arr, size_t len, double max){
    if(!arr){
        return;
    }
    for(size_t i = 0; i < len; i++){
        arr[i] = (rand()/(double)RAND_MAX) * max;
    }
}

void fce3(double* doubleArr, size_t doubleArr_size, size_t n, int** intArr, int* size){
    if(n >= doubleArr_size){
        printf("pole double neobsahuje %luty prvek\n", n);
        return;
    }
    //printf("na pozici %lu v poli double je hodnota %lf\n", n, doubleArr[n]);
    int velikost = (int)doubleArr[n];
    //printf("velikost pole int bude %d\n", velikost);
    *intArr = (int*)malloc(velikost * sizeof(int));
    for(int i = 0; i < velikost; i++){
        (*intArr)[i] = i;
    }
    *size = velikost;
}

void check(double* doubleArr, size_t doubleArr_size, size_t n, int* intArr, int intArr_size){
    printf("%lu-ta hodnota pole double: %lf\n", n, doubleArr[n]);
    printf("vytvoreno pole int o velikosti %d\n", intArr_size);
    for(int i = 0; i < intArr_size; i++){
        printf("intarr[%d] = %d\n", i, intArr[i]);
    }
}

int main(){
    srand(123);
    size_t l = 10;
    size_t n = 5;
    int arrLen;
    int* arr;
    double* doubleArr = pole(l);
    fillRand(doubleArr, l, 100.0);
    fce3(doubleArr, l, n, &arr, &arrLen);
    check(doubleArr, l, n, arr, arrLen);
    return 0;
}