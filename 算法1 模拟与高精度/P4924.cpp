#include<bits/stdc++.h>
using namespace std;
int n,m;
void reversecolumn(vector<vector<int>> &v,int x,int y,
int x1,int y1)
{
    for(int i=y;i<=y1;i++)
    {
        for(int j=x,k=x1;j<k;j++,k--)
        {
            swap(v[j][i],v[k][i]);
        }
    }
}
void reverserow(vector<vector<int>> &v,int x,int y,
int x1,int y1)
{
    for(int i=x;i<=x1;i++)
    {
        for(int j=y,k=y1;j<k;j++,k--)
        {
            swap(v[i][j],v[i][k]);
        }
    }
}
void transpose(vector<vector<int>> &v,int x,int y,
int r)
{
    int basex=x-r,basey=y-r;
    for(int i=basex;i<=basex+2*r;i++)
    {
        for(int j=basey+i-basex;j<=basey+2*r;j++)
        {
            swap(v[i][j],
            v[basex-basey+j][basey-basex+i]);
        }
    }
}
void rot(vector<vector<int>> &v,int x,int y,int r,int z)
{
    transpose(v,x,y,r);
    if(z)
        reversecolumn(v,x-r,y-r,x+r,y+r);
    else
        reverserow(v,x-r,y-r,x+r,y+r);
}

int main()
{
    cin>>n>>m;
    vector<vector<int>> v(n+2,vector<int>(n+2));
    int cnt=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            v[i][j]=cnt++;
        }
    }
    int x,y,z,r;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y>>r>>z;
        if(r==0)
            continue;
        rot(v,x,y,r,z);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}