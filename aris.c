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

void* myfun1 ()
{
    struct data *tmp;
    while(1) {
        
        wptr->a = rptr->a;
        wptr->b = rptr->b;

        wptr->a = (wptr->a+1)%100;
        wptr->b = (wptr->b+1)%100;
        tmp = wptr;
        wptr = rptr;
        rptr = tmp;

    }
}

void* myfun2 ()
{
    int da, db;
    while(1) {
        
        if (rptr->a != rptr->b) {
               printf("a %d, b %d \n", rptr->a, rptr->b);
               return ;
        }
    }
}
int main()
{
    rptr = &d1;
    wptr = &d2;
    pthread_t tid=1;
    pthread_create(&tid, NULL, &myfun1, NULL);
    tid =2;
    pthread_create(&tid, NULL, &myfun2, NULL);
    pthread_join(tid, NULL);
    
}



