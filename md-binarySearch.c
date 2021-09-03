// C++ program to insert element in Binary Tree
#include <iostream>
#include <queue>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int findstartend(int *a, int len, int num, int is_start) {

    int start = 0, end = len - 1;
    while (start <= end) {

        int mid = (start + end ) / 2;

        if (a[mid] > num) {
            end = mid - 1;
        } else if(a[mid] < num) {
            start = mid + 1;
        } else {
            printf("num at %d\n", mid);
            if (is_start == 0 && mid < len - 1 && a[mid+1] == num) {
                start = mid + 1;
            } else if (is_start == 1 && mid > 0 && a[mid-1] == num) {
                end = mid -1;
            } else {
                printf("num at =>%d\n", mid);
                return mid;
            }
        }
    }
    return -1;
}

int main()
{

    int a[] = {1,2,2,2,3,4,4,4,4,5,6,7};
    int len = sizeof(a) / sizeof(a[0]);
    int num = 2;
    int start = findstartend (a, len, num, 1);
    int end = findstartend (a, len, num, 0);
    printf("start %d, end %d \n", start, end);

}



