#include <iostream>
using namespace std;

/*
描述： 写一个函数， 将整数A -> B ，需要改变多少了位；

方法： 异或 C= A^B 得到是两个数不相同的位 ；所以之需要统计 C 中位为1 的数量就可以了

*/
int  BitSwapReqired(int a  , int b )
{
    int Count  = 0 ;
    for (int c = a^b ; c != 0 ; c = c&(c-1) )  // c&(c-1) ----> 计算C 经过多少次变成零
    {
        Count++ ;
    }
    
    return Count;
}
#if 0 //方法二 ： 右移
int BitSwapReqired(int a , int b )
{
    int Count  = 0 ;
    for (int c = a^b ; c != 0 ; c = c>>1 )  // C 不断的右移 ；
    {
        Count += c&1 ; //统计位为 1 的数量 
    }
    
    return Count;
}
#endif // 0

int main()
{
    int value ;
    value = BitSwapReqired(3,4);
    cout<<"The Answer--->"<<value<<endl;
    return 0 ;
}
