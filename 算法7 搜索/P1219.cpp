#include<bits/stdc++.h>
using namespace std;
bitset<20> row(0);
bitset<20> col(0);
bitset<100> bm(0);
vector<int> flag(30);
int cnt=0;
int judge(int n,int x,int dep)
{
    int flag1=1;
    if(row[dep]||col[x])
        flag1=0;
    if(bm[dep+x+40]||bm[dep-x+20])
        flag1=0;
    return flag1;
}
void dfs(int dep,int n)
{
    if(dep==n+1)
    {
        cnt++;
        if(cnt<=3)
        {
            for(int i=1;i<=n;i++)
                cout<<flag[i]<<" ";
            cout<<endl;
        }
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(judge(n,i,dep))
        {
            if(cnt<=3)
                flag[dep]=i;
            bm.flip(dep+i+40);
            bm.flip(dep-i+20);
            row.flip(dep);
            col.flip(i);
            dfs(dep+1,n);
            bm.flip(dep+i+40);
            bm.flip(dep-i+20);
            row.flip(dep);
            col.flip(i);
            if(cnt<=3)
                flag[dep]=0;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    dfs(1,n);
    cout<<cnt<<endl;
}