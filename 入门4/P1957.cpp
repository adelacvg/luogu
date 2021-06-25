#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    map<char,char> m;
    m['a']='+';
    m['b']='-';
    m['c']='*';
    map<char,function<int(int,int)>> m1;
    m1['a']=[](int a,int b){return a+b;};
    m1['b']=[](int a,int b){return a-b;};
    m1['c']=[](int a,int b){return a*b;};
    stringstream ss;
    char op,c;
    int x,y;
    string s;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    for(int i=0;i<n;i++)
    {
        getline(std::cin,s);
        ss.clear();
        ss.str(s);
        c=ss.peek();
        if(isalpha(c))
        {
            ss>>op;
        }
        ss>>x>>y;
        s=to_string(x)+char(m[op])+
        to_string(y)+"="+to_string(m1[op](x,y));
        cout<<s<<endl;
        cout<<s.size()<<endl;
    }
}