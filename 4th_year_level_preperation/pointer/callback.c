#include<stdio.h>

int sum(int a, int b)
{  
    return a+b;
}

int B(int (*ptr)(int,int),int a, int b)
{
   (*ptr)(a,b);
}
int main()
{
   int (*ptr)(int,int) = &sum;
   int c;
   c = B(ptr,4,5);
   printf("Sum came from callback function 4+5 = %d\n",c); 
   return 0;
}
