import math
n = int(input())
length = math.log10(2)*n+1
print(int(length))
ans=pow(2,n,10**500)
ans-=1
ans=str(ans).zfill(500)
for i in range(10,1,-1):
    print(str(ans)[-i*50:-(i-1)*50])
print(str(ans)[-50:])
