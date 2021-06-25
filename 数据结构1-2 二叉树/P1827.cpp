#include<bits/stdc++.h>
using namespace std;

void post(string pre,string in)
{
    if(pre.empty()) return;
    auto root=pre[0];
    auto p=in.find(root);
    string lpre=pre.substr(1,p);
    string rpre=pre.substr(p+1);
    string lin=in.substr(0,p);
    string rin=in.substr(p+1);
    post(lpre,lin);
    post(rpre,rin);
    cout<<root;
}

int main()
{
    string in;
    string pre;
    cin>>in>>pre;
    post(pre,in);
}