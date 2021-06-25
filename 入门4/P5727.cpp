#include<bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long n;
    cin>>n;
    vector<int> v;
    while(n>1)
    {
        v.emplace_back(n);
        if(n&1)
            n=n*3+1;
        else
            n/=2;
    }
    v.emplace_back(1);
    for(auto i=v.rbegin();i!=v.rend();i++)
        cout<<*i<<" ";
}