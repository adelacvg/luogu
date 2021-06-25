#include<bits/stdc++.h>
using namespace std;
const int MAXN=100010;
int vis[MAXN];
int prime[MAXN];
void Prime(int n)
{
    vis[0]=vis[1]=1;
	int cnt=0;
	for(long long i=2;i<=n;i++)
    {
        if(!vis[i]) prime[cnt++]=i;
        for(long long j=0;j<cnt&&i*prime[j]<=n;j++)
        {
            vis[i*prime[j]]=i;
            if(i%prime[j]==0) break;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    Prime(n);
    for(int j=4;j<=n;j+=2)
    {
        for(int i=2;i<=j/2;i++)
        {
            if(!vis[i]&&!vis[j-i])
            {
                cout<<j<<"="<<i<<"+"<<j-i<<endl;
                break;
            }
        }
    }
}