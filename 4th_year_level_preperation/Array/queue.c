#include<stdio.h>
void queue(int *ptr,int n)
{
   int k=0;
   while(*(ptr+k) != -1)
   {
     k++;
   }
   *(ptr+k) = n;
}
void middle_layer(void (*functptr)(int *,int),int *ptr,int n)
{
   (*functptr)(ptr,n);
}

int main()
{
   int arr[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
   void (*ptr) = &queue;
   middle_layer(ptr,arr,1);
   middle_layer(ptr,arr,2);
   middle_layer(ptr,arr,3);
   middle_layer(ptr,arr,4);
   middle_layer(ptr,arr,5);
   middle_layer(ptr,arr,6);
   middle_layer(ptr,arr,7);
   middle_layer(ptr,arr,8);
   middle_layer(ptr,arr,9);
   middle_layer(ptr,arr,10);
   for(int i=0;i<10;i++)
     printf("Element %dth = %d\n",i,arr[i]);
   return 0;
}
