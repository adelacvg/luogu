#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> v;
    copy_n(istream_iterator<int>(std::cin),
    n,
    back_inserter(v));
    int sum=accumulate(begin(v),begin(v)+m,0);
    auto t=sum;
    for(int i=m;i<n;i++)
    {
        t+=v[i];
        t-=v[i-m];
        sum=min(sum,t);
    }
    cout<<sum<<endl;
}