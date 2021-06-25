#include<bits/stdc++.h>
using namespace std;

map<int,int> m{{0,6},{1,2},{2,5},{3,5},{4,4},
{5,5},{6,6},{7,3},{8,7},{9,6}};
int cnt(int x)
{
    int ans=0;
    if(x==0)
        return m[0];
    while(x)
    {
        ans+=m[x%10];
        x/=10;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int ans=0;
    vector<int> v(2020);
    for(int i=0;i<=2010;i++)
    {
        v[i]=cnt(i);
    }
    for(int i=0;i<=1000;i++)
    {
        for(int j=0;j<=1000;j++)
        {
            if(v[i]+v[j]+v[i+j]+4==n)
                ans++;
        }
    }
    cout<<ans<<endl;
}