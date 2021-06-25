#include<bits/stdc++.h>
using namespace std;

int main()
{
    int w;
    cin>>w;
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(begin(v),end(v));
    int i=0,j=n-1;
    int sum=0;
    int ans=0;
    while(i<=j)
    {
        sum=v[j];
        while(sum+v[i]<=w&&i<j)
        {
            sum+=v[i];
            i++;
        }
        j--;
        ans++;
    }
    cout<<ans<<endl;
}