#include<bits/stdc++.h>
using namespace std;

int main()
{
    string c;
    cin>>c;
    transform(c.begin(),c.end(),c.begin(),
    [](unsigned char c){return toupper(c);});
    cout<<c<<endl;
    return 0;
}