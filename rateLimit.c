// C++ program to insert element in Binary Tree
#include <iostream>
#include <queue>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int bucket_sz = 10;
int outrate = 3;
int input_sz = 4;
int no_of_pak = 100;

void leacky_bucket() {

    int storage = 0;
    
    for (int i=0; i< no_of_pak; i++) {
     
        int sz = bucket_sz - storage;
        if (sz >= input_sz ) {
            storage += input_sz;
            printf(" storage %d \n", storage);

        } else {
            printf("dropped %d \n", input_sz - sz);
            storage = bucket_sz;
        }

        storage -= outrate;
        printf(" after out storage %d \n", storage);
    }

}

int main()
{

    leacky_bucket();

    return 0;
}

