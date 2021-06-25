#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    int a,b,c;
    tuple<string,int,int,int> ans{"",0,0,0};
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>s>>a>>b>>c;
        if(a+b+c>sum)
        {
            sum=a+b+c;
            ans=make_tuple(s,a,b,c);
        }
    }
    auto [s1,a1,b1,c1]=ans;
    cout<<s1<<" "<<a1<<" "<<b1<<" "<<c1<<endl;
}