#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <limits.h>
#include <string.h>
int funmain(int *arr, int len, int k)
{
    int winend=0, winstart = 0;
    int maxsum = 0, winsum = 0;

    for(winend=0; winend<len; winend++) {
             winsum += arr[winend];

        if (winend >= k-1) {
            if(maxsum < winsum) maxsum = winsum;
            winsum -= arr[winstart];

            winstart++;
        }
    }
    printf("max sum = %d\n", maxsum);
}

int smallestSubArray(int *arr, int s, int len) 
{

    int winst=0, winend=0;
    int sum=0;
    int smallest = INT_MAX;


    for (winend=0; winend <len; winend++) {

        sum += arr[winend];

        if (sum > s) {
            if(smallest > winend-winst+1) smallest = winend-winst+1;
            while(sum >=s) {
                sum -= arr[winst];
                winst++;
            }
        }
    }
    printf("smallest subarray len = %d\n", smallest);
}

int kdistinct()
{
    char str[] = "cbbebiaabbbcccdddddd";
    int wins=0, wine=0;
    int maxl=INT_MIN, len;
    int hash[26]={0};
    int k=3;;
    int newc=0;

    for (wine=0; wine<strlen(str); wine++) {

        int index = str[wine] - 'a';
        
        if (hash[index] == 0) newc++;
        hash[index]++;
        
        if(newc==k) 
            if(maxl < wine-wins+1) maxl = wine-wins +1;
        
        while(newc > k) {
            int start_idx = str[wins] - 'a';
            if(hash[start_idx] == 1) newc--;
            hash[start_idx] -= 1;
            wins++;
        }
    }
    printf("max len with k distinct %d \n", maxl);
}

int longestSubstring()
{
    char str[] = "abcaefg";
    int wins=0, wine=0;
    int maxl=INT_MIN, len;
    int hash[26]={0};
    int k=3;;
    int newc=0;

    // abcazyz

    for (wine=0; wine<strlen(str); wine++) {

        int index = str[wine] - 'a';
        
        hash[index]++;
        
        if(hash[index]==1) 
            if(maxl < wine-wins+1) maxl = wine-wins +1;
        
        while(hash[index] !=1) {
            int start_idx = str[wins] - 'a';
            hash[start_idx] -= 1;
            wins++;
        }
    }
    printf("longest substring non repeating %d \n", maxl);
}

int main()
{
    //int arr[]= { 2, 3, 4, 1, 5};
    int arr[]= {2, 1, 5, 1, 3, 2};
    int k=3;
    int len =  sizeof(arr)/sizeof(arr[0]);

    funmain(arr, len , k);
    smallestSubArray(arr, len , 7);
    kdistinct();
    longestSubstring();
}

