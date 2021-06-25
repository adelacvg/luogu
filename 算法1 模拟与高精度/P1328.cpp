#include<bits/stdc++.h>
using namespace std;
int m[5][5]{{0,0,1,1,0},
            {1,0,0,1,0},
            {0,1,0,0,1},
            {0,0,1,0,1},
            {1,1,0,0,0}};
int judge(int a,int b)
{
    if(a==b)
        return -1;
    if(m[a][b]) return 1;
    else return 0;
}
int main()
{
    int n,na,nb;
    cin>>n>>na>>nb;
    vector<int> a,b;
    int t;
    for(int i=0;i<na;i++)
    {
        cin>>t;
        a.emplace_back(t);
    }
    for(int i=0;i<nb;i++)
    {
        cin>>t;
        b.emplace_back(t);
    }
    int cnta=0,cntb=0;
    for(int i=0;i<n;i++)
    {
        if(judge(a[i%na],b[i%nb])==1)
            cnta++;
        else if(judge(a[i%na],b[i%nb])==0)
            cntb++;
    }
    cout<<cnta<<" "<<cntb<<endl;
}