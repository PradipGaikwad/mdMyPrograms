// C++ program to insert element in Binary Tree
#include <iostream>
#include <queue>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

void hepify (int *arr, int idx, int len) {

    int left = 2*idx + 1;
    int right = 2*idx + 2;
    int root = idx;

    if(left < len && arr[idx] < arr[left]) idx = left;
    if(right < len && arr[idx] < arr[right]) idx = right;

    if(idx != root) {
        int tmp = arr[idx];
        arr[idx] = arr[root];
        arr[root] = tmp;
        hepify(arr, idx, len);
    }

}

void display(int *arr, int len) {
    for(int i=0; i<len; i++) {
        printf("%d->", arr[i]);
    }
    printf("\n");
}

int main() 
{

    int arr[] = {1,2,3,4,5,6,7,8,9};
    int len = sizeof(arr) / sizeof(arr[0]);

    display(arr, len);
    
    for(int i=len/2-1; i>=0; i--) {
        hepify(arr, i, len);
        display(arr, len);
    }
}
