#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    auto s=to_string(n);
    reverse(begin(s),end(s));
    if(n<0)cout<<'-';
    cout<<stoi(s)<<endl;
}