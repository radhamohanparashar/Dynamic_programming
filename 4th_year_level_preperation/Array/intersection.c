#include<stdio.h>
int* intersection(int *arr1,int *arr2, int l1, int l2)
{
   int i=0,j=0,k=0;
   int size = 0;
   if(l1 < l2) size=l1;
   else size=l2;
   int *ptr = NULL;
   ptr = (int *)malloc(sizeof(int) * size);
   memset(ptr,-1,size*sizeof(int));
   while ( i<l1 && j<l2)
   {
     if(arr1[i] < arr2[j]) 
        i++;
     else if(arr1[i] > arr2[j])
        j++;
     else
      {
        (*(ptr+k)) = arr1[i];k++;i++;j++; }
   }
   return ptr;
}


int * middle_layer(int *(*funct_ptr)(int *, int *, int,int),int *arr1,int *arr2,int l1,int l2)
{
    return (*funct_ptr)(arr1,arr2,l1,l2);
}
int main()
{
   int ptr[] = {1,2,3,4,5};
   int next[] = {3,4,5,6,7,8,9};
   int *(*funct) = &intersection;
   int *final = NULL;
   final = middle_layer(funct,ptr,next,sizeof(ptr)/sizeof(ptr[0]),sizeof(next)/sizeof(next[0]));
   while(1)
   {
     if(*(final) != -1)
       printf("%d \n",*(final++));
     else
       break;
   }
  return 0; 
}
