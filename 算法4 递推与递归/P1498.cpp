#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int h=1<<n;
    vector<int> a(1025,0);
    a[0]=1;
    for(int i=h-1;i>=0;i--)
    {
        cout<<string(i,' ');
        for(int j=h-i-1;j>=1;j--)
        {
            a[j]^=a[j-1];
        }
        if(i%2)
        for(int j=0;j<=h-i-1;++j)
            cout<<(a[j]?"/\\":"  ");
        else
            for(int j=0;j<=h-i-1;j+=2)
                cout<<(a[j]?"/__\\":"    ");
        cout<<'\n';
    }
}