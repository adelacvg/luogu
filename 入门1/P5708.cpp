#include<bits/stdc++.h>
using namespace std;

int main()
{
    double a,b,c;
    cin>>a>>b>>c;
    double p=(a+b+c)/2;
    auto ans=sqrt(p*(p-a)*(p-b)*(p-c));
    ans = round(ans*10)/10.0;
    cout<<setprecision(1)<<fixed<<ans<<endl;
}