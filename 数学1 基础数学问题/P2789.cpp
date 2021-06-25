#include<bits/stdc++.h>
using namespace std;

vector<bitset<305>> dp(30,bitset<305>{});
int n,x;

int main()
{
	cin>>n;
	x=(n*(n-1))>>1;
	for(int i=1;i<=n;i++)
	    dp[i].set(0);
	for(int i=1;i<=n;i++)
	    for(int j=0;j<=x;j++)
	        for(int k=1;k<=n-i;k++)
	        if(dp[i].test(j))
	            dp[i+k].set(j+i*k,1);
	cout<<dp[n].count()<<endl;
	return 0;
}