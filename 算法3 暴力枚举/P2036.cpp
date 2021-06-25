#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> s(20),b(20);
int ans=2e9;
void dfs(int dep,int sum,int product,int index)
{
    if(dep==n)
    {
        if(product==1&&sum==0)
            return;
        ans=min(ans,abs(sum-product));
        return;
    }
    dfs(dep+1,sum+b[index],product*s[index],index+1);
    dfs(dep+1,sum,product,index+1);
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s[i]>>b[i];
        ans=min(ans,abs(s[i]-b[i]));
    }
    dfs(0,0,1,0);
    cout<<ans<<endl;
}