m,n = map(int,input().split())
dp=[0 for i in range(1010)]
dp[1]=1
dp[2]=2
for i in range(3,n-m+1):
    dp[i]+=dp[i-1]+dp[i-2]
print(dp[n-m])
