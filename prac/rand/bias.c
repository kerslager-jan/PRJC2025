#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
    srand(time(NULL));
    const size_t cnt = 1000000000;

    size_t counts[6] = {0, 0, 0, 0, 0, 0};
    for(size_t i = 0; i < cnt; i++){
        int diceroll = 1 + rand() % 6;
        counts[diceroll - 1]++;
    }
    for(int i = 0; i < 6; i++){
        printf("count %d: %lu, percent: %lf%%\n", i+1, counts[i], (double)counts[i]/cnt);
    }
    return 0;
}