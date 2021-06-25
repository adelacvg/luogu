#include<iostream>
#include <numeric>
#include<algorithm>
using namespace std;

int main()
{
    int a,b,c,x,y;
    cin>>a>>b>>c;
    x=min(min(a,b),c);
    y=max(max(a,b),c);
    auto xy_gcd=gcd(x,y);
    cout<<x/xy_gcd<<"/"<<y/xy_gcd<<endl;
}