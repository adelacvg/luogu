#include<bits/stdc++.h>
using namespace std;
int main()
{
    int64_t n,k;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    unordered_map<int,int> x,y;
    while(k--)
    {
        int r,c;
        cin>>r>>c;
        x[r]=1;
        y[c]=1;
    }
    cout<<(x.size()+y.size())*n-x.size()*y.size()<<endl;
}