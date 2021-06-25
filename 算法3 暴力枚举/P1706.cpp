#include<bits/stdc++.h>
using namespace std;

int main()
{
    stringstream ss;
    int n;
    cin>>n;
    vector<int> v(n);
    iota(v.begin(),v.end(),1);
    int fac=accumulate(begin(v),end(v),1,multiplies<int>());
    for(int j=0;j<fac;j++)
    {
        for(auto i:v)
            ss<<setw(5)<<i;
        ss<<endl;
        next_permutation(begin(v),end(v));
    }
    cout<<ss.str();
}