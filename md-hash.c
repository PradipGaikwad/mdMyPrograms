// C++ program to insert element in Binary Tree
#include <iostream>
#include <queue>
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

struct item {
    int val;
    struct item *next;
    //pthread_mutex lock
};


struct hashtbl {
    int buckets;
    struct item **item_ptr;
};

void print(struct hashtbl *obj) 
{
    for(int i=0; i<obj->buckets; i++) {
        printf("%d :", i);
        struct item *list = obj->item_ptr[i];
        while(list) {
            printf("%d -> ", list->val);
            list = list->next;
        }
        printf("\n");
    }
}
void insert(struct hashtbl *obj, int val)
{
    int buck = val % obj->buckets;
    
    struct item *newitem = (struct item *) malloc(sizeof(struct item));
    newitem->val = val;
    newitem->next = NULL; 

    if(obj->item_ptr[buck] == NULL) {
        obj->item_ptr[buck] = newitem;
        return;
    }

    newitem->next = obj->item_ptr[buck];
    obj->item_ptr[buck] = newitem;
}
int main() {

    struct hashtbl obj;

    obj.buckets = 40;
    obj.item_ptr = (struct item **) malloc (sizeof(struct item *) * obj.buckets);
    for(int i=0; i< obj.buckets; i++) obj.item_ptr[i] = NULL;

    for(int i=0; i<80; i++) {
        insert(&obj, i);
    }
        print(&obj);

}
