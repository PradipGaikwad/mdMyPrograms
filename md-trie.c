// C++ program to insert element in Binary Tree
#include <iostream>
#include <queue>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;


typedef struct _trie {
    int isleaf;
    struct _trie *ptr[26];
} trie;

trie *root1;
trie *newnode() {
    trie *tmp = (trie*) malloc(sizeof(trie));
    for(int i=0; i<26; i++) {
        tmp->ptr[i] = NULL;
    }
    tmp->isleaf = 0;
    return tmp;
}

void insert(const char *str) {
    trie *root = root1;

    for(int i=0; i<strlen(str); i++) {
        int index = str[i] - 'a';

        if (!root->ptr[index]) {
            root->ptr[index] = newnode();
        }
        root = root->ptr[index];
    }
    root->isleaf = 1;
}

int allnull(trie *root) {

    for(int i=0; i<26; i++) {
        if (root->ptr[i]) return 0;
    }
    return 1;
}

int del(const char *str, int i, trie *root) {

    if (!root) return 1;

    if(root->isleaf) {
        root->isleaf = 0;
        return 1;
    }

    int index = str[i] - 'a';
    root = root->ptr[index];
    if (del(str, i+1, root)) {
        if (allnull(root)) {
            root=NULL;
            free(root);
            return 1;
        }
    }
    return 0;
}

void search(const char *str) {
    trie *root = root1;

    for (int i=0; i < strlen(str); i++) {
        int index = str[i] - 'a';
        
        if (!root->ptr[index]) {
            printf("Not Found\n");
            return;
        }
        root = root->ptr[index];
    }
    if (root->isleaf) {
        printf("found \n");
        return ;
    }
}


int main() {
    
    root1 = newnode();
    insert("pradeep");
    search ("pradeep");
    search ("manoj");
    insert("manoj");
    search ("manoj");
    del("manoj", 0, root1);
    search ("manoj");
    return 0;
}
