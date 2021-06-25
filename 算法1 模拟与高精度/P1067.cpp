#include<bits/stdc++.h>
using namespace std;
void print(int x)
{
    if(x==1)
        cout<<"x";
    else
        cout<<"x^"<<x;
}
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    int x;
    for(int i=0;i<=n;i++)
    {
        cin>>x;
        v.emplace_back(x);
    }
    int flag=0;
    for(int i=0;i<=n;i++)
    {
        if(v[i]==0)
            continue;
        else if(flag==0)
        {
            if(v[i]==1)
                print(n-i);
            else if(v[i]==-1)
            {
                cout<<"-";
                print(n-i);
            }
            else
            {
                cout<<v[i];
                print(n-i);
            }
            flag=1;
        }
        else if(i==n)
            cout<<showpos<<v[i]<<noshowpos;
        else if(v[i]==1)
        {
            cout<<"+";
            print(n-i);
        }
        else if(v[i]==-1)
        {
            cout<<"-";
            print(n-i);
        }
        else
        {
            cout<<showpos<<v[i]<<noshowpos;
            print(n-i);
        }
    }
}