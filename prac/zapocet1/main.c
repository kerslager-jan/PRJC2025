#include <stdio.h>
#include <stdlib.h>

int* pole(int n){
    return (int*)malloc(n*sizeof(int));
}

void sudalicha(int* arr, int n, int** resEven, int* n1, int** resOdd, int* n2){
    int Evencount = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] % 2 == 0){
            Evencount++;
        }
    }
    int* resE = (int*)malloc(Evencount*sizeof(int));
    int* resO = (int*)malloc((n - Evencount)*sizeof(int));
    int j = 0;
    int k = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] % 2 == 0){
            resE[j] = arr[i];
            j++;
        } else{
            resO[k] = arr[i];
            k++;
        }
    }
    *resEven = resE;
    *resOdd = resO;
}

int** triangle(int h){
    int** t = (int**)malloc(h*sizeof(int*));
    for(int i = 0; i < h; i++){
        t[i] = (int*)malloc((2*i + 1)*sizeof(int));
    }
    return t;
}

void fillTriangle(int** t, int h){
    for(int i = 0; i < h; i++){
        for(int j = 0; j < (2*i + 1); j++){
            t[i][j] = j;
        }
    }
}

int main(){

    return 0;
}