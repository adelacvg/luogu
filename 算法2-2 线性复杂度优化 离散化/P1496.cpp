#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    map<int,int> v;
    int l,r;
    for(int i=1;i<=n;i++)
    {
        cin>>l>>r;
        v[l]++;
        v[r]--;
    }
    int pre=0;
    l=INT_MIN;
    int ans=0;
    for(auto &[p,s]:v)
    {
        s+=pre;
        if(l!=INT_MIN&&s<=0)
        {
            ans+=p-l;
            l=INT_MIN;
        }
        if(s>0&&l==INT_MIN)
        {
            l=p;
        }
        pre=s;
    }
    cout<<ans<<endl;
}