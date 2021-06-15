#include<stdio.h>


int main ()
{

    int size = sizeof (unsigned int);
    unsigned int bit = 1;
    int loop = 0, i, sz;
    int arr[] = { 12, 1, 7, 3, 7, 1, 1, 2, 3, 2, 2, 3, 7 };
    int num = 0;
    int sum = 0;
    printf ("arry len %d\n", sz = sizeof (arr) / sizeof (arr[0]));
    printf ("size of int %d\n", sizeof(unsigned int));

    for (i=0; i < sz; i++) {
        printf("a[%d] = 0x%08x\n", i, arr[i]);
    }

    for (loop = 0; loop < size*8; loop++) {

        sum = 0;
        printf ("bit 0x%08x\n", 1 << loop);

        bit = 1 << loop;
        for (i=0; i < sz; i++) {
       //     printf("a[%d] = %d\n", i, arr[i]);
            if (arr[i] & bit) sum++; 
        }
        if (sum % 3) {
            num |= bit;
            printf("num = 0x%08x \n", num);
        }
    }

    printf("final asn %d \n", num);
    return 0;
}
