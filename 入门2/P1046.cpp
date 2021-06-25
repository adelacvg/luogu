#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    vector<int> v;
    for(int i=0;i<10;i++)
    {
        cin>>t;
        v.emplace_back(t);
    }
    int height;
    cin>>height;
    int ans = count_if(v.begin(),v.end(),[=](auto i){return i<=height+30;});
    cout<<ans<<endl;
}