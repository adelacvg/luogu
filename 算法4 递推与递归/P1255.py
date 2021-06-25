n=int(input())
x=1
y=2
z=0
if n==1 or n==2:
    print(n)
else:
    n-=2
    for _ in range(n):
        z=x+y
        x=y
        y=z
    print(z)
