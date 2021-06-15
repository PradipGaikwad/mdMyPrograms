#include <stdio.h>
#include <stdlib.h>
       #include <unistd.h>


int board[9][9]={0};

void print1(int board[][9]) 
{
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
        printf("\n");
        printf("\n");
        printf("\n");
}

int isokay(int val, int r1, int c1) {

    for(int i=0; i<9; i++) {
        if(board[i][c1]==val) return 0;
        if(board[r1][i]==val) return 0;
    }
    int r2 = r1 - r1%3;
    int c2 = c1 - c1%3;
    for(int i=r2; i<r2+3; i++) {
        for(int j=c2;j<c2+3; j++) {
            if(board[i][j] == val) return 0;
        }
    }
    return 1;

}

int fill (int row, int col)
{
    //printf("r %d, c %d \n", row, col); 
        //print1(board);

    if(row == 8 && col == 9) {
        print1(board);
        return 1;
    }
    if(col >=9 ) {
        row++;
        col=0;
    }

    if (board[row][col]!=0) return fill (row,col+1);

    for (int j=1; j<=9; j++) {
        if(isokay(j, row, col)) {
            board[row][col] = j;
            if(fill(row, col+1)) return 1;
            else
                board[row][col] = 0;
        }
    }
    return 0;
}


int main() {

    for(int i=0; i<9; i++) {
        board[i][i] = i+1;
    }
    board[0][1]=4;
    print1(board);
    fill(0,0);
}




