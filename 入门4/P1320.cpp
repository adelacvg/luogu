#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s,code="0";
    cin>>s;
    code+=s;
    for(int i=1;i<s.size();i++)
    {
        cin>>s;
        code+=s;
    }
    vector<int> ans;
    int num=0;
    for(int i=1;i<=code.size();i++)
    {
        if(code[i]==code[i-1])
            num++;
        else
        {
            ans.emplace_back(num);
            num=1;
        }
    }
    cout<<s.size()<<" ";
    for(auto i:ans)
        cout<<i<<" ";
}