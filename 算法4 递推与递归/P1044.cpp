#include<bits/stdc++.h>
using namespace std;

long long nCr(long long n,long long r)
{
    if(r>n)return 0;
    if(r*2>n)r=n-r;
    if(r==0)return 1;
    long long res=n;
    for(int i=2;i<=r;i++)
    {
        res=res*(n-i+1);
        res/=i;
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    cout<<nCr(2*n,n)-nCr(2*n,n-1);
}