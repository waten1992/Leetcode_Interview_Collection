#include <iostream>
using namespace std;

/*
描述：Determine whether an integer is a palindrome. Do this without extra space

方法：取第一个数 和最后一个数 相比 ， 2 with n-2 , 3 with n-3 -------
------如果相等，则是回文数，否者不是！！！
*/
#if 1
class Solution
{
public:

    bool IsPalindorme(int x)
    {
        if (x < 0)
            return false;
        int d = 1;
        while( x/d >= 10)
            d *= 10 ; //获取最高位的值
        while( x > 0 )
        {
            int Front = x / d ; //获取最高位的值
            int Rear  = x % 10 ; //获取最底位的值
            if ( Front != Rear )
                return false ;
            x = x % d / 10 ; //除去 目前的 最高和最低 位
            d /= 100 ; // 每次都除去最高和最低  总共是2位 所以呢 要除以100
        }
        return true ;
    }
};

int main()
{
    Solution A ;
    int i ,len;
    string value ;
    int a[] = { 123 , 121 , 1001 , 12721 , 1234554321}; //测试数组
    len = sizeof(a)/sizeof(a[0]);
    while (i<len)
    {
        if( 1 == A.IsPalindorme(a[i]) )
            value = "YES";
        else
            value = "NO" ;
        cout<<"The Origins is-->"<<a[i]<<" \t \t The Answer----->"<<value<<endl;
        i++;
    }
    return 0;
}

#endif
/*
The Answer as follows --->

The Origins is-->123             The Answer----->NO
The Origins is-->121             The Answer----->YES
The Origins is-->1001            The Answer----->YES
The Origins is-->12721           The Answer----->YES
The Origins is-->1234554321              The Answer----->YES

Process returned 0 (0x0)   execution time : 0.031 s
Press any key to continue.

*/