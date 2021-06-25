#include<bits/stdc++.h>
using namespace std;

int find_fa(int x,vector<int>& fa)
{
    return fa[x]==x?x:fa[x]=find_fa(fa[x],fa);
}

int main()
{
    int a,b,p;
    cin>>a>>b>>p;
    vector<int> fa(b+1);
    for(int i=a;i<=b;i++)
    {
        fa[i]=i;
    }
    vector<bool> flag(b+1,0);
    int ans=b-a+1;
    for(long long i=2;i<=b;i++)
    {
        if(!flag[i])
        {
            if(i>=p)
            {
                for(long long j=2*i;j<=b;j+=i)
                {
                    flag[j]=true;
                    if(j-i>=a&&find_fa(j,fa)!=find_fa(j-i,fa))
                    {
                        fa[find_fa(j,fa)]=find_fa(j-i,fa);
                        --ans;
                    }
                }
            }
            else
            {
                for(long long j=i*i;j<=b;j+=i)
                {
                    flag[j]=true;
                }
            }
        }
    }
    cout<<ans<<endl;
}