#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    int l=1,r=0;
    unordered_map<int,int> ma;
    while(ma.size()<m)
    {
        r++;
        ma[v[r]]++;
    }
    int ansl=l,ansr=r,ans=r-l+1;
    while(r<=n&&l<=n)
    {
        while(ma[v[l]]>1)
        {
            ma[v[l]]--;
            l++;
        }
        if(r-l+1<ans)
        {
            ans=r-l+1;
            ansl=l;
            ansr=r;
        }
        r++;
        ma[v[r]]++;
    }
    cout<<ansl<<" "<<ansr<<endl;
}