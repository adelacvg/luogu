#include<bits/stdc++.h>
using namespace std;
string m="\
XXX...X.XXX.XXX.X.X.XXX.XXX.XXX.XXX.XXX\
X.X...X...X...X.X.X.X...X.....X.X.X.X.X\
X.X...X.XXX.XXX.XXX.XXX.XXX...X.XXX.XXX\
X.X...X.X.....X...X...X.X.X...X.X.X...X\
XXX...X.XXX.XXX...X.XXX.XXX...X.XXX.XXX";
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    string ans;
    for(int j=0;j<5;j++)
    {
        for(int i=0;i<s.size();i++)
        {
            if(i)
            cout<<'.';
            for(int k=0;k<3;k++)
            {
                cout<<m[39*j+4*(s[i]-'0')+k];
            }
        }
        cout<<endl;
    }
}