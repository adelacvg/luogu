#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> ans(n+1);
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        int t,ti;
        cin>>t;
        cin>>ti;
        int pre=0;
        while(cin>>t)
        {
            if(t==0)
                break;
            pre=max(pre,ans[t]);
        }
        ans[i]=pre+ti;
        mx=max(mx,ans[i]);
    }
    cout<<mx<<endl;
}