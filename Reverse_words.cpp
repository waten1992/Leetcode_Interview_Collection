#if 1
/*
描述：逆转字符串中的单词 ， 以单词为一个单位；
例子：
-----INPUT : "The Sky is Bule "
-----OUPUT : "Bule is Sky The"

*/
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    void reverseWords(string &s)
    {
        stack<int> word;
        stack<int> sentence;
        int i = 0;

        while(i <= s.size())
        {
            if(i == s.size() || s[i] == ' ') //当s 为空 或者遍历 完成的时候
            {
                if(!sentence.empty() && !word.empty() ) //当sentence word 都不为空的时候  push 空格 ，过滤了最开始为空格 和字符串中间的多个空格
                {
                    sentence.push(' ');
                }
                while(!word.empty()) // word 不为空
                {
                    sentence.push(word.top());//把 word 弹出去到 sentence
                    word.pop(); //每次POP一个
                }
            }
            else
            {
                word.push(s[i]); //压入 word 栈中
            }
            i++;
        };

        s.clear();
        while(!sentence.empty())
        {
            s.push_back(sentence.top());
            sentence.pop(); //pop sentence
        };
    }
};


int main()
{
	string s = "The Sky is Bule ";
	Solution *RevStr = new Solution;
    
    cout<<"The origin string is-->"<<s<<endl;
    RevStr->reverseWords(s);
    cout<<"The change string is-->"<< s <<endl;

    delete RevStr ;
	return 0 ;
}

#endif