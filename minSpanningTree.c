#include <iostream>
#include <queue>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define V   5

int getminidx(int *dis, int *visited) {

    int min = INT_MAX, idx;
    for(int i=0; i < V; i++) {
        if(dis[i] < min && !visited[i]){
            min = dis[i];
            idx = i;
        }
    }
    return idx;
}

void primMST(int g[][V]) {

    int parent[V] = {0};
    int visited[V] = {0};
    int min_dis[V] = {INT_MAX};
    for(int i=0; i<V; i++) {
        min_dis[i] = INT_MAX;
        parent[i] = INT_MAX;
    }

    parent[0] = -1;
    min_dis[0] = 0;


    for (int i=0; i< V-1; i++) {

        int idx = getminidx(min_dis, visited);
        printf("%d -> ", idx);
        visited[idx] = 1;
        

        for(int j=0; j<V; j++) {
            if(!visited[j] && min_dis[j] > g[idx][j] && g[idx][j]) {
                parent[j] = idx;
                min_dis[j] = g[idx][j];
            }
        }
    }
    printf("\n");
    for(int j=0; j<V; j++) printf("%d => ", parent[j]);

}


// Driver code
int main()
{
    /* Let us create the following graph
       2 3
       (0)--(1)--(2)
       | / \ |
       6| 8/ \5 |7
       | / \ |
       (3)-------(4)
       9     */
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
        { 2, 0, 3, 8, 5 },
        { 0, 3, 0, 0, 7 },
        { 6, 8, 0, 0, 9 },
        { 0, 5, 7, 9, 0 } };

    // Print the solution
    primMST(graph);

    return 0;
}

