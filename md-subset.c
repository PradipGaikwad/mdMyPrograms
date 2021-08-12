#include<stdio.h>

static int c = 1;
void gensubset(int *arr, int idx, int *path, int pidx, int len) {

    if(idx >= len) {
        return;
    }
    
    path[pidx] = arr[idx];

    printf("%3.d :", c);
    for(int i=0; i<=pidx; i++) printf("%d->", path[i]);
    c++;
    printf("\n");
    
    gensubset(arr, idx+1, path, pidx+1, len);
    gensubset(arr, idx+1, path, pidx, len);

}

void itrative(int *arr, int len) 
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

int main()
{
    int arr[]={1,2,3,4,5};
    int path[100];
    int len = sizeof(arr)/sizeof(arr[0]);
    gensubset(arr, 0, path, 0, len);
    printf("=======================\n");
    c = 0;
    itrative(arr, len);
}



