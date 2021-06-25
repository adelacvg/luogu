n = int(input())
if n==3:
    print("1 2")
    print(2)
elif n==4:
    print("1 3")
    print(3)
else:
    t=2
    pro=1
    l=[]
    while t<=n:
        l.append(t)
        n-=t
        t+=1
    for i in range(len(l)-1,len(l)-1-n,-1):
        l[i]=l[i]+1
    print(*l)
    ans=1
    for i in range(len(l)):
        ans*=l[i]
    print(ans)
