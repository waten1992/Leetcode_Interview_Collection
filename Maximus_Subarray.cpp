
/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

201 / 201 test cases passed.
Status: Accepted
Runtime: 17 ms
*/
class Solution {
public:
    int maxSubArray(int A[], int n)
    {
        int sum = INT_MIN , cur_sum = 0 ; 
        for(int i = 0 ; i < n  ; i++)
        {
            cur_sum = max(A[i], cur_sum +A[i]) ; //当前最大的值
            sum = max(sum , cur_sum) ;
        }
        return sum ;
    }
};