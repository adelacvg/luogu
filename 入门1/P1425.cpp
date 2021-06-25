#include<bits/stdc++.h>
using namespace std;

int main()
{
    int h1,m1,h2,m2;
    cin>>h1>>m1>>h2>>m2;
    int delta = h2*60+m2-(h1*60+m1);
    cout<<delta/60<<" "<<delta%60<<endl;
    return 0;
}