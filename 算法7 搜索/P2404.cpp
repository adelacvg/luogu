#include<bits/stdc++.h>
using namespace std;

void dfs(int n,vector<int>& ans)
{
    for(int i=ans.empty()?1:ans[ans.size()-1];i<=n;i++)
    {
        ans.push_back(i);
        dfs(n-i,ans);
        if(n-i==0&&ans.size()!=1)
        {
            for(int i=0;i<ans.size()-1;i++)
            {
                cout<<ans[i]<<"+";
            }
            cout<<ans[ans.size()-1]<<endl;
        }
        ans.pop_back();
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> ans;
    dfs(n,ans);
}