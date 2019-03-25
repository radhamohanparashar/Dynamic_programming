"""
Description : 

Rule 1 : If last character matches : 
            lcs[i][j] = lcs[i-1][j-1] + 1
         Else:
            lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1])
Rule 2: 
         Initialise all starting indexes of i = 0 or j = 0 with 0

To get Longest common subseq : 
     
       Start with bottom and rightmost and follow given point:
       1. If we see the stored value is not the max of top and left cell 
            then it means it is a part of longest common substring.
       2. Pick point 1 character and move diagonally up.
       3. If it matches with max of anyone then move towards max side and continue.

""" 
from array import *
def lcs(X, Y): 
    m = len(X) 
    n = len(Y) 
    lcs = [] 
    # declaring the array for storing the dp values 
    L = [[None]*(n + 1) for i in xrange(m + 1)] 
  
    """Following steps build L[m + 1][n + 1] in bottom up fashion 
    Note: L[i][j] contains length of LCS of X[0..i-1] 
    and Y[0..j-1]"""
    for i in range(m + 1): 
        for j in range(n + 1): 
            if i == 0 or j == 0 : 
                L[i][j] = 0
            elif X[i-1] == Y[j-1]: 
                L[i][j] = L[i-1][j-1]+1
            else: 
                L[i][j] = max(L[i-1][j], L[i][j-1]) 
    i = m
    j = n
    while i > 0 or j > 0:
        if j<=0 or i<=0:
            break
        if L[i][j] != max(L[i-1][j],L[i][j-1]):
            lcs.append(X[i-1])
            i = i - 1
            j = j - 1
        else:
           if L[i][j] == L[i-1][j]:
              i = i-1
           else:
              j = j-1
  
    # L[m][n] contains the length of LCS of X[0..n-1] & Y[0..m-1] 
    return lcs 

def Alcs(x,y,m,n):
    print x,y,m,n
    lcs = []
    l = [[0]*(m+1)]*(n+1)
    for i in range(1,m):
      for j in range(1,n):
         if((i == 0) or (j == 0)):
              l[i][j] = 0
         elif (x[i-1] == y[j-1]):
              l[i][j] = l[i-1][j-1] + 1
         else:
              l[i][j] = max(l[i-1][j],l[i][j-1])
    print l
    i = m
    j = n
    while i > 0 or j > 0:
        if j<=0 or i<=0:
            break
        print i , j, l[i][j], l[i-1][j] , l[i][j-1]
        if l[i][j] != max(l[i-1][j],l[i][j-1]):
            lcs.append(x[i-1])
            i = i - 1
            j = j - 1
        else:
           if l[i][j] == l[i-1][j]:
              i = i-1
           else:
              j = j-1
    print lcs
    return l[n][m] 


def main():
   l1= "AGGTAAB"
   l2 = "GXTXAYAXB"   
   L = lcs(l1,l2)[::-1]
   print "".join(str(x) for x in L)

main()
