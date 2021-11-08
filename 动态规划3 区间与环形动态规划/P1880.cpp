#include<bits/stdc++.h>
using namespace std;
const int maxn=220;
int a[maxn];
int dp_min[maxn][maxn];
int dp_max[maxn][maxn];
int suf[maxn];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=2*n;i++)
        for(int j=i+1;j<=2*n;j++)
            dp_min[i][j]=1000000;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i+n]=a[i];
    }
    for(int i=1;i<=2*n;i++)
    {
        suf[i]=suf[i-1]+a[i];
    }

    for(int len=1;len<=n;len++)
    {
        for(int i=1;i<=2*n;i++)
        {
            auto j=min(i+len,2*n);
            for(int k=i;k<j;k++)
            {
                auto &t=dp_min[i][j];
                if(dp_min[i][k]+dp_min[k+1][j]+
                suf[j]-suf[i-1]<t)
                {
                    t=dp_min[i][k]+dp_min[k+1][j]+
                    suf[j]-suf[i-1];
                }
                auto &t1=dp_max[i][j];
                if(dp_max[i][k]+dp_max[k+1][j]+
                suf[j]-suf[i-1]>t1)
                {
                    t1=dp_max[i][k]+dp_max[k+1][j]+
                    suf[j]-suf[i-1];
                }
            }
        }
    }
    int ans_min=INT_MAX,ans_max=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        ans_min=min(ans_min,dp_min[i][i+n-1]);
        ans_max=max(ans_max,dp_max[i][i+n-1]);
    }
    cout<<ans_min<<endl;
    cout<<ans_max<<endl;
}