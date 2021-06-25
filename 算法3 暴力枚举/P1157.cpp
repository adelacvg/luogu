#include<bits/stdc++.h>
using namespace std;
int n,r;
stringstream ss;
vector<int> v;
vector<bool> flag(100,0);
void dfs(int dep,int index)
{
    if(dep==r)
    {
        for(auto i:v)
            ss<<setw(3)<<i;
        ss<<endl;
    }
    for(int i=index;i<=n;i++)
    {
        if(!flag[i])
        {
            flag[i]=1;
            v.push_back(i);
            dfs(dep+1,i);
            v.pop_back();
            flag[i]=0;
        }
    }
}
int main()
{
    cin>>n>>r;
    dfs(0,1);
    cout<<ss.str();
}