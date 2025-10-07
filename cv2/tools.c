#define DEBUG
#include "tools.h"
#include <stdio.h>

void print(double d){
    printf("d = %f\n", d);
}

double circleArea(double r){
    DEBUG_MSG(r)
    return PI * r*r;
}

int divide(int a, int b){
    DEBUG_MSG(a)
    DEBUG_MSG(b)
    return a / b;
}