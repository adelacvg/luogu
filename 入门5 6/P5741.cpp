#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<tuple<string,int,int,int>> t;
    vector<pair<string,string>> ans;
    string s;
    int a,b,c;
    for(int i=0;i<n;i++)
    {
        cin>>s>>a>>b>>c;
        t.emplace_back(make_tuple(s,a,b,c));
    }
    for(int i=0;i<t.size();i++)
    {
        for(int j=i+1;j<t.size();j++)
        {
            auto [s1,a1,b1,c1] = t[i];
            auto [s2,a2,b2,c2] = t[j];
            if(abs(a1-a2)<=5&&abs(b1-b2)<=5&&
            abs(c1-c2)<=5&&
            abs(a1+b1+c1-a2-b2-c2)<=10)
            {
                if(s1>s2)
                    swap(s1,s2);
                ans.emplace_back(make_pair(s1,s2));
            }
        }
    }
    sort(ans.begin(),ans.end(),[](auto x,auto y){
        if(x.first<y.first) return 1;
        else if(x.first==y.first&&x.second<y.second)
            return 1;
        return 0;
    });
    for(auto [s1,s2]:ans)
    {
        cout<<s1<<" "<<s2<<endl;
    }
}