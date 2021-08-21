// C++ program to insert element in Binary Tree
#include <iostream>
#include <queue>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

void display(int *arr, int len) {
    for(int i=0;i<len;i++) {
        printf("%.2d-> ", arr[i]);
    }
    printf("\n");
}

void buildtree(int *arr, int len, int *seg, int sidx) {

    int left = sidx*2-1;
    int right = sidx * 2 ;
    printf("sidx %d, left %d:%d, right %d:%d \n", sidx, left, seg[left], right, seg[right]);
    if(right < len*2) seg[sidx] += seg[right];
    if(left < len *2) seg[sidx] += seg[left];
}

int get (int *arr, int ts, int te, int s, int e, int sid) {
    
    //if(sid > te) return 0;
    if (s <= ts && e >= te) return arr[sid];
    
    if(s > te || e < ts ) return 0;
    
    int mid = (ts + te) / 2;

    printf("%d - %d = %d \n", ts, te, arr[sid]);
    return get(arr, ts, mid, s, e, sid*2+1) + 
        get(arr, mid+1, te, s, e, sid*2+2);

}

int build1 (int arr[], int *seg, int ss, int se, int si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        seg[si] = arr[ss];
        return seg[si];
    }

    // If there are more than one elements, then recur for left and
    // right subtrees and store the sum of values in this node
    int mid = (se + ss) / 2;
    seg[si] = build1(arr, seg, ss, mid, si*2+1) +
            build1(arr, seg, mid+1, se, si*2+2);
    return seg[si]; 
}
void update (int arr[], int *seg, int ui, int si, int diff, int ss, int se) {

    printf("=>>%d - %d = %d \n", ss, se, arr[ss]);
    if(ss == se) {
        seg[si] += arr[ui];
        return; 
    }
    
    seg[si] += diff;
    int mid = (ss + se) / 2;

    if (ui <=mid) {
        update(arr, seg, ui, si*2+1, diff, ss, mid);
    } else {
        update(arr, seg, ui, si*2+2, diff, mid+1, se);
    }

}
int main() {
    //int arr[] = {1,3,5,7,9,11,12};
    //int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int arr[] = {1, 2, 3, 4, 5, 6};// 5, 6, 7, 8, 9};//, 10, 11, 12};
    int len = sizeof(arr)/sizeof(arr[0]);

    int *seg = (int *) calloc (len * 2, sizeof(int));

    //memcpy(seg+len, arr, len*sizeof(int)); 
    //display(seg, len*2);
    build1(arr, seg, 0, len-1, 0);

    display(seg, len*2);
    printf("%d \n", get(seg, 0, len-1, 1, 3, 0));
    
    int diff = 10 - arr[4]; 
    arr[4] = 10; 
    int ui = 4;  
    update(arr, seg, ui, 0, diff, 0, len-1);

    display(seg, len*2);
    //printf("%d \n", get(seg, 0, len-1, 1, 3, 0));
}

/* 
 *                 1
 *
 *        1                9
 *
 *    1       5       9      12
 *
 *  1   3   5   7   9   11      12
 *
 * */
