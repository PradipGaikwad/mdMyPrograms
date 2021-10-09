// C++ program to insert element in Binary Tree
#include <iostream>
#include <queue>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

void rev(char * s, int st, int en) {


    while(st < en) {
        char ch = s[st];
        s[st] = s[en];
        s[en] = ch;
        st++; en--;
    }
}

int main() {

    char str[] = ".   This is a Horse";
    int st = 0;

    for (int i=0; i <= strlen(str); i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            rev (str, st, i-1);
            st = i+1;
        }
    }

    printf("%s\n", str);
    rev(str, 0, strlen(str)-1);
    printf("%s\n", str);

}

