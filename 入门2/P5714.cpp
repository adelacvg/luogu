#include<bits/stdc++.h>
using namespace std;

int main()
{
    double m,h;
    cin>>m>>h;
    auto bmi=m/h/h;
    if(bmi<18.5) cout<<"Underweight"<<endl;
    else if(bmi<24) cout<<"Normal"<<endl;
    else
    {
        cout<<bmi<<endl;
        cout<<"Overweight"<<endl;
    }
    
}