#include <stdio.h>
#include <stdlib.h>

typedef struct Tfigure{
    char* name;
    int attack;
    int defense;
} figure;

void createBoard(int n, int m, figure**** board){
    figure*** b = (figure***)malloc(n * sizeof(figure**));
    for(int i = 0; i < n; i++){
        b[i] = (figure**)malloc(m * sizeof(figure*));
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            b[i][j] = NULL;
        }
    }
    *board = b;
}

void moveFigure(figure*** board, int rowFrom, int colFrom, int rowTo, int colTo){
    //from je prazdny
    if(board[rowFrom][colFrom] == NULL){
        return;
    }
    //to je prazdny
    if((board[rowTo][colTo] == NULL)){
        board[rowTo][colTo] = board[rowFrom][colFrom];
        board[rowFrom][colFrom] = NULL;
        return;
    }
    // souboj
    figure* defender = board[rowTo][colTo];
    figure* attacker = board[rowFrom][colFrom];
    if(defender->defense - attacker->attack <= 0){
        //defender prohral
        free(board[rowTo][colTo]);
        board[rowTo][colTo] = attacker;
        board[rowFrom][colFrom] = NULL;
    } else{
        //defender vyhral (nebo byla remiza)
        free(board[rowFrom][colFrom]);
        board[rowFrom][colFrom] = NULL;
    }
    return;
}

figure* createFigure(char* name, int attack, int defense){
    figure* f = (figure*)malloc(sizeof(figure));
    f->attack = attack;
    f->defense = defense;
    f->name = name;
    return f;
}

void addFigure(figure*** board, int row, int col, figure* fig){
    board[row][col] = fig;
}

void freeBoard(figure*** board, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] != NULL){
                free(board[i][j]);
            }
        }
        free(board[i]);
    }
    free(board);
}

void printBoard(figure*** board, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] != NULL){
                printf("%d/%d", board[i][j]->attack, board[i][j]->defense);
            } else{
                printf("___");
            }
            if(j != 7){
                printf("|");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    figure*** b;
    createBoard(8, 8, &b);
    char name1[] = "prvni";
    char name2[] = "druha";
    figure* f1 = createFigure(name1, 1, 1);
    figure* f2 = createFigure(name2, 1, 2);
    addFigure(b, 0, 0, f1);
    addFigure(b, 7, 7, f2);
    
    printBoard(b, 8, 8);

    moveFigure(b, 7, 7, 0, 0);

    printBoard(b, 8, 8);

    freeBoard(b, 8, 8);
    return 0;
}