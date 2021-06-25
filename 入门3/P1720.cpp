#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    double fn=(pow((1+sqrt(5))/2,n)-pow((1-sqrt(5))/2,n))/sqrt(5);
    cout<<fixed<<setprecision(2)<<fn<<endl;
}