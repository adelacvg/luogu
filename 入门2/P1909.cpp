#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int money=1000000000;
    int num,value;
    for(int i=0;i<3;i++)
    {
        cin>>num>>value;
        money=min((int)ceil(n*1.0/num)*value,money);
    }
    cout<<money<<endl;
}