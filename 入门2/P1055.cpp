#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int sum=0;
    cin>>s;
    s.erase(remove(s.begin(),s.end(),'-'),s.end());
    for(int i=0;i<9;i++)
    {
        sum+=(s[i]-'0')*(i+1);
    }
    if(((sum%11==10)?'X':('0'+sum%11))==s[9])
        cout<<"Right"<<endl;
    else
    {
        cout<<s[0]<<"-";
        for(int i=1;i<=3;i++)
            cout<<s[i];
        cout<<"-";
        for(int i=4;i<=8;i++)
            cout<<s[i];
        cout<<"-";
        cout<<(char)((sum%11==10)?'X':'0'+sum%11);
    }
    
}