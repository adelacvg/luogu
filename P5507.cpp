#include<bits/stdc++.h>
using namespace std;
const int n=(1<<24)+10;
int nxt[14][5],fa[n],choice[n],g[n];
struct node
{
    int state;
    double f;
    node(int s):state(s)
    {
        double h=0;
        f=0;
        for(int i=0;i<12;i++)
        {
            if((s>>(i<<1))&3)
                h+=4-((s>>(i<<1))&3);
        }
        f=h/2+g[s]+h/2*g[s];
    }
    bool operator<(const node &y)const
    {
        return f>y.f;
    }
};

int main()
{
    priority_queue<node> q;
    int t,start=0;
    for(int i=0;i<12;i++)
    {
        cin>>t;
        start|=(t-1)<<(i<<1);
        for(int j=0;j<4;j++)
        {
            cin>>t;
            nxt[i][j]=t-1;
        }
    }
    q.push(node(start));
    g[start]=0;
    while(!q.empty())
    {
        int state=q.top().state;
        q.pop();
        if(state==0)
            break;
        int si,snxt,nx,nxtstate;
        for(int i=0;i<12;i++)
        {
            si=(state>>(i<<1))&3;
            nx=nxt[i][si];
            snxt=(state>>(nx<<1))&3;
            nxtstate=state^(si<<(i<<1))^(((si+1)&3)<<(i<<1))^(snxt<<(nx<<1))^(((snxt+1)&3)<<(nx<<1));
            if(!g[nxtstate])
            {
                g[nxtstate]=g[state]+1;
                fa[nxtstate]=state;
                choice[nxtstate]=i+1;
                q.push(node(nxtstate));
            }
        }
    }
    vector<int> ans;
    int cnt=0;
    int state=0;
    while(state!=start)
    {
        ans.emplace_back(choice[state]);
        state=fa[state];
    }
    cout<<ans.size()<<endl;
    reverse(begin(ans),end(ans));
    for(auto i:ans)
    {
        cout<<i<<" ";
    }
}