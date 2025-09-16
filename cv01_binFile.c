#include <stdio.h>

int main(){
    double d = 1.6;
    int i = 10;

    FILE* fbin = fopen("soubor.bin", "wb");
    if(fbin == NULL){
        return 1;
    }


    for(int j = 0; j < 20; j++){
        fwrite(&i, sizeof(int), 1, fbin);
        fwrite(&d, sizeof(double), 1, fbin);
    }

    fread(&i, sizeof(int), 1, fbin);

    fclose(fbin);
    return 0;
}