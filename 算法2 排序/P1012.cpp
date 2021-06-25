#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    sort(begin(v),end(v),[](auto &i,auto &j){
        string s1=to_string(i);
        string s2=to_string(j);
        for(int i=0,j=0;i<s1.size()&&j<s2.size();i++,j++)
        {
            if(s1[i]>s2[j])
                return true;
            else if(s1[i]<s2[j])
                return false;
        }
        return s1+s2>s2+s1;
    });
    for(auto i:v)
        cout<<i;
}