--------------------------
旋转数组，
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
---------------
为什么LEETCODE 总是说Last executed input: [1,2,3], 0
不知道哪里出了问题了
--------------
