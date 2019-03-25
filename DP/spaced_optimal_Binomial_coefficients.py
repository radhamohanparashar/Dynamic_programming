def binaomialCoefficient(n,k):
    L = [0]*(k + 1)
    L[0] = 1
    for i in range(1,n+1):
      for j in range(min(i,k),0,-1):
           L[j] = L[j-1] + L[j]
    return L[k]

def main():
    n = 4
    k = 2
    print binaomialCoefficient(n,k)

main()
