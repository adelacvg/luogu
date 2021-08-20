#include<bits/stdc++.h>
using namespace std;
int n;
string a,b,c;
vector<int> nxt;
vector<bool> used(100);
vector<int> num(30,-1);
bool judge()
{
    int x=0;
    for(int i=n-1;i>=0;i--)
    {
        int A=num[a[i]-'A'];
        int B=num[b[i]-'A'];
        int C=num[c[i]-'A'];
        if((A+B+x)%n!=C)
            return false;
        x=(A+B+x)/n;
    }
    return true;
}
void print()
{
    for(int i=0;i<n;i++)
    {
        cout<<num[i]<<" ";
    }
    cout<<endl;
}
bool prune()
{
    if(num[a[0]-'A']+num[b[0]-'A']>=n)
        return true;
    for(int i=n-1;i>=0;i--)
    {
        int A=num[a[i]-'A'];
        int B=num[b[i]-'A'];
        int C=num[c[i]-'A'];
        if(A==-1||B==-1||C==-1) continue;
        if((A+B)%n!=C&&(A+B+1)%n!=C)
            return true;
    }
    return false;
}
bool dfs(int x)
{
    // print();
    if(prune()==true)
        return false;
    if(x==n)
    {
        if(judge())
            print();
        return true;
    }
    for(int i=n-1;i>=0;i--)
    {
        if(used[i]==false)
        {
            num[nxt[x]]=i;
            used[i]=true;
            if(dfs(x+1))
                return true;
            num[nxt[x]]=-1;
            used[i]=false;
        }
    }
    return false;
}

int main()
{
    cin>>n;
    cin>>a>>b>>c;
    for(int i=n-1;i>=0;i--)
    {
        if(used[a[i]-'A']==false)
        {
            nxt.emplace_back(a[i]-'A');
            used[a[i]-'A']=true;
        }
        if(used[b[i]-'A']==false)
        {
            used[b[i]-'A']=true;
            nxt.emplace_back(b[i]-'A');
        }
        if(used[c[i]-'A']==false)
        {
            used[c[i]-'A']=true;
            nxt.emplace_back(c[i]-'A');
        }
    }
    fill(begin(used),end(used),false);
    dfs(0);
}