#include<bits/stdc++.h>
using namespace std;

int n,m,sum,len,cnt,a[70],nxt[70];
bool ok,used[70];
auto cmp = [](int a,int b){return a>b;};
void dfs(int k,int last,int rest)
{
    int i;
    if(!rest)
    {
        if(k==m)
        {
            ok=1;
            return;
        }
        for(i=1;i<=cnt;i++)
            if(!used[i])
                break;
        used[i]=1;
        dfs(k+1,i,len-a[i]);
        used[i]=0;
        if(ok) return;
    }
    int l=last+1, r=cnt, mid;
    while(l<r){
        mid=(l+r)>>1;
        if(a[mid]<=rest) r=mid;
        else l=mid+1;
    }
    auto p=lower_bound(a+last+1,a+cnt,rest,cmp);
    for(i=p-a;i<=cnt;i++)
    {
        if(!used[i])
        {
            used[i]=1;
            dfs(k,i,rest-a[i]);
            used[i]=0;
            if(ok)
                return;
            if(rest==a[i]||rest==len)
                return;
            i=nxt[i];
            if(i==cnt) return;
        }
    }
}
int main()
{
    cin>>n;
    int d;
    for(int i=1;i<=n;i++)
    {
        cin>>d;
        if(d>50)
            continue;
        a[++cnt]=d;
        sum+=d;
    }
    sort(a+1,a+cnt+1,cmp);
    nxt[cnt]=cnt;
    for(int i=cnt-1;i>=1;i--)
    {
        if(a[i]==a[i+1]) nxt[i]=nxt[i+1];
        else nxt[i]=i;
    }
    for(len = a[1];len<=sum/2;len++)
    {
        if(sum%len) continue;
        m=sum/len;
        ok=0;
        used[1]=1;
        dfs(1,1,len-a[1]);
        used[1]=0;
        if(ok)
        {
            cout<<len<<endl;
            return 0;
        }
    }
    cout<<sum<<endl;
    return 0;
}