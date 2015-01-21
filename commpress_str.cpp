#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string commpress(string str)
{
    string new_str("") , Current ; //new_str-->是存储压缩字符； Current-->记录当前字符
    int local_count = 1 , Size = 0; //local_count -->记录被压缩的字符的个数
    for(int i = 0 ; str[i] != '\0'  ; i++ )//Size 记录压缩后的长度
    {
        Current = str[i];
        if (str[i] == str[i+1])
        {
            if (local_count == 1 ) //某个字符和后面的字符相等，就是第一次就添加；
                 new_str.append(Current);
            local_count++;
        }
        else
        {
            if(local_count == 1) //当前的和后面的不相同
                new_str.append(Current);
            else
            {
                ostringstream ss;
                ss << local_count; //int 转 string ,本来Current++11 可以用to_string(int)，但是我的编译器不能用
                new_str = new_str+ss.str(); //添加数字
                Size++ ;
            }
        local_count = 1 ; //每次，遇到不相同的字符 置1
        }
    }

    if (str.length() == Size)
        return str;
    else
        return new_str;
}

int main()
{
    int i ;
    string str[4] = {"oouuha" ,"waten","tataa","www.orderbf.com"};
    for( i = 0 ; i < 4 ; i++) //输出未压缩的前的字符串
        cout<<"This is original string-->"<<str[i]<<endl;
    cout<<"---------commpress after--------------->"<<endl;
    for(i = 0 ; i < 4 ; i++)
        cout<<"This is commpress after string-->"<<commpress(str[i])<<endl;
return true ;
}
/*
The Answer as follow --->

This is original string-->oouuha
This is original string-->waten
This is original string-->tataa
This is original string-->www.orderbf.com
---------commpress after--------------->
This is commpress after string-->o2u2ha
This is commpress after string-->waten
This is commpress after string-->tata2
This is commpress after string-->w3.orderbf.com

Process returned 1 (0x1)   execution time : 0.020 s
Press any key to continue.

*/