#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    char c;
    vector<vector<int>> v(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>c;
            if(c=='*')
                v[i][j]=1;
        }
    }
    vector<int> h(m+1,0);
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(!v[i][j])
                h[j]++;
            else
                h[j]=0;
        }
        stack<int> s,s1;
        vector<int> l(m+1),r(m+1);
        for(int j=1;j<=m;j++)
        {
            while(!s.empty()&&h[s.top()]>h[j])
            {
                s.pop();
            }
            if(!s.empty())
            {
                l[j]=s.top();
            }
            else
                l[j]=0;
            s.push(j);
        }
        for(int j=m;j>=1;j--)
        {
            while(!s1.empty()&&h[s1.top()]>=h[j])
            {
                s1.pop();
            }
            if(!s1.empty())
                r[j]=s1.top();
            else
                r[j]=m+1;
            s1.push(j);
        }
        for(int j=1;j<=m;j++)
        {
            ans+=(j-l[j])*(r[j]-j)*h[j];
        }
    }
    cout<<ans<<endl;
}