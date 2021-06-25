#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int min_num=min(min(a,b),c);
    int max_num=max(max(a,b),c);
    cout<<min_num<<" "
    <<a+b+c-min_num-max_num<<" "
    <<max_num<<endl;
}