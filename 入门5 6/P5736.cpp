#include<bits/stdc++.h>
using namespace std;
const int MAXN=100100;
int vis[MAXN];
int prime[MAXN];
void Prime(int n)
{
	int cnt=0;
    vis[0]=vis[1]=1;
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
    Prime(100010);
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(!vis[x])
        {
            cout<<x<<" ";
        }
    }
}