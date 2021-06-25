#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++)
    {
        v[i].first=i+1;
        cin>>v[i].second;
    }
    sort(begin(v),end(v),[](auto x,auto y){
        return x.second<y.second;
    });
    double sum=0,time=0;
    int flag=0;
    for(auto[i,j]:v)
    {
        if(flag==0)
            flag=1;
        else
            sum+=time;
        time+=j;
        cout<<i<<" ";
    }
    cout<<'\n';
    cout<<fixed<<setprecision(2)<<sum*1.0/n<<'\n';
}