// C++ program to insert element in Binary Tree
#include <iostream>
#include <queue>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define N   4
int main() 
{
    int n =N;
    int res[N][N]={0}; // To store result
    int mat1[N][N] = { 
        { 1, 1, 1, 1 },
        { 2, 2, 2, 2 },
        { 3, 3, 3, 3 },
        { 4, 4, 4, 4 } };

    int mat2[N][N] = { 
        { 1, 1, 1, 1 },
        { 2, 2, 2, 2 },
        { 3, 3, 3, 3 },
        { 4, 4, 4, 4 } };
    
    int i, j ,k;

    for(j=0; j<n; j++) {
        for(i=0; i<n; i++) {
            for(k=0; k<n; k++) {
                res[i][k] += mat1[i][k] * mat2[j][k];
            }
        }
    }
/*

*/
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%3.d\t", res[i][j]);
            res[i][j] = 0;
       }
       printf("\n");
    }
    printf("\n\n");

    for(i=0; i<n; i++) {
        for(k=0; k<n; k++) {
            for(j=0; j<n; j++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%3.d\t", res[i][j]);
       }
       printf("\n");
    }
    
    return 0;

}
