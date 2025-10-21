#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

double randDouble(){
    unsigned long lng1, lng2, lng3;
    lng1 = (short)rand();
    lng1 = lng1 << 48;
    lng2 = (short)rand();
    lng2 = lng2 << 32;
    lng3 = (short)rand();
    lng3 = lng3 << 16;
    lng1 += lng2 + lng3 + (short)rand();
    double rnd = *((double*)&lng1);
    return rnd;
}

void printByBits(double d){
    unsigned long* ulp = (unsigned long*)&d;
    for(int i = 0; i < 64; i++){
        if((*ulp) & (1ul << i)){
            printf("1");
        } else{
            printf("0");
        }
    }
    printf("\n");
}


int main(){
    srand(12);
    //printf("%lu\n", sizeof(unsigned long));
    double d = randDouble();
    printByBits(d);
    printf("%.512lf\n", d);
    return 0;
}