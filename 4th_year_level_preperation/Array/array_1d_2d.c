#include<stdio.h>
int main()
{ 
   int **ptr = NULL;
   ptr = (int *)malloc(sizeof(int *) * 10);
   for(int i=0;i<10;i++)
     *(ptr+i) = (int *)malloc(sizeof(int) * 10);
   for(int i=0;i<10;i++)
    {
      for(int j=0;j<10;j++)
      {
        (*(*(ptr+i)+j)) = ((i+1)*(j+1));
     }
   }
   for(int i=0;i<10;i++)
    {
      for(int j=0;j<10;j++)
      {
        printf(" %dth and %dth = %d\n",i,j,*(*(ptr+i)+j));
     }
   }
  return 0;
}
