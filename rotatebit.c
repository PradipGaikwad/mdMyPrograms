#include<stdio.h> 
  
int addOne(int x) 
{
    printf("x 0x%08x\n", x); 
    printf("~x 0x%08x\n", ~x); 
    printf("~x 0x%08x\n", -(~x)); 
   return (-(~x)); 
} 

#define mdprint(val) \
{ \
    int i;\
    unsigned int n = 0;\
    printf("\n %s: - ", #val);\
    for (i=(sizeof(val)*8 - 1); i>=0; i--) {\
        if(val >> i & 1 )\
            printf("1"); \
        else \
            printf("0");\
    }\
    printf("\n");\
}

void rotate_left (unsigned int val, int left)
{
    unsigned int z = 0;
    unsigned int intsz = 32;

    mdprint(val);
    val = (val >> (intsz - left)) | (val <<left);
    mdprint(val);

}
 
void rotate_right (unsigned int val, int left)
{
    unsigned int z = 0;
    unsigned int intsz = 32;
//    mdprint((~z)<<( intsz - 4));
//    mdprint((~z)<<(( intsz - 4))>>(intsz-4));

    mdprint(val);
    val = (val << (intsz - left)) | (val >>left);
    mdprint(val);

}

void count1 (unsigned int val)
{
int count = 0;
    while(val) {
        mdprint(val);
        val &= (val-1);
        mdprint(val);
        count++;
    } 
    printf("set bit =%d \n", count);

}
void abso( int val)
{
    unsigned int mask = val>>11;
    int r=0;
    mdprint(val);
    mdprint(~val);
    mdprint(mask);
    r = ~(val - 1);

    mdprint(r);
    printf("val %d = %d\n", val, r);
}
void max_min(int x, int y) 
{
    int r;
    printf("x<y %d\n", -(x<y));
    r = y ^ ((x^y) & 0);
    mdprint(-(x<y));
    mdprint(x^y);
    mdprint(y^(x^y));
    printf("r = %d\n", r);
}

unsigned int nextPowerOf2(unsigned int n) 
{ 
    unsigned count = 0; 

    // First n in the below condition 
    // is for the case where n is 0 
    if (n && !(n & (n - 1))){
        printf("already pow 2 \n"); 
        return n; 
    }
    printf("n = %d\n", n);
    while( n != 0) 
    { 
        n >>= 1; 
        count += 1; 
    } 

    return 1 << count; 
}

void swap(unsigned int num, int p1, int p2, int n)
{
    unsigned int mask = (1U<<n)-1;
    unsigned int set1, set2;
    unsigned int xor;

    mdprint(num);
    mdprint(mask);

    set1 = num >>p1 & mask;
    mdprint(set1);

    set2 = num >>p2 & mask;
    mdprint(set2);

    xor = set1 ^ set2;
    
    mdprint(xor);
    xor = xor << p2 | xor <<p1;
    mdprint(xor);
    mdprint(num);
    num = num ^ (xor <<p2); 
    mdprint(num);
    num = num ^ (xor <<p1); 
    mdprint(num);
    mdprint(xor);
    printf("num = %d\n", num);
}

void rev(unsigned int val)
{
   unsigned int tmp=0, i=31; 
    mdprint(val);
    
    while(val) {
        tmp |=  (val & 1)<<i;
        val = val >> 1;
        i--;
    }
    printf("loop %d\n", i);
    mdprint(val);
    mdprint(tmp);
    printf("tmp = 0x%x\n", tmp);
}
void alter (unsigned int val)
{
    unsigned int mask1=0x55555555;
    mdprint(val);
    val = ((val & mask1) <<1)| ( (val & mask1<<1)>>1);
    mdprint(val);
    printf("val = 0x%x\n", val); 
}
int main() 
{
    mdprint(0xa);
    printf("0x%8x\n", ((~((unsigned int)0))>>1)); 

    printf("\n rotate Left ===========================");
    rotate_left(0x5FF5FFF5,5);
    printf("\n rotate right ===========================");
    rotate_right(0x5FF5FFF5,5);
    printf("\n===count 1 ========================");
    count1(0xb);
    printf(" ==== ABS ==========\n");
    abso(-400);
    printf(" ==== Min Max ==========\n");
    max_min(10,7);
    max_min(7,10);
    printf(" ==== next pow 2  ==========\n");
    printf("==%d\n", nextPowerOf2(2)); 
    printf("==%d\n", nextPowerOf2(15)); 
    printf(" ==== swap p1 p2 n  ==========\n");
    swap(0xff00, 0, 12, 3);
    printf(" ==== reverse  ==========\n");
    rev(0xFFFF);
    printf(" ==== alter  ==========\n");
    alter(0x55555555);
    return 0;
} 
