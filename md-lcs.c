#include<stdio.h>
#include<string.h>

int max(int a, int b) {
    return (a>b)?a:b;
}

int lcs(char *x, char *y, int xi, int yi)
{

    if(x[xi] == '\0' || y[yi] == '\0') return 0; 

    if (x[xi] == y[yi]) return 1 + lcs (x, y, xi+1, yi+1);
    else return max(lcs(x, y, xi+1, yi), lcs(x, y, xi, yi+1));
}

int lcs1(char *x, char *y, int xi, int yi, int count)
{
    if(x[xi] == '\0' || y[yi] == '\0') return count; 
    
    int count1 = count; 
    
    if (x[xi] == y[yi]) {
        count1 = lcs1 (x, y, xi+1, yi+1, count + 1);
    }

    int count2 = lcs1(x, y, xi+1, yi, 0);
    int count3 = lcs1(x, y, xi, yi+1, 0);
    return max(count1, max(count3, count2));
}
int main()
{
    char x[] = "pqrabc";
    char y[] = "xyzabc";
    printf("lcs = %d\n", lcs1(x,y,0,0,0));
    return 0;
}
