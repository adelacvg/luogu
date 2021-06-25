#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    stringstream ss(s);
    long long sum=0,a,cnt=0;
    while(ss>>a)
    {
        sum+=a;
        cnt++;
    }
    cout<<sum*(1<<(cnt-1))<<endl;
}