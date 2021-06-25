#include<bits/stdc++.h>
using namespace std;
int x[4]{-1,0,1, 0};
int y[4]{ 0,1,0,-1};
int main()
{
    vector<string> m;
    string s;
    for(int i=0;i<10;i++)
    {
        getline(cin,s);
        m.emplace_back(s);
    }
    pair<int,int> F,C;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(m[i][j]=='F')
            {
                F=make_pair(i,j);
                m[i][j]='.';
            }
            else if(m[i][j]=='C')
            {
                C=make_pair(i,j);
                m[i][j]='.';
            }
        }
    }
    int ans=0;
    int dirf=0,dirc=0;
    int tx,ty;
    while(1)
    {
        if(ans>200000)
        {
            cout<<0<<endl;
            break;
        }
        if(F==C)
        {
            cout<<ans<<endl;
            break;
        }
        tx=F.first+x[dirf];
        ty=F.second+y[dirf];
        if(tx>=0&&tx<10&&ty>=0&&ty<10&&m[tx][ty]=='.')
            F=make_pair(tx,ty);
        else
            dirf=(dirf+1)%4;
        tx=C.first+x[dirc];
        ty=C.second+y[dirc];
        if(tx>=0&&tx<10&&ty>=0&&ty<10&&m[tx][ty]=='.')
            C=make_pair(tx,ty);
        else
            dirc=(dirc+1)%4;
        ans++;
    }
}