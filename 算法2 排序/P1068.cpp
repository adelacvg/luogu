#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int k,s;
    vector<pair<int,int>> w;
    for(int i=0;i<n;i++)
    {
        cin>>k>>s;
        w.emplace_back(make_pair(k,s));
    }
    sort(begin(w),end(w),[](auto i,auto j){
        auto &[k1,s1]=i;
        auto &[k2,s2]=j;
        if(s1==s2)
            return k1<k2;
        return s1>s2;
    });
    int score=w[floor(m+m/2.0)-1].second;
    int ans=0;
    for(auto &[k,s]:w)
        if(s>=score)
            ans++;
    cout<<score<<" "<<ans<<endl;
    for(auto &[k,s]:w)
        if(s>=score)
            cout<<k<<" "<<s<<endl;
}