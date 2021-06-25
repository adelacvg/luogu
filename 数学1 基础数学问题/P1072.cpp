#include<bits/stdc++.h>
using namespace std;
using i64=unsigned long long;


int main()
{
    i64 a0,a1,b0,b1;
    int t;
    cin>>t;
    while(t--)
    {
        int ans=0;
        cin>>a0>>a1>>b0>>b1;
        i64 t1=a0/a1;
        i64 t2=b1/b0;
        for(i64 i=1;i*i<=b1;i++)
        {
            if(b1%i==0)
            {
                if(i%a1==0&&gcd(i/a1,t1)==1&&gcd(t2,b1/i)==1) ans++;
                auto j=b1/i;
                if(i==j)
                    continue;
                if(j%a1==0&&gcd(j/a1,t1)==1&&gcd(t2,b1/j)==1)
                    ans++;
            }
        }
        cout<<ans<<endl;
    }
}