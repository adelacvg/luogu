#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int x=100,k=1;
    while(x*364>n)
        x--;
    while(x>=1)
    {
        for(int k=1;k<=100;k++)
        {
            if(x*364+1092*k==n)
            {
                cout<<x<<endl;
                cout<<k<<endl;
                return 0;
            }
        }
        x--;
    }
}