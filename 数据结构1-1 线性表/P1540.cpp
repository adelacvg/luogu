#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    vector<int> v(m,-1);
    int now=0;
    map<int,int> ma;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(!ma[x])
        {
            ma[x]=1;
            now=(now+1)%m;
            if(v[now]!=-1)
                ma[v[now]]=0;
            v[now]=x;
            ans++;
        }
    }
    cout<<ans<<endl;
}