#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long k;
    cin>>k;
    long long m=(long long)floor((-1+sqrt(1+8*k*1.0))/2.0);
    long long ans=m*(m+1)*(2*m+1)/6+(k-m*(m+1)/2)*(m+1);
    cout<<ans<<endl;
}