#include<bits/stdc++.h>
using namespace std;

vector<int> split(string str, char deli)
{
    vector<int> res;
    stringstream ss{str};
    string token;
    while(getline(ss,token,deli))
    {
        if(!token.empty())
        {
            res.emplace_back(stoi(token));
        }
    }
    return res;
}
int main()
{
    string s;
    getline(std::cin,s);
    auto v = split(s,' ');
    for(auto i=v.rbegin()+1;i!=v.rend();i++)
    {
        cout<<*i<<" ";
    }
}