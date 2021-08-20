#include<bits/stdc++.h>
using namespace std;
int st[100010][20];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> a;
    copy_n(istream_iterator<int>(cin),n,
    back_inserter(a));
    for(int i=0;i<n;i++)
    {
        st[i][0]=a[i];
    }
    int depth=0;
    while((1<<depth)<n)
        depth++;
    for(int j=1;j<=depth;j++)
    {
        for(int i=0;i+(1<<j)-1<n;i++)
        {
            st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
    int l,r;
    while(m--)
    {
        cin>>l>>r;
        --l,--r;
        int k=log2(r-l+1);
        cout<<max(st[l][k],st[r-(1<<k)+1][k])<<'\n';
    }
}