#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    copy_n(istream_iterator<int>(std::cin),
    12,
    back_inserter(v));
    int bank=0;
    int hand=0;
    int save=0;
    for(int i=0;i<12;i++)
    {
        hand+=300;
        if(v[i]>hand)
        {
            cout<<"-"<<i+1<<endl;
            return 0;
        }
        save=100*((hand-v[i])/100);
        hand-=save+v[i];
        bank+=save;
    }
    cout<<bank*1.2+hand<<endl;
}