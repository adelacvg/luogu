#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin>>n>>x;
    vector<int> v(n);
    iota(v.begin(),v.end(),1);
    int ans=0;
    for(auto i:v)
    {
        auto s=to_string(i);
        ans+=count(s.begin(),s.end(),x+'0');
    }
    cout<<ans<<endl;
}
/*
int main(){
    int n,x,m=1,ans=0;
    scanf("%d%d",&n,&x);
    while(m<=n){
        //a,b,c为n的三部分，求哪一位x的个数，b就为那一位数，a为b左边的数，c为b右边的数，如求1~728中十位7的个数，则a=7，b=2，c=8
        int a=n/(m*10),b=n/m%10,c=n%m; 
        if(x){
            if(b>x) ans+=(a+1)*m; //如果b>x，说明有(a+1)*m个x（如求1~728中个位7的个数，则为（72+1）*1=73）
            if(b==x) ans+=a*m+c+1; //如果b=x，说明有a*m+c+1个x（如求1~728中百位7的个数，则为0*100+28+1=29）
            if(b<x) ans+=a*m; //如果b<x，说明有a*m个x（如求1~728中十位7的个数，则为7*10个）
        }
        else{ //x=0的情况和x！=0的情况有所不同
            if(b) ans+=a*m;
            else ans+=(a-1)*m+c+1;
        }
        m*=10;
    }
    printf("%d\n",ans);
    return 0;
}
*/