import math
fac=[math.factorial(n) for n in range(1010)]
n=int(input())
for _ in range(n):
    a,b=map(int,input().split())
    print(str(fac[a]).count(str(b)))
