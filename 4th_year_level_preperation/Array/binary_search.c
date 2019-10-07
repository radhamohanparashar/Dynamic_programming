#include<stdio.h>
void stack(int *ptr,int n,int l)
{
   int k=0;
   while(*(ptr+k) != -1)
   {
     k++;
   }
   while(k > 0)
   {
      *(ptr+k) = *(ptr+k-1);
      k--;
   }
   *ptr = n;
}
void binary_search(int *ptr,int n,int l)
{
  int start = 0;
  int len = l;
  while(1)
  {
    if(start > len)
       break;
    if(ptr[(len+start)/2] > n)
      start = (start + len)/2; 
    else if(ptr[(len+start)/2] < n)
       len = (start + len)/2;
    else
       { printf("Element for %d element is %dth\n\n ",n,(start + len)/2);break; }
  }
}
void middle_layer(void (*functptr)(int *,int,int),int *ptr,int n,int len)
{
   (*functptr)(ptr,n,len);
}

int main()
{
   int arr[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
   void (*ptr) = &stack;
   void (*ptr1) = &binary_search;
   middle_layer(ptr,arr,1,10);
   middle_layer(ptr,arr,2,10);
   middle_layer(ptr,arr,3,10);
   middle_layer(ptr,arr,4,10);
   middle_layer(ptr,arr,5,10);
   middle_layer(ptr,arr,6,10);
   middle_layer(ptr,arr,7,10);
   middle_layer(ptr,arr,8,10);
   middle_layer(ptr,arr,9,10);
   middle_layer(ptr,arr,10,10);
   middle_layer(ptr1,arr,4,10);
   for(int i=0;i<10;i++)
     printf("Element %dth = %d\n",i,arr[i]);
   return 0;
}
