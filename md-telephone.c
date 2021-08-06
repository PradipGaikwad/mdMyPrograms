
#include<stdio.h>
#include<string.h>
char *key[9];

void comb (char *key[], char *input, char *output, int idx, int j) {


    if(idx >= strlen(input)) {
        output[j] = '\0';
        printf("%s \n", output);
        return ;
    }
    
    int num = input[idx] - '0';

    for(int i=0; i<strlen(key[num]); i++) {
        
        output[j] = key[num][i];
        comb(key, input, output, idx+1, j+1);
    }
}

int main()
{

    key[0] ="";
    key[1]="";
    key[2]="abc";
    key[3]="def";
    key[4]="ghi";
    key[5]="jkl";
    key[6]="mno";
    key[7]="pqrs";
    key[8]="tuv";
    key[9]="wxyz";
    
    char input[10] = "3256";
    int j=0;
    for(int i=0; i<strlen (input); i++) {
        if(input[i]!='0' && input[i] != '1') {
            input[j] = input[i];
            j++;
        }
    }
    input[j] = '\0';
    char output[100];

    comb(key, input, output, 0, 0);
}




