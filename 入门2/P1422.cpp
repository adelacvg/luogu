#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    double ans=0;
    ans+=min(150,n)*0.4463;
    ans+=max(0,min(n-150,250))*0.4663;
    ans+=max(0,n-400)*0.5663;
    cout<<fixed<<setprecision(1)<<ans<<endl;
}