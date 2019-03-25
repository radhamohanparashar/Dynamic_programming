def binaomialCoefficient(n,k):
    L = [[0]*(k + 1) for i in xrange(n + 1)]
    for i in range(n+1):
      for j in range(min(i,k)+1):
        if(j == 0 or j == i):
            L[i][j] = 1
        else:
           L[i][j] = L[i-1][j-1] + L[i-1][j]
    return L[n][k]

def main():
    n = 4
    k = 2
    print binaomialCoefficient(n,k)

main()
