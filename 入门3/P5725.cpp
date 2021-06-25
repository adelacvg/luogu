#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int t=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<setfill('0')<<setw(2)<<t;
            t++;
        }
        cout<<endl;
    }
    cout<<endl;
    t=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j<=n-i)
                cout<<"  ";
            else
            {
                cout<<setfill('0')<<setw(2)<<t;
                t++;
            }
        }
        cout<<endl;
    }
}