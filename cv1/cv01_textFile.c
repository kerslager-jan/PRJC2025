#include <stdio.h>

int main(){
    int i = 10;
    FILE* fileToRead = fopen("soubor.txt", "r"); //mody pro otevreni r/w/a read/write/append, b - binary
    
    if(fileToRead == NULL){
        printf("chyba pri otevreni souboru\n");
        return 1;
    }

    //fprintf(f, "%d", i);
    while(fscanf(fileToRead, "%d", &i) == 1){ //returns num of succesfully read and assigned fields
        printf("precetlo se %d\n", i);
    }; 

    fclose(fileToRead); // !!!


    return 0;
}