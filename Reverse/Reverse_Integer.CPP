/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Update (2014-11-10):
Test cases had been added to test the overflow behavior.

1032 / 1032 test cases passed.
Status: Accepted
Runtime: 20 ms

*/

class Solution {
public:
    int reverse(int x) 
    {
        int Tmp = 0 ;
        for( ; x ; x = x/10) //每次左移一位
        {
        	if(Tmp > INT_MAX /10 || Tmp < INT_MIN /10) //判断是否溢出
            	return 0;    
            Tmp = Tmp*10 + x%10; 
        }
        return Tmp ;
    }
};

/*
优化之后：
1032 / 1032 test cases passed.
Status: Accepted
Runtime: 16 ms
*/
class Solution {
public:
    int reverse(int x) 
    {
        int Tmp = 0 ;
        const long int Max = INT_MAX /10;
        const long int Min = INT_MIN /10;
        for(int i = x ; x ; x = x/10)
        {
            if(Tmp > Max || Tmp < Min ) //溢出
                return 0;    
            Tmp = Tmp*10 + x%10;
        }
            
        return Tmp ;
    }
};