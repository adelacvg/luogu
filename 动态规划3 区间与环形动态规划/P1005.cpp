#include<bits/stdc++.h>
using namespace std;
using i64 = __uint128_t;
i64 a[100][100];
i64 dp[100][100][100];
i64 pwr[100];
i64 read() {
    i64 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void print(i64 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}
void init()
{
    pwr[0]=1;
    for(int i=1;i<=100;i++)
    {
        pwr[i]=pwr[i-1]*2;
    }
}
int main()
{
    init();
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            a[i][j]=read();
        }
    }
    i64 ans=0;
    for(int i=1;i<=n;i++)
    {
        i64 mx=0;
        for(int len=m-2;len>=0;len--)
        {
            auto cnt=m-len-1;
            for(int l=1;l<=m;l++)
            {
                auto r=l+len;
                if(r>m)
                    break;
                dp[i][l][r]=max(
                    dp[i][l-1][r]+pwr[cnt]*a[i][l-1],
                    dp[i][l][r+1]+pwr[cnt]*a[i][r+1]);
                if(len==0)
                {
                    mx=max(mx,
                    dp[i][l][r]+a[i][l]*pwr[m]);
                }
            }
        }
        ans+=mx;
    }
    print(ans);
}