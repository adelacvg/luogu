#include<bits/stdc++.h>
using namespace std;
set<int> row[45],col[45];
map<int,pair<int,int>> mp;
int main()
{
    int m[45][45]{0};
    int n;
    cin>>n;
    m[1][n/2+1]=1;
    row[1].insert(1);
    col[n/2+1].insert(1);
    int t=2;
    mp[1]={1,n/2+1};
    while(t<=n*n)
    {
        if(row[1].count(t-1)&&(!col[n].count(t-1)))
        {
            m[n][mp[t-1].second+1]=t;
            mp[t]={n,mp[t-1].second+1};
            row[mp[t].first].insert(t);
            col[mp[t].second].insert(t);
        }
        if(col[n].count(t-1)&&(!row[1].count(t-1)))
        {
            m[mp[t-1].first-1][1]=t;
            mp[t]={mp[t-1].first-1,1};
            row[mp[t].first].insert(t);
            col[mp[t].second].insert(t);
        }
        if(row[1].count(t-1)&&col[n].count(t-1))
        {
            m[2][n]=t;
            mp[t]={2,n};
            row[mp[t].first].insert(t);
            col[mp[t].second].insert(t);
        }
        if((!row[1].count(t-1))&&(!col[n].count(t-1)))
        {
            if(m[mp[t-1].first-1][mp[t-1].second+1]==0)
            {
                m[mp[t-1].first-1][mp[t-1].second+1]=t;
                mp[t]={mp[t-1].first-1,mp[t-1].second+1};
            }
            else
            {
                m[mp[t-1].first+1][mp[t-1].second]=t;
                mp[t]={mp[t-1].first+1,mp[t-1].second};
            }
            row[mp[t].first].insert(t);
            col[mp[t].second].insert(t);
        }
        t++;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
}