#include<stdio.h>
#include<string.h>
#include <stdlib.h>

#define max_sz      10

struct queue {

    int head;   
    int tail;
    char data[max_sz];
    int sz;
};

void dump(struct queue *q) {
    if(!q) return ;
    printf("head:tail - %d:%d \n", q->head, q->tail);
    for(int i=0;i<max_sz; i++) {
        printf("%c ->", q->data[i]);
    }
    printf("\n");
}


void push(struct queue *q, const char *udata) {

    if(q->sz == max_sz -1) {
        printf("queue Full \n");
        return;
    }

    q->sz += 1;
    
    for(int i=0;i<strlen(udata); i++) {
        q->tail = (q->tail + 1) % max_sz;
        if(q->tail == q->head) q->head++;
        q->data[q->tail] = udata[i];
        if(q->head==-1) q->head=0;
    }
    dump(q);
}

struct queue* initq() {

    struct queue *q = (struct queue *) malloc (sizeof(struct queue));
    q->sz = 0;
    q->head = -1;
    q->tail = -1;
    q->data[0] = '\0';
    return q;
}

int main()
{
    struct queue *q; 
    q = initq();

    push(q,"ABCD");
    push(q,"EFGH");
    push(q,"IJKLM");
    push(q,"abcd");
}
