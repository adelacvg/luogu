#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string s;
    int a,b;
    for(int i=0;i<n;i++)
    {
        cin>>s>>a>>b;
        cout<<s<<" "<<a+1<<" "<<min(600.0,b*1.2)<<endl;
    }
}