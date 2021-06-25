#include<bits/stdc++.h>
using namespace std;

int main()
{
    string pre,post;
    cin>>pre>>post;
    int t=0;
    for(int i=0;i<pre.size()-1;i++)
    {
        for(int j=0;j<pre.size()-1;j++)
        {
            if(pre[i]==post[j+1]&&pre[i+1]==post[j])
            {
                t++;
            }
        }
    }
    cout<<(1<<(t))<<endl;
}