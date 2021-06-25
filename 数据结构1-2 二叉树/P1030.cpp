#include<bits/stdc++.h>
using namespace std;
void pre(string in,string post)
{
    if(post.empty())
        return;
    auto root=post[post.size()-1];
    cout<<root;
    auto p=in.find(root);
    string lin=in.substr(0,p);
    string rin=in.substr(p+1);
    string lpost=post.substr(0,p);
    string rpost=post.substr(p,rin.size());
    pre(lin,lpost);
    pre(rin,rpost);
}

int main()
{
    string in,post;
    cin>>in>>post;
    pre(in,post);
}