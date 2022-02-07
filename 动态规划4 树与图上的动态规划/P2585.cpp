#include<bits/stdc++.h>
using namespace std;
const constexpr int maxn=5e5+10;
int dp_min[maxn][3];
int dp_max[maxn][3];
string s;
int cnt=1;

void dfs(int x)
{
    if(s[x]=='0')
    {
        dp_max[x][0]=1;
        dp_min[x][0]=1;
        return;
    }
    dfs(++cnt);
    if(s[x]=='1')
    {
        dp_max[x][0]=max(dp_max[x+1][1],dp_max[x+1][2])+1;
        dp_max[x][1]=max(dp_max[x+1][0],dp_max[x+1][2]);
        dp_max[x][2]=max(dp_max[x+1][0],dp_max[x+1][1]);
        dp_min[x][0]=min(dp_min[x+1][1],dp_min[x+1][2])+1;
        dp_min[x][1]=min(dp_min[x+1][0],dp_min[x+1][2]);
        dp_min[x][2]=min(dp_min[x+1][0],dp_min[x+1][1]);
    }
    else
    {
        int t=cnt+1;
        dfs(++cnt);
        dp_max[x][0]=max(dp_max[x+1][1]+dp_max[t][2],dp_max[x+1][2]+dp_max[t][1])+1;
        dp_max[x][1]=max(dp_max[x+1][0]+dp_max[t][2],dp_max[x+1][2]+dp_max[t][0]);
        dp_max[x][2]=max(dp_max[x+1][0]+dp_max[t][1],dp_max[x+1][1]+dp_max[t][0]);
        dp_min[x][0]=min(dp_min[x+1][1]+dp_min[t][2],dp_min[x+1][2]+dp_min[t][1])+1;
        dp_min[x][1]=min(dp_min[x+1][0]+dp_min[t][2],dp_min[x+1][2]+dp_min[t][0]);
        dp_min[x][2]=min(dp_min[x+1][0]+dp_min[t][1],dp_min[x+1][1]+dp_min[t][0]);
    }
}

int main()
{
    cin>>s;
    s = " "+s;
    dfs(1);
    cout<<dp_max[1][0]<<" "<<min({dp_min[1][0],dp_min[1][1],dp_min[1][2]})<<endl;
}