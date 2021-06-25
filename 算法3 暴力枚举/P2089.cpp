#include<bits/stdc++.h>
using namespace std;
stringstream ss;
int n;
int ans=0;
vector<int> v(10);
inline void out(int x)
{
    if(x>9) out(x/10);
    putchar(x%10+'0');
}
void dfs(int dep,int sum)
{
    if(dep==10)
    {
        if(sum==n)
        {
            for(int i=0;i<10;i++)
                ss<<v[i]<<" ";
            ss<<endl;
            ans++;
        }
        return;
    }
    if(sum+(10-dep)>n||sum+3*(10-dep)<n) return;
    for(int i=1;i<=3;i++)
    {
        v[dep]=i;
        dfs(dep+1,sum+i);
    }
    return;
}

int main()
{
    cin>>n;
    if(n<10||n>30)
        cout<<0<<endl;
    else
    {
        dfs(0,0);
        cout<<ans<<endl;
        cout<<ss.str();
    }
}