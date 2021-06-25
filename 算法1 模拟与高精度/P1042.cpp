#include<bits/stdc++.h>
using namespace std;

int main()
{
    // ofstream cout("out.txt");
    string str,s;
    while(cin>>s)
    {
        str+=s;
    }
    int cnt=0;
    int w1=0,w2=0,l1=0,l2=0;
    vector<pair<int,int>> ans1,ans2;
    for(auto i:str)
    {
        if(i=='W')
        {
            w1++;
            w2++;
        }
        else if(i=='L')
        {
            l1++;
            l2++;
        }
        else
            break;
        if((w1>=11||l1>=11)&&abs(w1-l1)>=2)
        {
            ans1.emplace_back(make_pair(w1,l1));
            w1=0;
            l1=0;
        }
        if((w2>=21||l2>=21)&&abs(w2-l2)>=2)
        {
            ans2.emplace_back(make_pair(w2,l2));
            w2=0;
            l2=0;
        }
    }
    ans1.emplace_back(make_pair(w1,l1));
    ans2.emplace_back(make_pair(w2,l2));
    for(auto [i,j]:ans1)
    {
        cout<<i<<":"<<j<<endl;
    }
    cout<<endl;
    for(auto [i,j]:ans2)
    {
        cout<<i<<":"<<j<<endl;
    }

}