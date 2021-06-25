#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,b;
    cin>>n>>b;
    vector<pair<int,int>> v(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>v[i].second>>v[i].first;
    }
    sort(begin(v),end(v));
    int l=0,r=0;
    for(int i=2;i<=n;i++)
    {
        auto &[p,s]=v[i-1];
        auto &[pn,sn]=v[i];
        if(b>p&&b<pn)
        {
            l=i-1;
            r=i;
            break;
        }
    }
    if(l==0&&r==0)
    {
        cout<<-1<<endl;
    }
    else
    {
        int tl=l,tr=r;
        int ans=INT_MAX;
        while(l>=1)
        {
            while(r<=n&&v[r].second<v[r].first-v[l].first)
            {
                r++;
            }
            if(r>n)
            {
                break;
            }
            ans=min(ans,max(v[r].first-v[l].first-v[l].second,0));
            if(ans==0)
            {
                cout<<ans<<endl;
                return 0;
            }
            l--;
        }
        l=tl,r=tr;
        while(r<=n)
        {
            while(l>=1&&v[l].second<v[r].first-v[l].first)
            {
                l--;
            }
            if(l<1)
            {
                break;
            }
            ans=min(ans,max(v[r].first-v[l].first-v[r].second,0));
            if(ans==0)
            {
                cout<<ans<<endl;
                return 0;
            }
            r++;
        }
        if(ans==INT_MAX)
        {
            cout<<-1<<endl;
        }
        else
            cout<<ans<<endl;
    }
}