#include <iostream>
const int INT_MAX = (1<<31) -1 ;
const int INT_MIN = (1<<31) ;
using namespace std;

/*
Reverse Integer
    EXAMPLE :
    ---------INPUT : 123  OUTPUT : 321
    ---------INPUT : -123 OUTPUT : -321
    CASE 1: INPUT 1000 HOW TO SOLVE IT?
    -------OUTPUT : 1 ;
    CASE 2: INPUT 2^31+100 STACKOVERFOWER; HOW TO SOLVE IT ?
    ------OUTPUT : 0 ;
*/
class Solution
{
public:
    int Reverse(int x) // 申请一个临时变量，存储 逆转后的值
    {
        int Tmp = 0 ;
        for(; x ; x = x/10)//原来的值，每次不断的右移一位 ，直到为零；
        {
            if(Tmp > INT_MAX /10 || Tmp < INT_MIN /10 ) //溢出
                return 0;
            Tmp = Tmp*10 + x%10;//临时变量 不断的左移一位， 外加余值；
        }

        return Tmp ;
    }
};

int main()
{
    int value , item ,len ,i=0;
   long int a[] ={0,1019,123,-321,100,2147483647 ,-2147483647};
    Solution A ;
    len = sizeof(a)/sizeof(a[0]);
    while(i < len)
    {
        cout<<"Origin item is-->"<<a[i]<<endl ;
        value = A.Reverse(a[i]) ;
        cout<<"The Answers----->"<<value<< endl ;
        i++;
    }
    return 0 ;
}
/*
THE ANSWER AS FOLLOWS------->

Origin item is-->0
The Answers----->0
Origin item is-->1019
The Answers----->9101
Origin item is-->123
The Answers----->321
Origin item is-->-321
The Answers----->-123
Origin item is-->100
The Answers----->1
Origin item is-->2147483647
The Answers----->0
Origin item is-->-2147483647
The Answers----->0

Process returned 0 (0x0)   execution time : 0.028 s
Press any key to continue.

*/
