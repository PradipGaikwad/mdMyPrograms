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
int main()
{
    char x[] = "zxyabcdll";
    char y[] = "paqrbcdpp";
    printf("lcs = %d\n", lcs(x,y,0,0));
    return 0;
}
