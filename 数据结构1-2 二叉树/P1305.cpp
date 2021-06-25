#include<bits/stdc++.h>
using namespace std;
void pre(map<char,pair<char,char>>& son,char root)
{
    cout<<root;
    auto &[l,r]=son[root];
    if(l!='*')
        pre(son,l);
    if(r!='*')
        pre(son,r);
}

int main()
{
    int n;
    cin>>n;
    char f,l,r;
    map<char,pair<char,char>> son;
    map<char,int> m;
    for(int i=0;i<n;i++)
    {
        cin>>f>>l>>r;
        son[f]=make_pair(l,r);
        m[f]++;
        m[l]++;
        m[r]++;
    }
    char root;
    for(auto &[i,j]:m)
    {
        if(j==1)
        {
            root=i;
            break;
        }
    }
    pre(son,root);
}