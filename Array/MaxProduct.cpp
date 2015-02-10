/*
描述：给定一个数组，编写一个函数求相邻的元素乘积最大值

解决方案：分为两步分扫描数组，用一个临时变量保存当前最大值；
        1-前面部分扫描相乘保存为frontProduct；
        2-后面部分扫描相乘保存为backProduct;
        3-判断frontProduct 、backProduct 是否为零？
                -是 则置为1；
                -否 还是原样；
        4-返回到1 ，一直到扫描为止；
时间O(N) 空间O(1)；
*/
#include <iostream>
#include <cmath>
using namespace std;
const int INT_MIN = -99999;//初始值
class Solution
{
public:
    int maxProduct(int A[], int n)
    {
        int frontProduct = 1;
        int backProduct = 1;
        int answer = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            frontProduct *=  A[i];
            backProduct *= A[n - i - 1];
            answer = max(answer,max(frontProduct,backProduct)); //获取当前最大值
            frontProduct = frontProduct == 0 ? 1 : frontProduct;//扫描前部
            backProduct = backProduct == 0 ? 1 : backProduct;//扫描后部分
        }
        return answer;
    }
};

int main()
{
    Solution A ;
    int a[] = {-9,5,12,0,6};
    cout<<A.maxProduct(a,sizeof(a)/sizeof(a[0]));
    return 0 ;
}
/*
The answer as follow--->
60
Process returned 0 (0x0)   execution time : 0.023 s
Press any key to continue.
*/