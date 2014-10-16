#include <iostream>
using namespace std;
#if 1
/*
Reverse Integer
    EXAMPLE :
    ---------INPUT : 123  OUTPUT : 321
    ---------INPUT : -123 OUTPUT : -321
    CASE 1: INPUT 1000 HOW TO SOLVE IT?
    -------OUTPUT : 1 ;
    CASE 2: INPUT 2^31+100 STACKOVERFOWER; HOW TO SOLVE IT ?
*/
class Solution
{
public:
    int Reverse(int x) // 申请一个临时变量，存储 逆转后的值
    {
        int tmp = 0;
        for( ; x ; x /= 10 ) //原来的值，每次不断的右移一位 ，直到为零；
            tmp = tmp*10 + x%10; //临时变量 不断的左移一位， 外加余值；
        return tmp;
    }
};

int main()
{
    int value , item ,len ,i=0;
    int a[] ={0,1019,123,-321,100};
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

Process returned 0 (0x0)   execution time : 0.062 s
Press any key to continue.

*/