/* mdbabyjob*/
#include<stdio.h>
typedef struct node {
    int val;
    struct node *next;
}NODE;


void display_node(NODE *head)
{
    printf("\n");
    while(head) {
        printf("%d ->", head->val);
        head = head->next;
    }
    printf("\n");
}

NODE *add_node(NODE *head, int val)
{
    NODE *tmp;
    if(!head){
        head = (NODE*) malloc (sizeof(NODE));
        head->val = val;
        head->next = NULL;
    } else{ 
        tmp = (NODE*) malloc (sizeof(NODE));
        tmp->val = val;
        tmp->next = NULL;
        tmp->next = head;
        head = tmp;
    }
    return head;

}

int main()
{
    NODE *head = NULL;
    int i = 0;
    
    for( i=0; i<=10; i++) {

        head = add_node(head, i);
    }

    display_node(head);

    return 0;
}


