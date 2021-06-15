#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <limits.h>
#include <string.h>


/*
 * Given an array, find the length of the smallest subarray in it which when
 * sorted will sort the whole array.
 */
void sortWindow()
{
    printf("========= %s ==========\n", __FUNCTION__);
    //int arr[]={ 1, 2, 5, 3, 7, 10, 9, 12};
    int arr[]={1, 3, 2, 0, -1, 7, 10};
    int len = sizeof(arr)/sizeof(arr[0]);
    int min = len-1, max = 0;

    //find from left
    for (int i=0; i<len; i++) {
        if(arr[i] >= arr[max]) max = i;
        else break;
    }

    //find from right
    for (int i=len-1; i>0; i--) {
        if(arr[i] <= arr[min]) min = i;
        else break;
    }
    
    // all numbers between min and max are not sorted
    int len1 = min-max+1; 
    printf("max %d, min %d, sortlist %d  \n", max, min, len1);
    
}

int _twoSum(int *arr, int start, int end, int sum) {
    
    int cur_sum = 0;
    while(start < end ) {
        cur_sum = arr[start] + arr[end];
        if (cur_sum < sum ) start++;
        else if (cur_sum > sum) end--;
        else break;
    }

    printf("start = %d, end = %d \n", start, end);
    return (start>=end)?0:1;
}

void twoSum() 
{

    printf("========= %s ==========\n", __FUNCTION__);
    int arr[] = {2,7,11,15};
    int len = sizeof(arr)/sizeof(arr[0]);
    int find = 18;

    if(_twoSum(arr, 0, len-1, find)) printf("found \n");
    else printf("Not Found \n");
}

void stringCompareBackspace()
{
    char str1[]="x#yz", str2[]="xy#y#yzz#";
    printf("========= %s ==========\n", __FUNCTION__);
    int l1 = strlen (str1)-1;
    int l2 = strlen (str2)-1;
    int bk1, bk2;

    while(l1 >= 0 && l2 >= 0) {
        
        bk1=0; bk2=0;

        while(l1 > 0 ) {
            if (str1[l1] == '#') bk1 +=1;
            else if (bk1 > 0) bk1 -=1;
            else break;
            l1--;
        }

        while(l2 > 0 ) {
            if (str2[l2] == '#') bk2 +=1;
            else if (bk2 > 0) bk2 -=1;
            else break;
            l2--;
        }
        //l2 = l2 - bk2; l1= l1-bk1;
        //printf(" l1 %d, l2 %d \n", l1, l2);

        if (l1 >=0 && l2>=0 && str1[l1] != str2[l2]) 
            printf("Not Equal %c = %c \n", str1[l1], str2[l2]);
        else 
            printf("Equal %c = %c \n", str1[l1], str2[l2]);
        l1--; l2--;

    }
    if (l1==l2) printf("Equal \n");
    else 
        printf("not equall \n");
}

int main()
{
    sortWindow();
    stringCompareBackspace();
    twoSum();
}
