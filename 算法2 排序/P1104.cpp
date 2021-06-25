#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<tuple<string,int,int,int,int>> v;
    string s;
    int y,m,d,id;
    for(int i=0;i<n;i++)
    {
        cin>>s>>y>>m>>d;
        v.emplace_back(make_tuple(s,y,m,d,i));
    }
    sort(begin(v),end(v),[](auto &i,auto &j){
        auto &[s1,y1,m1,d1,id1]=i;
        auto &[s2,y2,m2,d2,id2]=j;
        if(y1==y2&&m1==m2&&d1==d2)
            return id1>id2;
        else
        {
            if(y1==y2&&m1==m2)
                return d1<d2;
            else
            {
                if(y1==y2)
                    return m1<m2;
                else
                    return y1<y2;
            }
        }
    });
    for(auto &[s,y,m,d,id]:v)
    {
        cout<<s<<endl;
    }
}