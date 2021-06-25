#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    map<int,string> mp;
    vector<int> dir(n);
    for(int i=0;i<n;i++)
    {
        cin>>dir[i];
        cin>>mp[i];
    }
    int a,s,p=0;
    for(int i=0;i<m;i++)
    {
        cin>>a>>s;
        if(dir[p]^a==0)
            p=(p+n-s)%n;
        else
            p=(p+s)%n;
    }
    cout<<mp[p]<<endl;
}