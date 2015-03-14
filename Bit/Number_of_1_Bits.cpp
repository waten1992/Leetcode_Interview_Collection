/*
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.

600 / 600 test cases passed.
Status: Accepted
Runtime: 12 ms
*/

class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
        const int size = 32 ;
        int result = 0 ;
        for(int i = 0 ; i < size ; i++ , n = n>>1 ) //每次向右移1位
    	{
    		if(n&1) //取最低位
				result = result + 1;
    	}
    return result;
    }	
};