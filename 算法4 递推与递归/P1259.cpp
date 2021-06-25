#include<bits/stdc++.h>
using namespace std;
vector<string> v{"ooo*o**--*",
                "o--*o**oo*",
                "o*o*o*--o*",
                "--o*o*o*o*"};
int main()
{
    int n;
    cin>>n;
    string s=string(n,'o')+
    string(n,'*')+string(2,'-');
    int i=n-1,j=n,len=n+1;
    n--;
    while(n--)
    {
        if(n==1)
        {
            cout<<v[0]<<s.substr(10,s.size()-10)<<'\n';
            cout<<v[1]<<s.substr(10,s.size()-10)<<'\n';
            continue;
        }
        if(n==0)
        {
            cout<<v[2]<<s.substr(10,s.size()-10)<<'\n';
            cout<<v[3]<<s.substr(10,s.size()-10)<<'\n';
            continue;
        }
        cout<<s<<'\n';
        swap(s[i],s[i+len]);
        swap(s[j],s[j+len]);
        cout<<s<<'\n';
        swap(s[i],s[i+len-2]);
        swap(s[j],s[j+len-2]);
        i--;
        j--;
        len--;
    }
}