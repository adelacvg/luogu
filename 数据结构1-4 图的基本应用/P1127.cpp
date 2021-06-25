#include<bits/stdc++.h>
using namespace std;
vector<string> s;
void dfs(int x,vector<vector<int>>& e_out,
vector<bool>& flag,int remain,string sa)
{
    if(remain==1)
    {
        cout<<sa.substr(1);
        cout<<'.'<<s[x]<<endl;
        exit(0);
    }
    for(auto i:e_out[x])
    {
        if(!flag[i])
        {
            flag[x]=1;
            dfs(i,e_out,flag,remain-1,sa+'.'+s[x]);
            flag[x]=0;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    string ss;
    map<char,int> st,ed;
    for(int i=0;i<n;i++)
    {
        cin>>ss;
        st[ss[0]]++;
        ed[ss.back()]++;
        s.emplace_back(ss);
    }
    sort(begin(s),end(s));
    vector<vector<int>> e_out(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j&&s[i].back()==s[j][0])
            {
                e_out[i].emplace_back(j);
            }
        }
    }
    int fst=0;
    for(int i=0;i<n;i++)
    {
        if(st[s[i][0]]==ed[s[i][0]]+1)
        {
            fst=i;
            break;
        }
    }
    vector<bool> flag(n,0);
    flag[fst]=1;
    dfs(fst,e_out,flag,n,"");
    cout<<"***"<<endl;
}