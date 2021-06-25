#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    vector<int> s(m),v(n);
    for(int i=0;i<m;i++)
    {
        cin>>s[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(begin(s),end(s));
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int l=0,r=m-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(s[mid]<v[i])
                l=mid+1;
            else if(s[mid]>v[i])
                r=mid-1;
            else
            {
                l=mid;
                break;
            }
        }
        if(r==-1)
            ans+=abs(v[i]-s[l]);
        else if(l==m)
            ans+=abs(v[i]-s[r]);
        else
            ans+=min(abs(v[i]-s[l]),abs(v[i]-s[r]));
    }
    cout<<ans<<endl;
}