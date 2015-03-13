/*
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

600 / 600 test cases passed.
Status: Accepted
Runtime: 12 ms
*/

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        stack<int>ST;
        int i ;
        uint32_t result = 0 ;
        for( i = 0 ; i < 32 ; i++ , n = n>>1)
        {
            int Tmp = n&1; //获取最低位T
            ST.push(Tmp); //压入栈
        }
        for( i = 0 ; i < 32 ; i++)
        {
            int Tmp = ST.top() ;
            ST.pop();
            result |= (Tmp<<i);
        }
        return result;
    }
};