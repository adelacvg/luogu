#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        unsigned long long n;
        cin>>n;
        if(n==4||n==10)
            cout<<n+1<<'\n';
        else
            cout<<n-1<<'\n';
    }
}