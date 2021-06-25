#include<bits/stdc++.h>
using namespace std;
int judge(int x,int y,int id,vector<vector<int>> &v)
{
    for(int i=x;i<=y;i++)
    {
        if(v[id][i])
            return 0;
    }
    return 1;
}
int main()
{
    int m,n;
    cin>>m>>n;
    vector<int> v;
    copy_n(istream_iterator<int>(std::cin),
    m*n,
    back_inserter(v));
    vector<vector<int>> machine_id;
    vector<int> t;
    machine_id.push_back({});
    for(int i=1;i<=n;i++)
    {
        t.clear();
        copy_n(istream_iterator<int>(std::cin),
        m,
        back_inserter(t));
        machine_id.push_back(t);
    }

    vector<vector<int>> time;
    time.push_back({});
    for(int i=1;i<=n;i++)
    {
        t.clear();
        copy_n(istream_iterator<int>(std::cin),
        m,
        back_inserter(t));
        time.push_back(t);
    }
    vector<vector<int>> timeline(m+2,vector<int>(200000,0));
    vector<int> index(n+1,0),last(n+1,0);
    int now,cost;
    for(auto i:v)
    {
        now=last[i]+1;
        cost=time[i][index[i]];
        while(1)
        {
            if(judge(now,now+cost-1,machine_id[i][index[i]],timeline))
            {
                for(int j=now;j<=now+cost-1;j++)
                    timeline[machine_id[i][index[i]]][j]=1;
                last[i]=now+cost-1;
                index[i]++;
                break;
            }
            now++;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,last[i]);
    cout<<ans<<endl;
}