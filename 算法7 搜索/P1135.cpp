#include<bits/stdc++.h>
using namespace std;
vector<int> ans(300,-1);
int n,a,b;
void bfs(vector<int>& v,int a,int b)
{
    queue<int> q;
    q.push(a);
    ans[a]=0;
    while(!q.empty())
    {
        auto t=q.front();
        q.pop();
        auto t1=t+v[t],t2=t-v[t];
        if(t1>=1&&t1<=n&&ans[t1]==-1)
        {
            q.push(t1);
            ans[t1]=ans[t]+1;
        }
        if(t2>=1&&t2<=n&&ans[t2]==-1)
        {
            q.push(t2);
            ans[t2]=ans[t]+1;
        }
    }
}
int main()
{
    cin>>n>>a>>b;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++)
        cin>>v[i];
    bfs(v,a,b);
    cout<<ans[b]<<endl;
}