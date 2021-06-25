#include<bits/stdc++.h>
using namespace std;
const double g=0.5772156649;

int main()
{
    int k;
    cin>>k;
    cout<<ceil(exp(k-g)-0.5)<<endl;
}