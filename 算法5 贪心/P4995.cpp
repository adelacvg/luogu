#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    vector<long long> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(begin(v),end(v));
    int i=0,j=n-1;
    int id=j;
    long long ans=0,now=0;
    while(i<=j)
    {
        if(id==j)
        {
            ans+=(v[j]-now)*(v[j]-now);
            now=v[j];
            j--;
            id=i;
        }
        else
        {
            ans+=(v[i]-now)*(v[i]-now);
            now=v[i];
            i++;
            id=j;
        }
    }
    cout<<ans<<endl;
}