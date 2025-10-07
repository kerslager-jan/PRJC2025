#include <stdio.h>

int main(){

    FILE* f = fopen("goog.csv", "r");
    if(f == NULL){
        printf("File didnt open succesfuly\n");
        return 1;
    }
    char date[12];
    char ignore[1024];
    double open, high, low, close, volume, adj_close;
    int i = 0;
    //skip headers
    fgets(ignore, sizeof(ignore), f);
    printf("skipped line: %s", ignore);
    FILE* bf = fopen("goog.bin", "wb");
    FILE* tf = fopen("goog-lows.txt", "w");

    // -------------------------------------------READING TEXT FILE BY FORMAT-------------------------------------------
    // -------------------------------------------WRITING BIN FILE-------------------------------------------
    // -------------------------------------------WRITING TEXT FILE-------------------------------------------
    while((fscanf(f, "%10s,%lf,%lf,%lf,%lf,%lf,%lf\n", date, &open, &high, &low, &close, &volume, &adj_close)) == 7){
        i++;
        //printf("%3d: low: %5.2f, high: %6.2f\n", i, low, high);
        fwrite(&low, sizeof(double), 1, bf);
        fprintf(tf, "high: %lf, low: %lf\n", high, low);
    }
    fclose(bf); // !!!!!!!!!!!!!!!!!!!!!!!!! IMPORTANT !!!!!!!!!!!!!!!!!!!!!!!!!!!
    fclose(tf);
    fclose(f);

    // -------------------------------------------READING BIN FILE-------------------------------------------
    FILE* bfr = fopen("goog.bin", "rb");
    if(bfr == NULL){
        printf("xd\n");
    }
    double d;
    size_t count = 1;
    size_t return_code;
    while((return_code = fread(&d, sizeof(double), count, bfr)) == count){
        printf("%lf\n", d);
    }
    fclose(bfr);

    // -------------------------------------------READING TEXT FILE BY LINES-------------------------------------------
    FILE* tfr = fopen("goog-lows.txt", "r");
    const size_t lineLength = 1024;
    char line[lineLength];
    while(fgets(line, lineLength, tfr) != NULL){
        printf("%s", line);
    }
    fclose(tfr);
    return 0;
}