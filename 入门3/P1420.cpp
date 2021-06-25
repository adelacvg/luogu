#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    copy_n(istream_iterator<int>(std::cin),
    n,
    back_inserter(v));
    adjacent_difference(v.begin(),v.end(),v.begin());
    v[0]=v[1]+1;
    int ans=1;
    int cnt=1;
    for(int i=1;i<v.size();i++)
    {
        if(v[i]==1)
        {
            cnt++;
            ans=max(ans,cnt);
        }
        else
        {
            cnt=1;
        }
    }
    cout<<ans<<endl;
}