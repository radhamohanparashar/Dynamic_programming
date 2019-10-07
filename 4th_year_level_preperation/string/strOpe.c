#include<stdio.h>
int my_strlen(char *s)
{
   int i=0;
   while(*s++ != NULL)
      i++;
   return i;
}
void my_strcat(char *s,char *d)
{
   int k=0;
   while(*s++ != NULL)
      k++;
   *s--;
   while(*d != NULL)
   {
      *s++ = *d++;k++;
   }
}
void my_strrev(char *s,int l)
{
   int k= l-1;
   int start = 0;
   char ch;
   while ( k > start )
   {
     ch = *(s+start);
     *(s+start) = *(s+k);
      *(s+k) = ch;
     start++;
     k--;
   }
}
int main()
{
   char str[] = "Radhamohan parashar";
   int l=0;
   char str1[30] = "Name = ";
   l = my_strlen(str);
   printf("Sring length = %d\n",l);
   my_strcat(str1,str);
   printf("String after concat = \"%s\"\n",str1); 
   my_strrev(str1,my_strlen(str1));
   printf("After strrev String = \"%s\"\n",str1); 
   return 0;
}
