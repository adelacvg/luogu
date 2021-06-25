#include<bits/stdc++.h>
using namespace std;
const int MAXN=200000;

int vis[MAXN];
int prime[MAXN];
void Prime(int n)
{
    vis[0]=1;
    vis[1]=1;
	int cnt=0;
	for(int i=2;i<=n;i++)
    {
        if(!vis[i]) prime[cnt++]=i;
        for(int j=0;j<cnt&&i*prime[j]<=n;j++)
        {
            vis[i*prime[j]]=i;
            if(i%prime[j]==0) break;
        }
    }
}

int main()
{
    Prime(1000);
    string s;
    cin>>s;
    map<char,int> m;
    for(auto i:s)
    {
        m[i]++;
    }
    int maxn=-10000,minn=10000;
    for(auto [i,j]:m)
    {
        maxn=max(j,maxn);
        minn=min(j,minn);
    }
    if(!vis[maxn-minn])
    {
        cout<<"Lucky Word"<<endl;
        cout<<maxn-minn<<endl;
    }
    else
    {
        cout<<"No Answer"<<endl;
        cout<<0<<endl;
    }
}