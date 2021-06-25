#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    set<string> s;
    map<string,int> m;
    while(n--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            string name;
            int score;
            cin>>name>>score;
            if(s.count(name))
            {
                m[name]=score;
            }
            else
            {
                s.emplace(name);
                m[name]=score;
            }
            cout<<"OK"<<endl;
        }
        else if(op==2)
        {
            string name;
            cin>>name;
            if(s.count(name))
            {
                cout<<m[name]<<endl;
            }
            else
            {
                cout<<"Not found"<<endl;
            }
        }
        else if(op==3)
        {
            string name;
            cin>>name;
            if(s.count(name))
            {
                cout<<"Deleted successfully"<<endl;
                s.erase(name);
            }
            else
            {
                cout<<"Not found"<<endl;
            }
        }
        else
        {
            cout<<s.size()<<endl;
        }
    }
}