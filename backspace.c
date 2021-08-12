#include<stdio.h>
#include<string.h>


/*
int main()
{
    char *s1 = "ab##c";
    char *s2 = "ab##c";

    int l1 = strlen (s1) - 1;
    int l2 = strlen (s2) - 1;
    int bk = 0;

    while(l1 >=0 && l2 >=0) {

        bk=0;
        while (l1) {
            if(s1[l1] == '#') {bk++; l1--;}
            else if(bk >0) {bk--; l1--;}
            else break;
        }
        
        bk = 0;
        while (l2) {
            if(s2[l2] == '#') {bk++; l2--;}
            else if(bk >0) {bk--; l2--;}
            else break;
        }

        if(s1[l1] != s2[l2]) {
            printf("Not equal \n");
            return 0;
        }
        l1--;l2--;
    }
    if(l1==l2) printf("Equal \n");
}
*/

int main()
{
    char s1[] = "#a#b#ced#";
    char s2[] = "ab##c";

    int s=0, e=0;

    for(e=0; e<strlen(s1); e++) {
        if(s1[e] == '#') {
            if(s!=0) s--;
        } else s1[s++] = s1[e];
    }

    
    for(e=0; e<s; e++) printf("%c", s1[e]);
    printf("\n");


}
