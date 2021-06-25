#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<char,int> m;
    string s;
    while(getline(cin,s))
    {
        for(auto i:s)
            m[i]++;
    }
    int h=0;
    for(auto i='A';i<='Z';i++)
    {
        h=max(h,m[i]);
    }
    vector<vector<char>> ma(h+2,vector<char>(27));
    for(auto i='A';i<='Z';i++)
    {
        ma[h+1][i-'A'+1]=i;
    }
    for(int i=h;i>=1;i--)
    {
        for(int j=1;j<=26;j++)
        {
            if(m['A'+j-1])
            {
                ma[i][j]='*';
                m['A'+j-1]--;
            }
            else
                ma[i][j]=' ';
        }
    }
    for(int i=1;i<=h+1;i++)
    {
        for(int j=1;j<=26;j++)
        {
            cout<<ma[i][j]<<" ";
        }
        cout<<endl;
    }
}