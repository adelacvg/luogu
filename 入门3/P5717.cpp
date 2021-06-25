#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    int n;cin>>n;
    int t;
    copy_n(istream_iterator<int>(std::cin),n,
    back_inserter(v));
    cout<<*min_element(v.begin(),v.end())<<endl;
}