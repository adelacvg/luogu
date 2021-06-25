#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int t;
    string s;
    int token=0;
    int sum=0;
    while(1)
    {
        cin>>t;
        s+=string(t,char(token+'0'));
        token^=1;
        sum+=t;
        if(sum==n*n)
            break;
    }
    for(int i=0;i<n;i++)
    {
        cout<<s.substr(i*n,n)<<endl;
    }
}