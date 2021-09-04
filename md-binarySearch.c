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
            if (is_start == 0 && mid < len - 1 && a[mid+1] == num) {
                start = mid + 1;
            } else if (is_start == 1 && mid > 0 && a[mid-1] == num) {
                end = mid -1;
            } else {
                return mid;
            }
        }
    }
    return -1;
}
int findpeak(int *a, int len) 
{
    int start = 0, end = len - 1;
    int mid;
    while (start <= end) {
        mid = start + (end - start) / 2;

        if (mid > 0 && a[mid] > a[mid-1] 
                && mid < len-1 && a[mid] > a[mid+1])
            return a[mid];

        if (mid > 0 && a[mid] >= a[mid - 1]) start = mid + 1 ;
        if (mid < len - 1 && a[mid] >= a[mid + 1]) end = mid - 1;
    }

    return a[mid];
}

void search (int *a, int len, int num) {

    int start = 0, end = len - 1;
    
    while(start <= end) {
        int mid = (start + end) / 2;

        if (a[mid] > num) end = mid - 1;
        else if (a[mid] < num) start = mid + 1;
        else {
            printf("start %d, mid %d, end %d \n", a[start], a[mid], a[end]);
            break;
        }
    }
    printf("\t%d: next %d, previous %d \n", num, a[start], a[end]);
}

int main()
{

    int a[] = {100,1,2,2,2,3,9,10,11,7};
    int len = sizeof(a) / sizeof(a[0]);
    int num = 2;
    int s1 = 2;
    search(a, len, s1);
    int start = findstartend (a, len, num, 1);
    int end = findstartend (a, len, num, 0);
    printf("\tDuplicate start %d, end %d \n", start, end);
    int peak = findpeak(a, len);
    printf("\tPeak Element = %d \n", peak);
}



