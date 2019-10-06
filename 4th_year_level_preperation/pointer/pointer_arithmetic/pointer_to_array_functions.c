#include<stdio.h>
void increament()
{
   int *ptr = NULL;
   int i=0;
   ptr = (int *)malloc(sizeof(int)*10);
   for(i = 0;i<10;i++)
     *(ptr+i) = (i+1)*10;
   for(i=0;i<10;i++)
      printf("%dth Element = %d\n",i,*(ptr+i));
   free(ptr);
}
void decrement()
{
   int *ptr = NULL;
   int i=0;
   ptr = (int *)malloc(sizeof(int)*10);
   for(i = 0;i<10;i++)
     *(ptr++) = (i+1)*10;
   for(i=10;i>0;i--)
      printf("%dth Element = %d\n",i,*(--ptr));
   free(ptr);
}
void addition()
{
   int *ptr=NULL;
   int i = 0,sum = 0;
   ptr = (int *)malloc(sizeof(int) * 10);
   for(i=0;i<10;i++)
     *(ptr+i) = (i+1)*10;
   for(i=0;i<10;i++)
     sum = sum + *(ptr+i);
   printf("sum = %d\n",sum);
}
void middle_layer(void (*func_ptr)())
{
   (*func_ptr)();
} 
int main()
{
   void (*ptr[])() = {&increament,&decrement,&addition};
   middle_layer(ptr[0]);
   middle_layer(ptr[1]);
   middle_layer(ptr[2]);
   return 0;
}
