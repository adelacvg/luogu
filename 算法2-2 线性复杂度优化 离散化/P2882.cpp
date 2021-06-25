#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    char c;
    vector<bool> v(n+2);
    for(int i=1;i<=n;i++)
    {
        cin>>c;
        if(c=='B')
            v[i]=0;
        else
            v[i]=1;
    }
    int min_cnt=INT_MAX,k=INT_MAX;
    for(int i=1;i<=n;i++)
    {
        vector<int> flag(n+2,0);
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            flag[j]+=flag[j-1];
            if(v[j]^(flag[j]&1)==0&&j+i<=n+1)
            {
                cnt++;
                flag[j]++;
                flag[j+i]--;
            }
        }
        int ok=1;
        for(int j=n;j>=1&&j>=n-i;j--)
        {
            if(v[j]^(flag[j]&1)==0)
            {
                ok=0;
                break;
            }
        }
        if(ok)
        {
            if(cnt<min_cnt)
            {
                min_cnt=min(cnt,min_cnt);
                k=i;
            }
        }
    }
    cout<<k<<" "<<min_cnt<<endl;
}