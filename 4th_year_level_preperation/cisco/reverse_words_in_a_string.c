#include<stdio.h>
#include<string.h>
int main()
{
   char *s="I love my india";
   char *new=NULL;
   int len = strlen(s);
   char *temp = s;
   temp = temp + len;
   while(len > 0)
   {
     if( *temp == ' ')
      {
       printf("%s \n",temp);
       *(temp) = '\0';
      }
     if(len != 0)
      {
       temp--;len--; }
     if (len == 0){
       printf("%s \n",temp);}
   }
   return 0;
}
