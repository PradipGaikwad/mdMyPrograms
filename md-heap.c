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
void bubble(int *a, int len)
{
    int swapped = 1;
    int count = 0;

    while(swapped == 1) {
        for (int j=0; j<len-count-1; j++) {
            swapped = 0;
            if(a[j] < a[j+1]) {
                int tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
                swapped = 1;
                count++;
            }
        }
    }
}
void heap_main(int *arr, int len) {

    for(int i=len/2-1; i>=0; i--) {
        hepify(arr, i, len);
        display(arr, len);
    }

}
int main() 
{

    int arr[] = {1,2,3,4,9,6,7,8,5};
    int len = sizeof(arr) / sizeof(arr[0]);

    display(arr, len);
    heap_main(arr, len); 
    display(arr, len);
    bubble(arr, len);
    display(arr, len);
}
