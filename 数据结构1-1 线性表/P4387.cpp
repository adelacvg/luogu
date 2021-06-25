#include<bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    int n;
    cin>>q;
    while(q--)
    {
        cin>>n;
        int x;
        unordered_map<int,int> id;

        for(int i=0;i<n;i++)
        {
            cin>>x;
            id[x]=i;
        }
        stack<int> st;
        int now=-1;
        int flag=1;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            if(flag==0)
                continue;
            else if(id[x]>now)
            {
                for(int i=now+1;i<id[x];i++)
                {
                    st.emplace(i);
                }
                now=id[x];
            }
            else
            {
                if(id[x]==st.top())
                {
                    st.pop();
                }
                else
                {
                    flag=0;
                }
            }
        }
        if(flag)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}