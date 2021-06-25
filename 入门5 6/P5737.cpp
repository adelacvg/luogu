#include<bits/stdc++.h>
using namespace std;
int judge(int n)
{
    if(n%4==0&&n%100!=0||n%400==0)
        return 1;
    else
        return 0;
}

int main()
{
    int x,y;
    cin>>x>>y;
    vector<int> ans;
    for(int i=x;i<=y;i++)
    {
        if(judge(i))
        {
            ans.emplace_back(i);
        }
    }
    cout<<ans.size()<<endl;
    for(auto i:ans)
        cout<<i<<" ";
}