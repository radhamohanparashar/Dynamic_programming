#include<stdio.h>
int main()
{
   int i = 100;
   int count = 0;
   while(i)
   {
     count += (i&1);
     i = i>>1;
   }
   printf("%d\n",count);
   return 0;
}
