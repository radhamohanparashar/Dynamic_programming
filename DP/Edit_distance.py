def edit_seq(L1,L2):
    m = len(L1)
    n = len(L2)
    L = [[None]*(n + 1) for i in xrange(m + 1)]
    for i in range(m + 1):
      for j in range(n + 1):
          if(i == 0):
             L[i][j] = j
          elif(j == 0):
             L[i][j] = i;
          elif(L1[i-1] == L2[j-1]):
             L[i][j] = L[i-1][j-1]
          else:
             L[i][j] = 1 + min( L[i][j-1],L[i-1][j-1],L[i-1][j] )
    return L[m][n]

def main():
  l1 = "cart"
  l2 = "march"
  print edit_seq(l1,l2)  

main()
