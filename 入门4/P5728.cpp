#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<tuple<int, int, int>> v(n+1);
    for(int i=1;i<=n;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        v[i]={x,y,z};
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            auto [x1,y1,z1] = v[i];
            auto [x2,y2,z2] = v[j];
            if(abs(x1-x2)<=5&&
            abs(y1-y2)<=5&&
            abs(z1-z2)<=5&&
            abs(x1+y1+z1-x2-y2-z2)<=10)
                ans++;
        }
    }
    cout<<ans<<endl;
}