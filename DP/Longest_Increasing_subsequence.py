""" 
************************************************************
Description : 

Get a dummy list and initialise all the element by 1
Now
 Iterate my_list and compaire every element with it's elements
before it and find if current element is greater than with it,
if yes then first check value of dummy[compared] should be 
greater than with dummy[current] : 
 
If both condition yes then increase with value 1 at same indexed 
value of dummy list by compared indexed value of dummy

 
if(my_list[current] > dummy[compared]) and (dummy[current] < dummy[compared] + 1 )
dummy[current] = dummy[compared] + 1

		
**************************************************************
"""
def lis(my_list,n):
    MAX = 0
    dummy = [1]*n
    for i in range(1,n):
      for j in range(0,i):
         if(my_list[i] >= my_list[j]) and (dummy[i] < dummy[j] + 1):
             dummy[i] = dummy[j] + 1

    for i in range(0,n):
       if( dummy[i] > MAX ):
           MAX = dummy[i]
    return MAX

def main():
   my_list = [10,22,9,33,21,50,41,60]
   n = len(my_list)
   sub_set = lis(my_list,n)
   print sub_set

main()
