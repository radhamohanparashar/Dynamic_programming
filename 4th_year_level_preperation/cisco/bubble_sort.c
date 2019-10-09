#include<stdio.h>
void swap(int *a,int *b)
{
   int x;
   x = *a;
   *a = *b;
   *b = x;
}
int main()
{
   int num[] = {3,12,45,22,44,11,65,77,66,55,44,33,243,1112,111};
   int n = sizeof(num)/sizeof(num[0]);
   for(int i=0;i<n;i++)
    {
     for(int j=0;j<n-i-1;j++)
     { 
       if(num[j] > num[j+1])
         swap(&num[j],&num[j+1]);
     }
   }
   for(int i=0;i<n;i++)
      printf("%d ",num[i]);
   return 0;
}
