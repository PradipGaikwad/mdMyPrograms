#include<stdio.h> 
  
int addOne(int x) 
{
    printf("x 0x%08x\n", x); 
    printf("~x 0x%08x\n", ~x); 
    printf("~x 0x%08x\n", -(~x)); 
   return (-(~x)); 
} 
  
/* Driver program to test above functions*/
int main() 
{ 
  printf("%d\n", addOne(13)); 
  printf("%d\n", addOne(10)); 
  printf("%d\n", addOne(11)); 
  return 0;
} 
