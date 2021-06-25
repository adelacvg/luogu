#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n+2);
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    sort(begin(v)+1,end(v)-1);
    v[0]=v[n+1]=INT_MAX;
    vector<int> pre(n+2),post(n+2);
    int l=1,r=1;
    while(l<=n&&r<=n)
    {
        pre[r]=max(pre[r-1],r-l+1);
        r++;
        while(v[r]-v[l]>k)
        {
            l++;
        }
    }
    l=n,r=n;
    while(l>=1&&r>=1)
    {
        post[l]=max(post[l+1],r-l+1);
        l--;
        while(v[r]-v[l]>k)
        {
            r--;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(pre[i-1]+post[i],ans);
    }
    cout<<ans<<endl;
}