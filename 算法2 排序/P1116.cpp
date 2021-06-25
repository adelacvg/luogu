#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
vector<int> a(maxn);
int lowbit(int n)
{
    return n&(-n);
}
int sum(int i)
{
    int ans=0;
    while(i)
    {
        ans+=a[i];
        i-=lowbit(i);
    }
    return ans;
}
void update(int i,int j)
{
    while(i<maxn)
    {
        a[i]+=j;
        i+=lowbit(i);
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int ans=0;
    for(int i=n-1;i>=0;i--)
    {
        ans+=sum(v[i]);
        update(v[i],1);
    }
    cout<<ans<<endl;
}