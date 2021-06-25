#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v;
    copy_n(istream_iterator<int>(std::cin),n,
    back_inserter(v));
    sort(v.begin(),v.end());
    v.erase(v.begin());
    v.erase(v.end()-1);
    cout<<fixed<<setprecision(2)
    <<accumulate(v.begin(),v.end(),0)/(1.0*n-2);
}