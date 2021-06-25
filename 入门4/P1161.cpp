#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    double a;
    int t;
    vector<int> v(2000020,0);
    int ans;
    for(int i=0;i<n;i++)
    {
        cin>>a>>t;
        for(int i=1;i<=t;i++)
            v[(int)floor(a*i)]^=1;
    }
    for(int i=1;i<=2000000;i++)
        if(v[i])
        {
            cout<<i<<endl;
            break;
        }
}