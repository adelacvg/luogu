#include<bits/stdc++.h>
using namespace std;
double judge(int &m,vector<int> &v)
{
    sort(begin(v),end(v));
    v.erase(v.begin());
    v.erase(v.end()-1);
    double ans=0;
    for(auto &i:v)
    {
        ans+=i;
    }
    ans=ans/(m-2);
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> v;
    double ans=-100;
    for(int i=0;i<n;i++)
    {
        v.clear();
        copy_n(istream_iterator<int>(cin),m,
        back_insert_iterator(v));
        ans=max(ans,judge(m,v));
    }
    cout<<fixed<<setprecision(2)<<ans<<endl;
}