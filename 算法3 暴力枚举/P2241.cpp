#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,m;
    cin>>n>>m;
    long long cub=0;
    long long tm=m,tn=n;
    while(tn&&tm)
    {
        cub+=tn*tm;
        tn--;
        tm--;
    }
    cout<<cub<<" "<<n*(n+1)/2*m*(m+1)/2-cub<<endl;
}