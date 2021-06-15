
#include<stdio.h>
       #include <stdlib.h>

typedef struct _list {
    int val;
    struct _list *next;
} list;

list* alloc_node(int val) {
    
    list *tmp = (list*) malloc (sizeof(list));
    tmp->val = val;
    tmp->next = NULL;
    return tmp;
}


list *head=NULL;


void display(list *head) {
    list *tmp = head;
    while(tmp) {
        printf("%d->", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");
}




int main() {

    list *tmp=head;;
    tmp = alloc_node(0);
    head = tmp;
    for (int i=1; i<10; i++) {
        tmp->next = alloc_node(i);
        tmp = tmp->next;
    }
    display(head);

    list *start = head, *end = NULL, *fun=head;

    int swap = 1;
//while(swap == 1) {
    while(fun) {
        start = head; swap = 0;
        while(start->next != end) {
            if(start->val < start->next->val) {
                int tmp = start->val;
                start->val = start->next->val;
                start->next->val = tmp;
                swap = 1;
            }
            start = start->next;
        }
        end = start;
        fun = fun->next;
    }
    display(head);
}



