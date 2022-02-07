#include<bits/stdc++.h>
using namespace std;

template<class... T>
auto sum(T ...t)
{
    return(0+...+t);
}

template <class T0, class... T>
void print(T0 const & t0,T const &... t)
{
    std::cout<<t0;
    ((std::cout<<' '<<t),...);
    std::cout<<std::endl;
}

int main()
{
    print(2, 4, 'a');
    return 0;
}