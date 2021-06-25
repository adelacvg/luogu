#include<bits/stdc++.h>
using namespace std;
int cal(string s)
{
    int res=1;
    for(auto i:s)
    {
        res=res*(i-'A'+1)%47;
    }
    return res;
}
int main()
{
    string s;
    cin>>s;
    string s1;
    cin>>s1;
    if(cal(s)==cal(s1))
        cout<<"GO"<<endl;
    else
        cout<<"STAY"<<endl;
}