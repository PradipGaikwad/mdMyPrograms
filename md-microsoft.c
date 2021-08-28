// C++ program to insert element in Binary Tree
#include <iostream>
#include <queue>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/*
//ab + bc = ac
//

*/
void gen (char *str, int j) {

    if(j >2) {
        str[j] = '\0';
        printf("%s ", str);
        return;
    }

    for(int i=0; i<=9; i++) {
        str[j] = '0' + i;
        gen(str, j+1);
    }
}

int main() {
    char str[10];
    gen(str, 0);
}
