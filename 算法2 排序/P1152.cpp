#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    adjacent_difference(begin(v),end(v),begin(v),
    [](auto i,auto j){
        return abs(i-j);
    });
    map<int,int> m;
    for(auto i:v)
    {
        m[i]++;
    }
    int flag=1;
    for(int i=1;i<=n-1;i++)
        if(!m[i])
            flag=0;
    if(flag)
        cout<<"Jolly"<<endl;
    else
        cout<<"Not jolly"<<endl;
}