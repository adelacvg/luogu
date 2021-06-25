#include<bits/stdc++.h>
using namespace std;
int a,b,c;
vector<int> v(3);
vector<bool> flag(10);
stringstream ss;
void dfs(int dep)
{
    if(dep==9)
    {
        if(v[0]*1.0/v[1]==a*1.0/b&&
        v[0]*1.0/v[2]==a*1.0/c)
        {
            ss<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
        }
        return;
    }
    for(int i=1;i<=9;i++)
    {
        if(!flag[i])
        {
            v[(dep/3)%3]=v[(dep/3)%3]*10+i;
            flag[i]=true;
            dfs(dep+1);
            v[(dep/3)%3]/=10;
            flag[i]=false;
        }
    }
}

int main()
{
    cin>>a>>b>>c;
    dfs(0);
    if(ss.rdbuf()->in_avail())
        cout<<ss.str();
    else
        cout<<"No!!!";
}