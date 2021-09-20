#include<bits/stdc++.h>
using namespace std;

using i64 =long long;
constexpr int maxn=5e5+10;
i64 seg[maxn<<2];
i64 n,M,T,mod,p;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n>>mod;
        for(M=1;M<n;M<<=1);
        for(int i=1;i<=M+n;i++)
            seg[i]=1;
        int pos;
        for(int i=0,op=0,k=0;i<n;i++)
        {
            cin>>op>>k;
            if(op==1)
            {
                seg[i+M]=k;
                pos=i+M;
            }
            else
            {
                seg[k-1+M]=1;
                pos=k-1+M;
            }
            while(pos>>=1)
                seg[pos]=seg[pos<<1]*seg[pos<<1|1]%mod;
            cout<<seg[1]<<'\n';
        }
    }
}