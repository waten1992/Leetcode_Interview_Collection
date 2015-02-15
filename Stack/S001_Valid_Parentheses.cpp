/*
描述：
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

*/


class Solution {
public:
    bool isValid(string s)
    {
        stack<char> ST; //保存 "(" "["
        int i = 0;
        while(s[i]) //遍历string
        {
            if(s[i]=='(' || s[i]=='[' || s[i] == '{')
                ST.push(s[i]);
            else if(s[i]== ')')
            {
                char Tmp ;
                if(ST.empty()) //如果栈是空栈
                    return false;
                Tmp = ST.top();
                if(Tmp == '(')
                    ST.pop();
                else 
                    return false ;
            }
            else if(s[i]==']')
            {
                char Tmp1 ;
                if(ST.empty()) //如果栈是空栈
                    return false;
                Tmp1 = ST.top();
                if(Tmp1 == '[')
                    ST.pop();
                else 
                    return false ;
            }
            else if(s[i] == '}')
            {
                char Tmp2 ;
                if(ST.empty()) //如果栈是空栈
                    return false;
                Tmp2 = ST.top();
                if(Tmp2 == '{')
                    ST.pop();
                else 
                    return false ;
            }
            else
                ;
            i++;
        }
       if(ST.empty())
            return true ;
       else
            return false;     
    }
};