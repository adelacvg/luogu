#include<bits/stdc++.h>
using namespace std;

int main()
{
    // ifstream cin("P2678_2.in");
    // ofstream cout("out.out");
    int s,n,m;
    cin>>s>>n>>m;
    vector<int> v(n+2);
    v[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    v[n+1]=s;
    int l=1,r=s;
    while(l<=r)
    {
        int mid=l+(r-l)/2;
        int t=0,now=0;
        for(int i=1;i<=n+1;i++)
        {
            if(v[i]-v[now]<mid)
                t++;
            else
                now=i;
        }
        if(t<m)
        {
            l=mid+1;
        }
        else if(t>m)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<r<<endl;
}