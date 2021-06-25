#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    map<int,int> m;
    vector<int> v;
    int t;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        v.push_back(t);
        m[t]++;
    }
    set<int> s;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(m[v[i]+v[j]])
                s.insert(v[i]+v[j]);
        }
    }
    cout<<s.size()<<endl;
}