#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int l=0,r=0;
    long long sm=0;
    while(r<=n&&l<=n)
    {
        sm+=r;
        while(sm>n)
        {
            sm-=l;
            l++;
        }
        if(sm==n&&r!=l)
        {
            cout<<l<<" "<<r<<'\n';
        }
        r++;
    }
}