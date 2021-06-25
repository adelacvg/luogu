#include<bits/stdc++.h>
using namespace std;
array<array<char, 20>, 20> 
rotate(array<array<char, 20>, 20> m,int n)
{
    auto mt=m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            mt[j][n+1-i]=m[i][j];
        }
    }
    return mt;
}
void reflect(array<array<char,20>,20>& m,int n)
{
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         cout<<m[i][j];
    //     }
    //     cout<<endl;
    // }
    for(int i=1;i<=n;i++)
    {
        reverse(m[i].begin()+1,m[i].begin()+n+1);
    }
}
int judge(array<array<char,20>,20> a,
array<array<char,20>,20> b, int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]!=b[i][j])
            return 0;
        }
    }
    return 1;
}
int bfs(array<array<char,20>,20> m1,
        array<array<char,20>,20> m2,int n) 
{
    int ans=100;
    auto m=m1;
    if(judge(m,m2,n)) ans=min(ans,6);
    m=rotate(m,n);
    if(judge(m,m2,n)) ans=min(ans,1);
    m=rotate(m,n);
    if(judge(m,m2,n)) ans=min(ans,2);
    m=rotate(m,n);
    if(judge(m,m2,n)) ans=min(ans,3);
    m=m1;
    reflect(m,n);
    if(judge(m,m2,n)) ans=min(ans,4);
    m=rotate(m,n);
    if(judge(m,m2,n)) ans=min(ans,5);
    m=rotate(m,n);
    if(judge(m,m2,n)) ans=min(ans,5);
    m=rotate(m,n);
    if(judge(m,m2,n)) ans=min(ans,5);
    if(ans>6) ans=7;

    return ans;
}
int main()
{
    int n;
    cin>>n;
    array<array<char,20>,20> m1,m2;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>m1[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>m2[i][j];
    cout<<bfs(m1,m2,n)<<endl;
}