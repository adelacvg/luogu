#include<bits/stdc++.h>
using namespace std;
template<class T> using v3 = vector<vector<vector<T>>>;
template<class T> using v2 = vector<vector<T>>;
template<class T> using v1 = vector<T>;
using i64=long long;
int city[18][100001][2];
i64 disa[18][100001][2],disb[18][100001][2];
pair<int,int> solve(int s,int x,int bound)
{
    auto lena=0,lenb=0;
    for(int i=bound;i>=0;i--)
    {
        if(city[i][s][0]&&lena+lenb+disa[i][s][0]+disb[i][s][0]<=x)
        {
            lena+=disa[i][s][0];
            lenb+=disb[i][s][0];
            s=city[i][s][0];
        }
    }
    return {lena,lenb};
}

int main()
{
    int n;
    cin>>n;
    vector<i64> h(n+1);
    for(int i=1;i<=n;i++)
        cin>>h[i];
    int x0;
    cin>>x0;
    int m;
    cin>>m;
    vector<i64> s(m+1),x(m+1);
    for(int i=1;i<=m;i++)
    {
        cin>>s[i]>>x[i];
    }
    auto cmp=[](auto& a,auto& b){return a.second<b.second;};
    multiset<pair<i64,i64>,decltype(cmp)> st(cmp);
    st.insert({0,INT_MAX});
    st.insert({0,INT_MAX});
    st.insert({n+1,INT_MIN});
    st.insert({n+1,INT_MIN});
    int bound=0;
    while((1<<(bound+1))<=n)
        bound++;


    for(int i=n;i>=1;i--)
    {
        auto iter=st.insert({i,h[i]});
        vector<pair<int,int>> v;
        --iter;
        v.emplace_back(*iter);
        --iter;
        v.emplace_back(*iter);
        ++++++iter;
        v.emplace_back(*iter);
        ++iter;
        v.emplace_back(*iter);
        sort(begin(v),end(v),[&](auto& a,auto& b)
        {
            auto t1=abs(h[i]-a.second);
            auto t2=abs(h[i]-b.second);
            if(t1<t2)
                return true;
            else if(t1==t2)
                return h[a.first]<h[b.first];
            else
                return false;
        });
        // cout<<v[0].first<<" "<<v[0].second<<endl;
        // cout<<v[1].first<<" "<<v[1].second<<endl;
        city[0][i][0]=v[1].first;
        city[0][i][1]=v[0].first;
        disa[0][i][0]=abs(v[1].second-h[i]);
        disb[0][i][1]=abs(v[0].second-h[i]);
    }
    for(int i=1;i<=bound;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=0;k<2;k++)
            {
                if(i==1)
                {
                    city[i][j][k]=city[i-1][city[i-1][j][k]][!k];
                    disa[i][j][k]=disa[i-1][j][k]+disa[i-1][city[i-1][j][k]][!k];
                    disb[i][j][k]=disb[i-1][j][k]+disb[i-1][city[i-1][j][k]][!k];
                }
                else
                {
                    city[i][j][k]=city[i-1][city[i-1][j][k]][k];
                    disa[i][j][k]=disa[i-1][j][k]+disa[i-1][city[i-1][j][k]][k];
                    disb[i][j][k]=disb[i-1][j][k]+disb[i-1][city[i-1][j][k]][k];
                }
            }
        }
    }
    double ratio=INT_MAX;
    int ans=1;
    for(int i=1;i<=n;i++)
    {
        auto tt=solve(i,x0,bound);
        auto t=1.0*tt.first/tt.second;
        if(t<ratio)
        {
            ratio=t;
            ans=i;
        }
        else if(t==ratio&&h[i]>h[ans])
        {
            ans=i;
        }
    }
    cout<<ans<<endl;
    for(int i=1;i<=m;i++)
    {
        auto t=solve(s[i],x[i],bound);
        cout<<t.first<<" "<<t.second<<'\n';
    }
}