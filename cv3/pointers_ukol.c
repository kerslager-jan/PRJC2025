#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>

void getSizes(size_t* i, size_t* c, size_t* d, size_t* f){
    *i = sizeof(int);
    *c = sizeof(char);
    *d = sizeof(double);
    *f = sizeof(float);
}

void print_sizes(size_t int_s, size_t char_s, size_t double_s, size_t float_s){
    printf("int size: %ld\n", int_s);
    printf("char size: %ld\n", char_s);
    printf("double size: %ld\n", double_s);
    printf("float size: %ld\n", float_s);
    return;
}

double swapHalves(double num){
    double d = num;
    double* pd = &d;
    unsigned int* first = (unsigned int*)pd;
    unsigned int* second = first + 1;
    unsigned int tmp = *first;
    *first = *second;
    *second = tmp;

    return *pd;
}

void printByBytes(double num){
    const size_t sz = sizeof(double);
    double* pd = &num;
    char* pc = (char*)pd;
    printf("double %lf by bytes:\n", num);
    for(size_t i = 0; i < sz; i++){
        char byte = *(pc + i);
        printf("%ld: %d\n", i, (int)byte);
    }
    return;
}

bool testSwap(double d){
    return (d == swapHalves(swapHalves(d)));
}

int main(){
    size_t i, c, d, f;
    getSizes(&i, &c, &d, &f);
    print_sizes(i, c, d, f);
    double n = 8.0;

    printByBytes(n);

    printf("double: %lf -> swapped %lf\n", n, swapHalves(n));

    printByBytes(swapHalves(n));

    // tests
    double dob = 3.141592;
    for(int i = 0; i < 20; i++){
        assert(testSwap(pow(dob, i)));
    }
    return 0;
}