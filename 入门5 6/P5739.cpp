#include<bits/stdc++.h>
using namespace std;
template<int N>
class Fac {
public:
    static constexpr auto value = N * Fac<N - 1>::value;
};

template<>
class Fac<0> {
public:
    static constexpr auto value = 1;
};
int a[14];


int main()
{
    int n;
    cin>>n;
    a[0]=Fac<0>::value;
    a[1]=Fac<1>::value;
    a[2]=Fac<2>::value;
    a[3]=Fac<3>::value;
    a[4]=Fac<4>::value;
    a[5]=Fac<5>::value;
    a[6]=Fac<6>::value;
    a[7]=Fac<7>::value;
    a[8]=Fac<8>::value;
    a[9]=Fac<9>::value;
    a[10]=Fac<10>::value;
    a[11]=Fac<11>::value;
    a[12]=Fac<12>::value;
    std::cout << a[n]; // 120
}