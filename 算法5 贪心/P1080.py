n = int(input())
a,b = map(int,input().split())
v = [list(map(int,input().split())) for _ in range(n)]
v.sort(key=lambda x:x[0]*x[1])
ans = 0
pro = a
for x in v:
    if pro//x[1]>ans:
        ans=pro//x[1]
    pro*=x[0]
print(ans)
