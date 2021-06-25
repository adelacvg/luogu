#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    string s;
    cin>>s>>n;
    long long len=s.size();
    long long ss=len;
    while(len<n)
        len<<=1;
    while(len!=ss)
    {
        len>>=1;
        if(n>len)
            n=(n-len-1-1+len)%len+1;
    }
    cout<<s[n-1];
}