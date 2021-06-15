#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <limits.h>
#include <string.h>
int num=1;
void gen_valid(int k, int n, char *str, int lp, int rp) 
{
    if(k>=n*2) {
        str[k]='\0';
        printf("%d :%s \n", num++,str);
        return;
    }

    if(rp<lp) {
        str[k] = ')';
        gen_valid (k+1, n, str, lp, rp+1);
    } 
    if(lp<n) {
        str[k]='(';
        gen_valid(k+1, n, str, lp+1, rp);
    }

}

int isvalid(char *str) {
    int sum = 0;
    for(int i=0; i<strlen(str); i++) {
       
        if(str[i] == '(') sum += 1;
        if(str[i] == ')') sum -= 1;
        if(sum <0) return 0;
    }
    return (sum == 0)? 1:0;
}
void genall(int k, int n, char *str, int lp, int rp) 
{
    if(k>=n*2) {
        str[k]='\0';
        if(isvalid(str))
            printf("%d :%s \n", num++,str);
        //printf("%s \n", str);
        return;
    }

    str[k] = '(';
    genall(k+1, n, str, lp+1, rp);
    str[k] = ')';
    genall(k+1, n, str, lp, rp+1);

}
int main()
{
    int len = 3;
    char str[10]={0};
    printf("valid Parenthisis \n");
    gen_valid (0, len, str, 0, 0);
    num = 1;
    printf("\n\nAll Parenthisis \n");
    genall(0, len, str, 0, 0);
}
