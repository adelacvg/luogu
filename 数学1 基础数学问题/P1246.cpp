#include<bits/stdc++.h>
using namespace std;

int nCm(int n,int m)
{
    int ans=1;
    for(int i=n,j=1;j<=m;j++,i--)
    {
        ans=ans*i/j;
    }
    return ans;
}

int main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i]>=s[i+1])
        {
            cout<<0<<endl;
            return 0;
        }
    }
    int ans=0;
    for(int i=1;i<s.size();i++)
    {
        ans+=nCm(26,i);
    }
    for(int i=0;i<s.size();i++)
    {
        for(int j=(i==0?'a':s[i-1]+1);j<s[i];j++)
        {
            ans+=nCm('z'-j,s.size()-i-1);
        }
    }
    cout<<ans+1<<endl;
}