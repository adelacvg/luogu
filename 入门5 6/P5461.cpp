#include<bits/stdc++.h>
using namespace std;
void judge(vector<vector<int>> &v,int n,int x,int y)
{
    if(n==1)
    {
        v[x][y]=0;
        return;
    }
    for(int i=x;i<x+(1<<(n-1));i++)
    {
        for(int j=y;j<y+(1<<(n-1));j++)
        {
            v[i][j]=0;
        }
    }
    judge(v,n-1,x+(1<<(n-1)),y);
    judge(v,n-1,x,y+(1<<(n-1)));
    judge(v,n-1,x+(1<<(n-1)),y+(1<<(n-1)));
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> v((1<<n)+10,vector<int>((1<<n)+10,1));
    judge(v,n,1,1);
    for(int i=1;i<=(1<<n);i++)
    {
        for(int j=1;j<=(1<<n);j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}