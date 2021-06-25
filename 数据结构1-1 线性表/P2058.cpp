#include<bits/stdc++.h>
using namespace std;

int main()
{
    int l=0,r=0;
    int n;
    cin>>n;
    map<int,int> m;
    vector<int> t(n);
    vector<vector<int>> v(n,vector<int>());
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>t[i]>>k;
        for(int j=0;j<k;j++)
        {
            int x;
            cin>>x;
            v[i].push_back(x);
            m[x]++;
        }
        while(t[r]-t[l]>=86400)
        {
            for(auto i:v[l])
            {
                m[i]--;
                if(m[i]==0)
                    m.erase(i);
            }
            l++;
        }
        cout<<m.size()<<endl;
        r++;
    }
}