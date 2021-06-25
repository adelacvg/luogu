#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string name,job;
    int point,level;
    vector<tuple<string,string,int,int,int>> v;
    for(int i=0;i<n;i++)
    {
        cin>>name>>job>>point>>level;
        v.emplace_back(make_tuple(name,job,point,level,i));
    }
    int index=0;
    while(index<v.size()&&(get<1>(v[index])=="BangZhu"||get<1>(v[index])=="FuBangZhu"))
        index++;
    sort(next(begin(v),index),end(v),[](auto x,auto y){
        auto &[n1,j1,p1,l1,id1]=x;
        auto &[n2,j2,p2,l2,id2]=y;
        if(p1==p2)
            return id1<id2;
        return p1>p2;
    });
    int hufa=2,zhanglao=4,tangzhu=7,jingying=25;
    map<string,int> m{{"HuFa",5},{"ZhangLao",4},
    {"TangZhu",3},{"JingYing",2},{"BangZhong",1}};
    while(hufa&&index<v.size())
    {
        get<1>(v[index])="HuFa";
        hufa--;
        index++;
    }
    while(zhanglao&&index<v.size())
    {
        get<1>(v[index])="ZhangLao";
        zhanglao--;
        index++;
    }
    while(tangzhu&&index<v.size())
    {
        get<1>(v[index])="TangZhu";
        tangzhu--;
        index++;
    }
    while(jingying&&index<v.size())
    {
        get<1>(v[index])="JingYing";
        jingying--;
        index++;
    }
    while(index<v.size())
    {
        get<1>(v[index])="BangZhong";
        index++;
    }
    index=0;
    while(index<v.size()&&(get<1>(v[index])=="BangZhu"||get<1>(v[index])=="FuBangZhu"))
        index++;
    sort(next(begin(v),index),end(v),[&](auto x,auto y){
        auto &[n1,j1,p1,l1,id1]=x;
        auto &[n2,j2,p2,l2,id2]=y;
        if(m[j1]==m[j2])
        {
            if(l1==l2)
                return id1<id2;
            return l1>l2;
        }
        return m[j1]>m[j2];
    });
    for(auto [n,j,p,l,id]:v)
        cout<<n<<" "<<j<<" "<<l<<endl;
}