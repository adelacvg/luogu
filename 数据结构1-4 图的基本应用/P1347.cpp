#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> e(n,vector<int>{});
    char a,b,c;
    vector<int> ind(n,0);
    int flag=0;
    vector<int> vis(n);
    int now=0;
    for(int cnt=1;cnt<=m;++cnt)
    {
        cin>>a>>b>>c;
        if(a==c)
        {
            flag=1;
            cout<<"Inconsistency found after "<<cnt<<" relations."<<endl;
        }
        if(flag)
            continue;
        if(!vis[a-'A'])
        {
            vis[a-'A']=1;
            now++;
        }
        if(!vis[c-'A'])
        {
            vis[c-'A']=1;
            now++;
        }
        if(find(begin(e[a-'A']),end(e[a-'A']),c-'A')==e[a-'A'].end())
        {
            e[a-'A'].emplace_back(c-'A');
            ind[c-'A']++;
        }
        else
            continue;
        vector<int> st;
        for(int i=0;i<n;i++)
            if(vis[i]&&ind[i]==0)
                st.emplace_back(i);
        if(st.size()>1)
        {
            vector<int> ind_t(ind);
            queue<int> q;
            for(auto i:st)
                q.emplace(i);
            int sm=st.size();
            while(!q.empty())
            {
                auto t=q.front();
                q.pop();
                for(auto i:e[t])
                {
                    if(--ind_t[i]==0)
                    {
                        q.emplace(i);
                        sm++;
                    }
                }
            }
            if(sm!=now)
            {
                flag=1;
                cout<<"Inconsistency found after "<<cnt<<" relations."<<endl;
            }
            continue;
        }
        if(st.empty())
        {
            flag=1;
            cout<<"Inconsistency found after "<<cnt<<" relations."<<endl;
        }
        if(st.size()==1)
        {
            vector<int> ind_t(ind);
            queue<int> q;
            q.emplace(st[0]);
            int sm=1;
            string s(1,'A'+st[0]);
            int cannot=0;
            while(!q.empty())
            {
                if(q.size()>1)
                {
                    cannot=1;
                    break;
                }
                auto t=q.front();
                q.pop();
                for(auto i:e[t])
                {
                    if(--ind_t[i]==0)
                    {
                        q.emplace(i);
                        sm++;
                        s.append(string(1,'A'+i));
                    }
                }
            }
            if(cannot)
                continue;
            if(sm==n)
            {
                flag=1;
                cout<<"Sorted sequence determined after "<<cnt<<
                " relations: "<<s<<"."<<endl;
            }
            else
            {
                if(sm!=now)
                {
                    flag=1;
                    cout<<"Inconsistency found after "<<cnt<<" relations."<<endl;
                }
            }
        }
    }
    if(!flag)
        cout<<"Sorted sequence cannot be determined."<<endl;
}