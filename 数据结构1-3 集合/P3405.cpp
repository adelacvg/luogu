#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    map<pair<string,string>,int> m;
    int ans=0;
    while(n--)
    {
        string city,state;
        cin>>city>>state;
        city=city.substr(0,2);
        if(city!=state)
        ans+=m[make_pair(state,city)];
        m[make_pair(city,state)]++;
    }
    cout<<ans<<endl;
}