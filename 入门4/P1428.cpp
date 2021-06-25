#include<bits/stdc++.h>
using namespace std;
vector<int> a(200);
int lowbit(int n)
{
    return n&(-n);
}
int sum(int i)
{
    int ans=0;
    while(i)
    {
        ans+=a[i];
        i-=lowbit(i);
    }
    return ans;
}
void update(int i,int j)
{
    while(i<110)
    {
        a[i]+=j;
        i+=lowbit(i);
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int> v;
    copy_n(istream_iterator<int>(std::cin),
    n,
    back_inserter(v));

    vector<int> w(v.size());
    iota(w.begin(),w.end(),0);
    stable_sort(begin(w),end(w),
        [&](auto a,auto b)
        {
            return v[a]<v[b];
        }
    );
    sort(begin(v),end(v));
    vector<int> u;
    transform
    (begin(v),end(v),back_inserter(u),
        [&,i=0](int a)mutable
        {
            auto t=0;
            if(i&&(v[i]==v[i-1]))
                t=u[i-1];   
            else t=i;
            i++;
            return t;
        }
    );
    iota(v.begin(),v.end(),0);
    stable_sort(begin(v),end(v),[&](auto a,auto b)
    {
        return w[a]<w[b];
    });
    vector<int> ans;

    for(int i=0;i<n;i++)
    {
        ans.emplace_back(sum(u[v[i]]));
        update(u[v[i]]+1,1);        
    }
    for(auto i:ans)
        cout<<i<<" ";
}