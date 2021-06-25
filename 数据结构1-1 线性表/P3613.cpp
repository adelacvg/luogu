#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    map<pair<int,int>,int> m;
    for(int i=0;i<q;i++)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            int i,j,k;
            cin>>i>>j>>k;
            m[make_pair(i,j)]=k;
        }
        else if(x==2)
        {
            int i,j;
            cin>>i>>j;
            cout<<m[make_pair(i,j)]<<endl;
        }
    }
}