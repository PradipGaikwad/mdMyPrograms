// C++ program to insert element in Binary Tree
#include <iostream>
#include <queue>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int x[4] = {0, 1, 0, -1};
int y[4] = {1, 0, -1, 0};
int moves = 4;

int is_safe(vector<vector<char> >& grid, int xval, int yval) {

    if (yval >= grid[0].size() || xval >= grid.size()) return 0;

    if (xval < 0 || yval < 0) return 0;

    if (grid[xval][yval] == '0' || grid[xval][yval] == '2') return 0;

    return 1;
}

void dfs (vector<vector<char> >& grid, int row, int col) {

    grid[row][col] = '2';

    for(int i=0; i< moves; i++) {

        int xval = row + x[i];
        int yval = col + y[i];

        if(is_safe(grid, xval, yval)) {
            printf("%d,%d\n", xval, yval);
            dfs(grid, xval, yval);
        }
    }
}

int numIslands(vector<vector<char> >& grid) {

    int island = 0;
    for(int row = 0; row < grid.size(); row++ ) {
        for (int col = 0; col < grid[0].size(); col++) {

            if(grid[row][col]== '2' || grid[row][col] == '0') continue;

            dfs(grid, row, col);
            island += 1;

        }
    }

    return island;
}
int main() {

    vector<vector<char> > grid = { 
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    printf("%d ", numIslands(grid));
} 
