#include <iostream>
#include <queue>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;


void dfs (int g[][7], int start, int end) 
{
    queue <int> q;
    int visited[100] = {0};

    q.push(start);
    visited[start] = 1;
    printf("%d -> ", start);
    while (!q.empty()) {
        int start = q.front();
        q.pop();

        for (int i=0; i<end; i++) {
            if (g[start][i] == 0) continue;
            if(visited[i] ) continue;

            visited[i] = 1;
            q.push(i);
            printf("%d -> ", i);
        }
    }
    printf("\n");
}

int main() {
    int G[7][7]={{0,0,0,0,0,0,0},
                {0,0,1,1,0,0,0},
                {0,1,0,0,1,0,0},
                {0,1,0,0,1,0,0},
                {0,0,1,1,0,1,1},
                {0,0,0,0,1,0,0},
                {0,0,0,0,1,0,0}};

    dfs (G,4,7);
    return 0;
}
