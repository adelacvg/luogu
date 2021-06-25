#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> vis(200,0);
    string s;
    cin>>s;
    string str="VK";
    auto res=search(s.begin(),s.end(),
    boyer_moore_searcher(str.begin(),str.end()));
    int ans=0;
    if(res!=s.end())
    {
        ans++;
        vis[res-s.begin()]=1;
        vis[res-s.begin()+1]=1;
    }
    while(res!=s.end())
    {
        res=search(res+2,s.end(),
        boyer_moore_searcher(str.begin(),str.end()));
        if(res!=s.end())
        {
            vis[res-s.begin()]=1;
            vis[res-s.begin()+1]=1;
            ans++;
        }
    }
    bool flag=0;
    if(flag==0)
    {
        str="VV";
        res=search(s.begin(),s.end(),
        boyer_moore_searcher(str.begin(),str.end()));
        if(res!=s.end()&&
            !vis[res-s.begin()]&&
            !vis[res-s.begin()+1])
        {
            ans++;
            flag=1;
        }
        while(res!=s.end()&&!flag)
        {
            res=search(res+1,s.end(),
            boyer_moore_searcher(str.begin(),str.end()));
            if(res!=s.end()&&
                !vis[res-s.begin()]&&
                !vis[res-s.begin()+1])
            {
                ans++;
                flag=1;
                break;
            }
        }
    }
    if(flag==0)
    {
        str="KK";
        res=search(s.begin(),s.end(),
        boyer_moore_searcher(str.begin(),str.end()));
        if(res!=s.end()&&
            !vis[res-s.begin()]&&
            !vis[res-s.begin()+1])
        {
            ans++;
            flag=1;
        }
        while(res!=s.end()&&!flag)
        {
            res=search(res+1,s.end(),
            boyer_moore_searcher(str.begin(),str.end()));
            if(res!=s.end()&&
                !vis[res-s.begin()]&&
                !vis[res-s.begin()+1])
            {
                ans++;
                flag=1;
                break;
            }
        }
    }
    cout<<ans<<endl;
}