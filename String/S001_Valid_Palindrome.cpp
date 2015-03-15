/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
-------------------------
1-统一转成小写调用STL transform()
2-第一个和最后一个比较相同继续，否者return false

475 / 475 test cases passed.
Status: Accepted
Runtime: 18 ms

*/

class Solution
{
public:
    bool isPalindrome(string s)
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);  //都转化成小写
        auto left = s.begin(), right = prev(s.end()); // std::prevGet iterator to previous element
        while (left < right)
        {
            if (!::isalnum(*left)) ++left;
            else if (!::isalnum(*right)) --right;
            else if (*left != *right) return false;
            else
            {
                left++, right--;
            }
        }
        return true;
    }
};