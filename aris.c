#include<stdio.h>
#include<assert.h>
#include<pthread.h>
struct data {

    int a;
    int b;
};

int count=0;

struct data d1={0};
struct data d2;
struct data *wptr, *rptr;

/*
void CAS(address, newval, oldval) {

    while(1) {
        val = *address;
        if(val == oldval) {
            *address = newval;
            break;
        } else {
            oldval = *address;
        }
}
*/

void testShort1() {
    short l[2];
    short cmp, repl;
    short *ptr = &(l[1]);
    int replaced;

    l[0] = 32;
    l[1] = 42;

    cmp = 42;
    repl = 3;
    replaced = __sync_val_compare_and_swap(ptr, cmp, repl);
    printf("replaced %d\n", replaced);
    printf("%d\n", l[0]);
    printf("%d\n", l[1]);

    l[0] = 32;
    l[1] = 42;

    cmp = 1;
    repl = 3;
    replaced = __sync_val_compare_and_swap(ptr, cmp, repl);
    printf("R-II %d\n", replaced);
    printf("%d\n", l[0]);
    printf("%d\n", l[1]);
}

void* myfun1 ()
{
    struct data *tmp;
    while(1) {
        
        wptr->a = rptr->a;
        wptr->b = rptr->b;

        wptr->a = (wptr->a+1)%100;
        wptr->b = (wptr->b+1)%100;
        tmp = rptr;
        //printf("w %p, r %p \n", wptr, rptr);
        //(void) __sync_val_compare_and_swap(&rptr, &rptr, &wptr);
        //printf("w %p, r %p \n", wptr, rptr);
       // break;
        //wptr = tmp;

    }
}

void* myfun2 ()
{
    int da, db;
    while(1) {
        
               printf("a %d, b %d \n", rptr->a, rptr->b);
        if (rptr->a != rptr->b) {
               printf("a %d, b %d \n", rptr->a, rptr->b);
               return ;
        }
    }
}
int main()
{
    testShort1();
    return;
    rptr = &d1;
    wptr = &d2;
    pthread_t tid=1;
    pthread_create(&tid, NULL, &myfun1, NULL);
    tid =2;
    pthread_create(&tid, NULL, &myfun2, NULL);
    pthread_join(tid, NULL);
    
}



