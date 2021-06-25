#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    cout<<fixed<<setprecision(1)<<k*(1+n/k)*1.0/2<<" "<<
    (n*(n+1)/2-k*(n/k)*(1+n/k)*1.0/2)/(n-n/k);
}