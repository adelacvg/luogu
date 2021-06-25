#include<bits/stdc++.h>
using namespace std;
int find_fa(int x,vector<int>& fa)
{
    return fa[x]=(fa[x]==x?x:find_fa(fa[x],fa));
}

int main()
{
    int n,m;
    while(cin>>n)
    {
        if(n==0) break;
        cin>>m;
        vector<int> fa(n+1);
        for(int i=1;i<=n;i++)
            fa[i]=i;
        while(m--)
        {
            int x,y;
            cin>>x>>y;
            fa[find_fa(x,fa)]=find_fa(y,fa);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(find_fa(i,fa)==i)
            {
                ans++;
            }
        }
        cout<<ans-1<<endl;
    }
}