#include <stdio.h>

void print(int a, double b, char c){
    printf("a = %d, b = %f, c = %c\n", a, b, c);
}

int main(){
    int a = 100;
    double b = 3.14;
    char c = 'x';

    print(a, b, c);
    //c = getchar();
    scanf("%d", &a);
    print(a, b, c);    

    return 0;
}