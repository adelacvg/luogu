#include<bits/stdc++.h>
using namespace std;
template <class T>
inline bool scan_d(T &ret)
{
    char c;int sgn;
    if(c=getchar(),c==EOF) return 0;
    while(c!='-'&&(c<'0'||c>'9')) c=getchar();
    sgn=(c=='-')?-1:1;
    ret=(c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
    ret*=sgn;
    return 1;
}
inline void out(int x)
{
    if(x>9) out(x/10);
    putchar(x%10+'0');
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n+1);
    for(int i=0;i<n;i++)
        scan_d(v[i]);
    nth_element(begin(v),next(begin(v),k),begin(v)+n);
    out(v[k]);
}