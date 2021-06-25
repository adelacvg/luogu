#include<bits/stdc++.h>
using namespace std;
/**
**  num：代表题目中的n ，target：需要统计的数
**/
int getCount(int num, int target) 
{
    //表示当前的位数（个位、十位。。。）
    int base = 1;
    //结果
    int sum = 0;
    int n = num;

    while (n != 0) {
        //以123为例，当1在个位时sum+= 1*12,并没有加13是因为我们还没有判断当前位的数cur跟要求的数的关系。
        sum += base * (n / 10);
        //cur当前位的数如123中个位的数是3
        int cur = n % 10;

        if (cur == target) {
        //当cur等于target,比如123，处于十位时求2出现的次数，因为只能有120~123四种情况所以，对应sum += num % base + 1
            sum += num % base + 1;
        } else if (cur > target) {
            //当cur大于target,比如123，处于个位时求1出现的次数，需要加上12开头的情况，所以sum += 1 * base。
            sum += 1 * base;
        }else if(cur<target){
            //当cur小于target,比如123，处于个位时求5出现的次数，这是125是不成立的。
        }

        base *= 10;
        n = n / 10;
    }
    return sum;
}
int getCount0(int num) 
{
    int base = 1;
    int sum = 0;
    int n = num;

    while (n != 0) 
    {
        //区别在于这一行代码，减掉了1
        sum += base * (n / 10 - 1);

        int cur = n % 10;
        if (cur == 0) 
        {
            sum += num % base + 1;
        } else if (cur > 0) 
        {
            sum += base;
        }

        base *= 10;
        n = n / 10;
    }
    return sum;
}

int main()
{
    int m,n;
    cin>>m>>n;
    for(int i=0;i<10;i++)
    {
        if(i==0)
        {
            cout<<getCount0(n)-getCount0(m-1)<<" ";
        }
        else
        {
            cout<<getCount(n,i)-getCount(m-1,i)<<" ";
        }
        
    }
}