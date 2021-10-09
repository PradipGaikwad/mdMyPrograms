// C++ program to insert element in Binary Tree
#include <iostream>
#include <queue>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;


int getMinDiceThrows (int *moves, int n) {

    int visited[30] = {0};
    int roll = 0;
    queue <int> q;

    q.push(0);

    while(!q.empty()) {
    
        int base = q.front();
        q.pop();
        printf("%d -> ", base);

        for(int i=1; i<=6; i++) {
            int next = base + i;
            
            if(moves[next] != -1) next = moves[next];

            if (next >= n ) continue; 
            if (next == n - 1) {
                printf("reached %d \n", visited[base]+1);
                return visited[base] + 1;
            }
            
            if(visited [next]!=0) continue;
            visited [next] = visited [base] + 1;
            
            printf(":%d", next);
            q.push(next);
        }
        printf("= %d\n", visited[base]);
    }
    return -1;
}

int main()
{
    // Let us construct the board given in above diagram
    int N = 50;
    int moves[N];
    for (int i = 0; i<N; i++)
        moves[i] = -1;
    
    // Ladders
    //moves[2] = 21;
    //moves[4] = 7;
    moves[10] = 25;
    //moves[19] = 28;

    // Snakes
    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;
    
    cout << "\nMin Dice rolls required is " << getMinDiceThrows(moves, N);
    printf("\n");
    return 0;
}
