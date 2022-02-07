#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
    int x;
    while(cin>>x)
    {
        v.emplace_back(x);
    }
    int n=v.size();
    vector<int> v_up;
    vector<int> v_down_or_equal;
    v_up.emplace_back(v[0]);
    v_down_or_equal.emplace_back(v[0]);
    for(int i=1;i<n;i++)
    {
        if(v[i]>v_up.back())
            v_up.emplace_back(v[i]);
        else
        {
            *lower_bound(begin(v_up),end(v_up),v[i])=v[i];
        }
        if(v[i]<=v_down_or_equal.back())
            v_down_or_equal.emplace_back(v[i]);
        else
        {
            *upper_bound(begin(v_down_or_equal),end(v_down_or_equal),v[i],greater<int>())=v[i];
        }
    }
    cout<<v_down_or_equal.size()<<'\n'<<v_up.size()<<endl;
}