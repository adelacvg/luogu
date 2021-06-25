#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n;
    cin>>n;
    while(1)
    {
        int flag=0;
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]>s[i+1])
            {
                flag=1;
                s.erase(i,1);
                n--;
                break;
            }
        }
        if(n==0||flag==0)break;
    }
    string& ans=s;
    int t=0;
    while(ans[t]=='0')t++;
    ans.erase(0,t);
    if(ans.size()==0)
        cout<<0;
    else
    {
        for(int i=0;i<ans.size()-n;i++)
            cout<<ans[i];
    }
}