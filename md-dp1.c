// C++ program to insert element in Binary Tree
#include <iostream>
#include <queue>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */

int dp[40] = {0};
int steps(int n) {
 
    if(n<=1) return 0;
    if(n==2) return 1;
    if(n==3) return 1;
    
    if(dp[n]!=0) return dp[n];
    dp[n] = steps(n-2) + steps(n-3);
    return dp[n];
}
void print(int *arr, int len) {
    for(int i=0; i<len; i++) {
        printf("%d + ", arr[i]);
    }
    printf("\n");
}

int coins(int *arr, int start, int len, int sum, int *path, int pidx) {
    
 
    if(start > len) {
        return 0;
    }
    
    if(sum == 0) {
        print(path, pidx);
        return 1;
    }
    if(sum < 0 ) return 0;

    path[pidx] = arr[start];
    dp[start] = coins(arr, start+1, len, sum - arr[start], path, pidx+1);
    dp[start+1] = coins(arr, start+1, len, sum, path, pidx);

}

int min = INT_MAX;
int coins1(int *arr, int start, int len, int sum, int *path, int pidx) {
    
 
    if(start > len) {
        return 0;
    }
    
    if(sum == 0) {
        print(path, pidx);
        return 1;
    }
    if(sum < 0 ) return 0;

    for(int i=0; i<len; i++) {
        path[pidx] = arr[i];
        dp[start] = coins1(arr, i, len, sum - arr[i], path, pidx+1);
    }

}

int main() {
/*
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    */
    int n=10;
    //steps(n);
    print(dp, n);
    printf("\n");
//---------------------------------------------
    int arr[] = {1,2,3,4,5,6,7};
    int path[10] = {0};
    int len = sizeof(arr)/sizeof(arr[0]);
    //coins(arr, 0, len, 6, path, 0);
    coins1(arr, 0, len, 3, path, 0);
    print(dp, n);
    //a[i] = a[i-3] + a[i-2] + a[i-1] //


}
