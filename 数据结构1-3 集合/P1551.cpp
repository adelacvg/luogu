#include<bits/stdc++.h>
using namespace std;
int fa(int x,vector<int>& fav)
{
    return fav[x]=(fav[x]==x?x:fa(fav[x],fav));
}

int main()
{
    int n,m,p;
    cin>>n>>m>>p;
    vector<int> fav(n+1);
    for(int i=1;i<=n;i++)//1.initialization
        fav[i]=i;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        fav[fa(x,fav)]=fa(y,fav);//2.fa[findfa(x)]=findfa(y)
    }
    while(p--)
    {
        int x,y;
        cin>>x>>y;
        if(fa(x,fav)==fa(y,fav))//3.findfa(x)==findfa(y)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}