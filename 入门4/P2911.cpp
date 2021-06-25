#include<bits/stdc++.h>
using namespace std;

int main()
{
    int s1,s2,s3;
    cin>>s1>>s2>>s3;
    if(s1>s2)swap(s1,s2);
    if(s2>s3)swap(s2,s3);
    if(s1>s2)swap(s1,s2);
    double e1,e2,e3;
    e1=(s1+1)*s1/2.0/s1;
    e2=(s2+1)*s2/2.0/s2;
    e3=(s3+1)*s3/2.0/s3;
    auto ans=e1+e2+e3;
    if(s2<=s3-s1+1)
        ans-=(s3-s1-s2+1)/2.0;
    
    cout<<floor(ans)<<endl;
}