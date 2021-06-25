#include<bits/stdc++.h>
using namespace std;
int a[20]{0,31,28,31,30,31,30,31,31,30,31,30,31};
int b[20]{0,31,29,31,30,31,30,31,31,30,31,30,31};

int main()
{
    int n,m;
    cin>>n>>m;
    if(n%4==0&&n%100!=0||n%400==0)
    {
        cout<<b[m]<<endl;
    }
    else
    {
        cout<<a[m]<<endl;
    }
    return 0;
}