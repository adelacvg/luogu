#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        if(n==1)
        {
            cout<<"Yes"<<'\n';
            continue;
        }
        int t=v[1];
        int flag=0;
        for(int i=0;i<n;i++)
        {
            if(i!=1)
            {
                t/=gcd(t,v[i]);
                if(t==1)
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag)
            cout<<"Yes"<<'\n';
        else
            cout<<"No"<<'\n';
    }
}