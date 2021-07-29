#include<bits/stdc++.h>
using namespace std;
unsigned int mulmod(unsigned int a, unsigned int b, unsigned int modulo)
{
    return ((unsigned long long)a*b)%modulo;
}
unsigned int powmod(unsigned int base, unsigned int exponent,unsigned int modulo)
{
    unsigned int result =1;
    while(exponent>0)
    {
        if(exponent&1)
            result=(result*(unsigned long long)base)%modulo;
        
        base = (base*(unsigned long long)base)%modulo;
        exponent>>=1;
    }
    return result;
}
bool isPrime(unsigned long long p)
{
    const unsigned int bitmaskPrimes2to31 = (1<<2)|(1<<3)|(1<<5)|(1<<7)|
                                            (1<<11)|(1<<13)|(1<<17)|(1<<19)|
                                            (1<<23)|(1<<29);
    if(p<31)
        return (bitmaskPrimes2to31&(1<<p)) !=0;
    if(p%2==0||p%3==0||p%5==0||
    p%7==0||p%11==0||p%13==0||p%17==0)
        return false;
    if(p<17*19)
        return true;
    const unsigned int STOP=0;
    const unsigned int TestAgainst1[]={377687, STOP};
    const unsigned int TestAgainst2[]={31,73, STOP};
    const unsigned int TestAgainst3[]={2,7,61, STOP};
    const unsigned int TestAgainst4[]={2,13,23,1662803, STOP};
    const unsigned int TestAgainst7[]={2,325,9375,28178,450775,9780504,1795265022, STOP};

    const unsigned int* testAgainst = TestAgainst7;
    if(p<5329)
        testAgainst = TestAgainst1;
    else if(p<9080191)
        testAgainst = TestAgainst2;
    else if(p<4759123141ULL)
        testAgainst = TestAgainst3;
    else if(p<1122004669633ULL)
        testAgainst = TestAgainst4;
    auto d=p-1;
    d>>=1;
    unsigned int shift=0;
    while((d&1)==0)
    {
        shift++;
        d>>=1;
    }
    do
    {
        auto x=powmod(*testAgainst++, d, p);
        if(x==1||x==p-1)
            continue;
        bool maybePrime = false;
        for(unsigned int r=0;r<shift;r++)
        {
            x= mulmod(x,x,p);
            if(x==1)
                return false;
            if(x==p-1)
            {
                maybePrime = true;
                break;
            }
        }
        if(!maybePrime)
            return false;
    } while (*testAgainst!=STOP);
    return true;
}
vector<long long> primes;
unsigned long long pi(unsigned long long n)
{
    if(!primes.empty()&&primes.back()>n)
    {
        auto i=upper_bound(begin(primes),end(primes),n);
        return distance(begin(primes),i);
    }
    auto v=(unsigned int) sqrt(n);
    vector<unsigned long long>  higher(v+2,0);
    vector<unsigned int>        lower(v+2,0);
    vector<bool>                used(v+2,false);
    unsigned long long result=n-1;
    for(unsigned int p=2;p<=v;p++)
    {
        lower[p]=p-1;
        higher[p]=n/p-1;
    }
    for(unsigned int p=2;p<=v;p++)
    {
        if(lower[p]==lower[p-1])
            continue;
        if(primes.empty()||p>primes.back())
            primes.push_back(p);
        auto temp = lower[p-1];
        result -= higher[p]-temp;

        auto pSquare = (unsigned long long)p*p;
        auto end = min<unsigned long long>(v,n/pSquare);
        auto j=1+(p&1);

        for(auto i=p+j;i<=end+1;i+=j)
        {
            if(used[i])
            continue;
            auto d=i*p;
            if(d<=v)
                higher[i]-=higher[d]-temp;
            else
                higher[i]-=lower[n/d]-temp;
        }
        for(auto i=v;i>=pSquare;i--)
            lower[i]-=lower[i/p]-temp;
        for(auto i=pSquare;i<=end;i+=p*j)
            used[i]=true;
    }
    return result;
}


const int mx = 2000000+10;
vector<bool> flag(mx,0);
void sieve(unsigned long long n)
{
    flag[0]=flag[1]=1;
    for(auto i=2ull;i<=n;i++)
    {
        if(!flag[i])
            primes.emplace_back(i);
        for(auto j=0;j<primes.size()&&i*primes[j]<=n;j++)
        {
            flag[i*primes[j]]=1;
            if(i%primes[j]==0)
                break;
        }
    }
}
vector<int> primes_in_range;
void sieve2(long long l,long long r)
{
    fill(begin(flag),end(flag),0);
    if(l==0)flag[0]=flag[1]=1;
    for(auto i:primes)
    {
        if(i*i>r)   break;
        auto &p=i;
        long long start=max(2*p,((long long)ceil(double(l)/double(p)))*p);
        for(auto j=start;j<=r;j+=i)
        {
            flag[j-l]=1;
        }
    }
    for(long long i=l;i<=r;i++)
    {
        if(!flag[i-l])
        {
            primes_in_range.emplace_back(i);
        }
    }
}

int main()
{
    int q=10;
    sieve(1e5);
    string s;
    long long num;
    while(q--)
    {
        getline(cin,s);
        string ts=s;
        ts=s.substr(s.find_first_of(':')+1);
        stringstream ss(ts);
        if(s[0]!='q')
        {
            ss>>num;
            auto &n=num;
            auto bn = n*(log(n)+log(log(n))-1+
            (log(log(n))-2)/log(n)-
            (powl(log(log(n)),2)-6*log(log(n))+11.847)/(2*log(n)*log(n)));
            bn=max((long double)0,bn);
            if(n<1000)
                cout<<primes[n-1]<<endl;
            else
            {
                // std::chrono::duration<double, std::milli> ms1,ms2,ms3,ms4,ms5;
                // auto t1 = std::chrono::high_resolution_clock::now();
                auto now=pi(bn);
                // auto t2 = std::chrono::high_resolution_clock::now();
                // ms1 = t2 - t1;
                // cout<<ms1.count()<<endl;
                long long i;
                for(i=int(ceil(bn));now<num;i++)
                {
                    if(isPrime(i))
                        now++;
                }
                // auto t3 = std::chrono::high_resolution_clock::now();
                // ms2 = t3 - t2;
                // cout<<ms2.count()<<endl;
                cout<<i-1<<endl;
            }
        }
        else
        {
            ss>>num;
            auto &n=num;
            auto bn = n*(log(n)+log(log(n))-1+
            (log(log(n))-2)/log(n)-
            (powl(log(log(n)),2)-
            6*log(log(n))+11.847)/(2*log(n)*log(n)));
            if(n<1000)
                cout<<"qq_group:"<<primes[n-1]<<'\n';
            else
            {
                auto now=pi(bn);
                long long i;
                for(i=int(ceil(bn));now<num;i++)
                {
                    if(isPrime(i))
                        now++;
                }
                cout<<"qq_group:"<<i-1<<'\n';
            }
        }
    }
}