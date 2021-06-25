#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int k=0;
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            k++;
            cout<<setfill('0')<<setw(2)<<k;
        }
        cout<<endl;
    }
}