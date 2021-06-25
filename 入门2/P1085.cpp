#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    int val=0;
    int ans=0;
    for(int i=1;i<=7;i++)
    {
        cin>>a>>b;
        if(a+b-8>val)
        {
            val=a+b-8;
            ans=i;
        }
    }
    cout<<ans<<endl;
}