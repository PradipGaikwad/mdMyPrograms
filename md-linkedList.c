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
    printf("NULL \n");
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

list* _reverseKnodes(list **cur, int k) 
{
    list  *prv = NULL, *next;
    
    while(*cur && k>0) {
        next = (*cur)->next;
        (*cur)->next = prv;

        prv=*cur;
        *cur = next;

        k--;
    }
    return prv;
}

void reverseKnodes(list **head, int k)
{
    list *cur = *head, *newhead, *prv = NULL;
    list *end, *start;
    printf("-------------- %s -------------\n", __FUNCTION__);

    while (cur) {
        // 1st node gonaa be last
        end = cur;
        //get the last node and next node to the last node
        start = _reverseKnodes(&cur, k);

        if (!prv) newhead = start;
        else prv->next = start;
        int n ;
        n = k;
        end->next = cur;

        while(cur && n) {
            n--;
            prv = cur;
            cur = cur->next;
        }
    }
    *head = newhead; 
    display(newhead);
}
int fib(int n) 
{
    if (n<=1) return n;
    return fib(n-1) + fib(n-2);
}

void _fib() {
    printf("-------------- %s -------------\n", __FUNCTION__);
    int n =31;
    printf("fib %d = %d\n", n , fib(n));

    int a=0, b=1, c; 
    for(int i=2; i<=n; i++){
        c = a + b;
        a=b; b = c;
    }

    printf("fib %d = %d\n", n , c);
}

void runnerLengthEncoding()
{

    printf("-------------- %s -------------\n", __FUNCTION__);
    char str[100] = "AAABBBCCCDDDDEEEEFF";
    char encode[200]={0};
    char encode1[200]={0};
    int count;
    for (int i=0; i<strlen(str); i++) {
        count = 1;
        while(i+1 < strlen (str) && str[i] == str[i+1]) {
            count++; 
            i++;
        }
        sprintf(encode, "%c%d", str[i], count);
        strcat(encode1, encode);
    }
    printf("%s\n", encode1);
}
void even_odd(list *head) {
    list oddh, evenh;
    list *odd, *even;
    
    odd = &oddh;
    even = &evenh;

    while(head) {
        if(head->val % 2) {
             odd->next = head;
             odd = odd->next;
        } else {
            even->next = head;
            even = even->next;
        }
        head = head->next;
    }
    odd->next = NULL;
    even->next = NULL;
    display(evenh.next);
    display(oddh.next);

}
int main() {
    
    list *head = NULL;
    for(int i=10; i<=25; i++) {
        listadd(&head,i);
 //       if(i%2==0)
   //         listadd(&head,i);
    }
    
    display(head);
    revListItrative(&head);
    display(head);
    revListRecursive(head, &head);
    display(head);
    bubbleSort(head);
    display(head);
    reverseKnodes(&head, 3);
    reverseKnodes(&head, 3);
    _fib();
    runnerLengthEncoding();
    even_odd(head);
    display(head);
} 
