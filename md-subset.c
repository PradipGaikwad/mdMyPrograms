#include<stdio.h>
#include <stdlib.h>     /* abs */
static int c = 1;
void gensubset(int *arr, int idx, int *path, int pidx, int len) {
    if(idx == len) return;

    for(int ii=idx; ii<len; ii++) {
        path[pidx] = arr[ii];

        printf("%5.d :", c++);
        for(int i=0; i<=pidx; i++) printf("%d->", path[i]); printf("\n");

        gensubset(arr, ii+1, path, pidx+1, len);
    }

}

void gensubset1(int *arr, int idx, int *path, int pidx, int len) {

    if(idx >= len) {
        return;
    }
    
    path[pidx] = arr[idx];

    printf("%3.d :", c);
    for(int i=0; i<=pidx; i++) printf("%d->", path[i]);
    c++;
    printf("\n");
    
    gensubset1(arr, idx+1, path, pidx+1, len);
    gensubset1(arr, idx+1, path, pidx, len);

}
void subarray(int *arr, int len) 
{
    for (int i=0; i<len; i++) {
        for(int j=i; j<len; j++) {
            printf("%.3d :",++c);
            for(int k=i; k<=j; k++) {
                printf("%d->", arr[k]);
            }
            printf("\n");
        }
    }
}

int diff = 100000;
void subset_sum(int *arr, int ai, int *path, int pi, int sum, int len, int target) 
{
    if (ai >= len) {
        int abs1 = abs(target-sum);
        if(diff > abs1) {
            for(int i=0; i<pi; i++) printf("%d->", path[i]);
            diff = abs1;
            printf(" =  %d \n", diff);
        }
        return;
    }
    path[pi] = arr[ai];
    subset_sum(arr, ai+1, path, pi+1, sum + arr[ai], len, target);
    subset_sum(arr, ai+1, path, pi, sum, len, target);
    return ;
}
void subset_sum1(int *arr, int ai, int *path, int pi, int sum, int len, int target) 
{
    if (ai >= len) {
        int abs1 = abs(target-sum);
        if(diff > abs1) {
            for(int i=0; i<pi; i++) printf("%d->", path[i]);
            diff = abs1;
            printf(" =  %d \n", diff);
        }
        return;
    }
    path[pi] = arr[ai];
    subset_sum(arr, ai, path, pi+1, sum + arr[ai], len, target);
    subset_sum(arr, ai+1, path, pi, sum, len, target);
    return ;
}
int main()
{
    int arr[]={1, 5, 7};
    int path[100];
    int len = sizeof(arr)/sizeof(arr[0]);
    gensubset(arr, 0, path, 0, len);
    printf("=======================\n");
    c = 0;
    subarray(arr, len);
    printf("=======================\n");
    
    int sum1=0;
    for(int i=0; i<len; i++) sum1 +=arr[i];
    sum1 = sum1/2;
    subset_sum(arr, 0, path, 0, 0, len, sum1);
    printf(" =>> %d \n", diff);
}



