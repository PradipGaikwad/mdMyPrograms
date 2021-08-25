// C++ program to insert element in Binary Tree
#include <iostream>
#include <queue>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int board[8][8] = {0};

struct player {
    char *name;
};

enum type  {
    king=0,
    queen,
    bishop,
    rook,
    pawn
};

struct pieces {
    int color;
    int type;
};

int king_move(int board, int start, int end) {

}

int queen_move(int board, int start, int end) {

}

int bishop_move(int board, int start, int end) {

}

int rook_move(int board, int start, int end) {

}

int pawn_move(int board, int start, int end) {

}

int move (int player_id, int board, int start, int end) {

    if (last_player_id == player_id) return -1;
    int what_moving = get_type(board, start, end);
    
   

    
    switch(what_moving) {

        case king: ret = king_move(board, start, end); break;
        case queen: ret = queen_move(board, start, end); break;
        case bishop: ret = bishop_move(board, start, end); break;
        case rook: ret = rook_move(board, start, end); break;
        case pawn: ret = pawn_move(board, start, end); break;
    }
    if(ret) return -1;
    board[start][end] = what_moving;
    last_player_id = player_id;
}

int setup_board() {
    //hardcoded;
}
