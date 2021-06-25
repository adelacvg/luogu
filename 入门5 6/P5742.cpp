#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<tuple<int,int,int,double>> v;
    int a,b,c;
    double d;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b>>c;
        v.push_back(make_tuple(a,b,c,b*0.7+c*0.3));
    }
    for(auto& [a,b,c,d]:v)
    {
        if(b+c>140&&d>=80)
            cout<<"Excellent"<<endl;
        else
            cout<<"Not excellent"<<endl;
    }
}