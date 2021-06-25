#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<string,int> m={
        {"one",1},{"two",2},{"three",3},
        {"four",4},{"five",5},{"six",6},
        {"seven",7},{"eight",8},{"nine",9},
        {"ten",10},{"eleven",11},{"twelve",12},
        {"thirteen",13},{"fourteen",14},{"fifteen",15},
        {"sixteen",16},{"seventeen",17},{"eighteen",18},
        {"nineteen",19},{"twenty",20},{"a",1},{"both",2},
        {"another",1},{"first",1},{"second",2},{"third",3},
    };
    
    string s;
    vector<int> v;
    for(int i=0;i<6;i++)
    {
        cin>>s;
        if(m.find(s)!=m.end())
            v.push_back(m[s]);
    }
    transform(begin(v),end(v),begin(v),
    [](int n){return (n*n)%100;});
    sort(begin(v),end(v));
    string ans="0";
    for(auto i:v)
    {
        if(to_string(i).size()==1)
            ans+="0";
        ans+=to_string(i);
    }
    cout<<stoull(ans)<<endl;
}