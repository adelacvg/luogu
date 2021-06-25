#include<bits/stdc++.h>
using namespace std;
stringstream ss;
void dfs(int x,int y,int x1,int y1,int size)
{
    if(size==1)
        return;
    size>>=1;
    if(x<x1+size&&y<y1+size)
    {
        ss<<x1+size<<" "<<
        y1+size<<" "<<1<<'\n';
        dfs(x,y,x1,y1,size);
        dfs(x1+size-1,y1+size,x1,y1+size,size);
        dfs(x1+size,y1+size-1,x1+size,y1,size);
        dfs(x1+size,y1+size,x1+size,y1+size,size);
    }
    else if(x<x1+size&&y>=y1+size)
    {
        ss<<x1+size<<" "<<
        y1+size-1<<" "<<2<<'\n';
        dfs(x1+size-1,y1+size-1,x1,y1,size);
        dfs(x,y,x1,y1+size,size);
        dfs(x1+size,y1+size-1,x1+size,y1,size);
        dfs(x1+size,y1+size,x1+size,y1+size,size);
    }
    else if(x>=x1+size&&y<y1+size)
    {
        ss<<x1+size-1<<" "<<
        y1+size<<" "<<3<<'\n';
        dfs(x1+size-1,y1+size-1,x1,y1,size);
        dfs(x1+size-1,y1+size,x1,y1+size,size);
        dfs(x,y,x1+size,y1,size);
        dfs(x1+size,y1+size,x1+size,y1+size,size);
    }
    else
    {
        ss<<x1+size-1<<" "<<
        y1+size-1<<" "<<4<<'\n';
        dfs(x1+size-1,y1+size-1,x1,y1,size);
        dfs(x1+size-1,y1+size,x1,y1+size,size);
        dfs(x1+size,y1+size-1,x1+size,y1,size);
        dfs(x,y,x1+size,y1+size,size);
    }
}
int main()
{
    int k;
    int x,y;
    cin>>k;
    cin>>x>>y;
    dfs(x,y,1,1,1<<k);
    cout<<ss.str();
}