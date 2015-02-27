--------------------------
旋转数组，Reverse(int x[] ,int i, int j) 是包括边界的[left , right] 

---------------------------

class Solution {
public:
    void rotate(int nums[], int n, int k) 
    {   if(n == 0 || k == 0 || k%n == 0)
            ;
        else
        {
            Reverse(nums,0,n-k-1);//前半部分
            Reverse(nums,n-k ,n-1);//后半部分
            Reverse(nums,0,n-1);//整体旋转
        }
    }
    void Reverse(int x[] ,int i, int j)
    {    int t;
         while (i < j)
         {
            t = x[i]; x[i] = x[j]; x[j] = t;
            i++;
            j--;
         }
    }
};
/*---------------
为什么LEETCODE 总是说Last executed input: [1,2,3], 0
不知道哪里出了问题了
----
上面的程序是可以运行的，但是Leetcode 说运行不能通过！
--------------
*/
/*-----------------------------------------
直接调用C++自带的void reverse( BidirIt first, BidirIt last )
Reverses the order of the elements in the range [first,last)
LEETCODE AC- Runtime: 27 ms
*/  
class Solution {
public:
    void rotate(int nums[], int n, int k) 
    {   
        k = k%n ;
        if(k==0 || n==0)
            return ;
        else
        {
            reverse(nums, nums+n-k);//前半部分
            reverse(nums+n-k ,nums+n);//后半部分
            reverse(nums,nums+n);//整体旋转
        }
    }
   
};