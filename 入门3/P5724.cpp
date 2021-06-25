#include<bits/stdc++.h>
using namespace std;

int main()
{
    int max_num=-2000,min_num=2000,x;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        max_num=max(x,max_num);
        min_num=min(x,min_num);
    }
    cout<<max_num-min_num<<endl;
}