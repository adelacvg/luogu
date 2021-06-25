#include<bits/stdc++.h>
using namespace std;
stringstream ss;
int msb(unsigned x)
{
    cout<<x<<endl;
    union {double a; int b[2]; };
    a=x;
    cout<<(b[1]>>20)<<endl;
    return (b[1]>>20)-1023;
}
void dfs(int n)
{
    bitset<64> x(n);
    // cout<<msb(n)<<'\n';
    // for(int i=msb(n);i>=0;i--)
    // {
    //     cout<<i<<" "<<x[i]<<'\n';
    // }
    int flag=0;
    for(int i=msb(n);i>=0;i--)
    {
        if(x[i])
        {
            if(flag)
                ss<<'+';
            else
                flag=1;
            if(i==1)
            ss<<2;
            else
            {
                ss<<"2(";
                if(i==0)
                    ss<<0;
                else
                    dfs(i);
                ss<<")";
            }
        }
    }
}
int main()
{
    int x;
    cin>>x;
    dfs(x);
    cout<<ss.str();
}