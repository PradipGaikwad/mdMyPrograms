#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <limits.h>
#include <string.h>

typedef struct _list {
    int val;
    struct _list *next;
} list;

list *new_node(int val)
{
    list *tmp = (list *) malloc ( sizeof(list));
    tmp->next = NULL;
    tmp->val = val;
    return tmp;
}

void listadd(list **head, int val) 
{
    list *h1 = *head;   
    if(!h1) {
        *head = new_node(val);
        return ;
    }
    
    list *tmp = new_node(val);
    tmp->next = *head;
    *head = tmp;
}

void display(list *head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("\n");
}

void revListItrative(list **head)
{
    printf("-------------- %s -------------\n", __FUNCTION__);
    list *h1 = *head;
    list *prv = NULL;

    while(h1) {
        
        list *next = h1->next;
        h1->next = prv;
        prv = h1;
        h1 = next;
    }
    *head = prv;
}

list* revListRecursive(list *node, list **head) 
{
    if (node->next == NULL) {
        printf("-------------- %s -------------\n", __FUNCTION__);
        *head = node;
        return node;
    }
    
    //list *prv = node;
    list *next  = revListRecursive(node->next, head);
    next->next = node;
    node->next = NULL;
    return node;
}

void bubbleSort(list *head) 
{
    list *h1 = head, *h2 = head;
    printf("-------------- %s -------------\n", __FUNCTION__);
    list *end = NULL;

    while(h2) {
        h1 = head;
        while(h1 && h1->next != end) {
            
            if(h1->next && h1->val > h1->next->val) {
                int tmp = h1->val; h1->val = h1->next->val; h1->next->val = tmp;
            }       
            h1=h1->next;
        }
        end = h1;
        h2 = h2->next;
    }
}

void removeDup(list *head)
{
    printf("-------------- %s -------------\n", __FUNCTION__);
    
    list *h1 = head;
    list tmp;
    h1 = &tmp;
    //h1->next = head;
    int dup = 0;

    while(head) {
        dup = 0;
        while (head->next &&
                head && 
                head->val == head->next->val) {
            head->next = head->next->next;
            dup = 1;
        } 
        if (dup) {
            h1->next = head->next;
        } else {
            h1->next = head;
            h1 = head;
        }
        head = head->next;
    }
    display(tmp.next);
}

void findMid(list *head)
{
    list *f = head, *s = head;
    printf("-------------- %s -------------\n", __FUNCTION__);
    while(s && s->next) {
        f = f->next;
        s = s->next->next;
    }
    printf("mid point val %d ", f->val);
    (s!=NULL)? printf("odd\n"):printf("even \n");
}

int main() {
    
    list *head = NULL;
    for(int i=20; i<=30; i++) {
        listadd(&head,i);
        if(i%2==0)
            listadd(&head,i);
    }
    
    display(head);
    revListItrative(&head);
    display(head);
    revListRecursive(head, &head);
    display(head);
    bubbleSort(head);
    display(head);
    removeDup(head);
    listadd(&head, 100);
    display(head);
    findMid(head);
    listadd(&head, 101);
    display(head);
    findMid(head);
    listadd(&head, 102);
    display(head);
    findMid(head);
} 
