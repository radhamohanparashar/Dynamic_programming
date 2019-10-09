#include<stdio.h>
#define mysizeof(type) (char *)(&type +1) - (char *)(&type)
void show_mem_rep(char *show,int n)
{
  int i;
  for(i=0;i<n;i++)
    printf("%.2x",show[i]);
  printf("\n");
}
void check_for_endinaness()
{
    int i = 1;
    if((char *)&i)
      printf("Little endian\n");
    else
      printf("Big endian\n");
}
int change_little_to_big(int x)
{
  return (  ((x>>24) & 0x0000000ff) | ((x>>8) & 0x00000ff00) | ((x<<8) & 0x00ff0000) | ((x<<24) & 0xff000000));
}
int main()
{
   int i=0x01234567;
   show_mem_rep((char *)&i,mysizeof(i));
   check_for_endinaness();
   i = change_little_to_big(i);
   show_mem_rep((char *)&i,mysizeof(i));
   return 0;
}
