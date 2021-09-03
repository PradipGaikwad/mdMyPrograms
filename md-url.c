// C++ program to insert element in Binary Tree
#include <iostream>
#include <queue>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */

int main() {

    char str[100] ={0};

    char map[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    int num = 12345;

    int i = 0;

    while(num) {
        
        str[i++] = map[num%strlen(map)];
        num = num/strlen(map);
    }
    str[i] = '\0';
   
    printf("%s \n", str);
    
    i=0;
    int k = strlen(str)-1; 
    while(i<k) {
        char tmp = str[k];
        str[k] = str[i];
        str[i] = tmp;
        i++;k--;
    }

    printf("%s \n", str);

    int j = 0;
    int id = 0;
    for(k=0; k<strlen(str); k++) {
        char ch = str[k];
        
        if (ch >= 'a' && ch <= 'z') id = id*62 + ch - 'a';
        if (ch >= 'A' && ch <= 'Z') id = id*62 + ch - 'A' + 26;
        if (ch >= '0' && ch <= '9') id = id*62 + ch - '0' + 52;

    }
    printf("%d \n", id);
}
//abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789
