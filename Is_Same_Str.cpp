#include <iostream>
#include <string>
using namespace std;

/*
描述： 给出2个字符串str，其中一个str是否能通过移动而与另一个str相等,
       编写一个函数判断；（假定是ACSII）

解题步骤：
        1-先判定两个str的长度是否相等；若是则继续，否者返回0
        2-建立一个Identify[256]统计str1中出现的频率；
        3-看str2中出现的频率是否相等；若是则返回1，否者返回0；
*/
int Is_Same_Str(string Str1 , string Str2)
{
    char Identify[256] = {0};
    int Index = 0 ;
    if (Str1.length() != Str2.length() )
        return 0;
    for( Index ; Str1[Index] != '\0'; Index++)
    {
        Identify[Str1[Index]]++; //统计str1的字符的频率
    }

    for(Index = 0 ; Str2[Index] != '\0' ; Index++)
    {
        if(Identify[Str2[Index]] != 0) //统计str2是否和str1是相同的
            Identify[Str2[Index]]--;
        else
            return 0 ;
    }
    return 1;
}

int main()
{
    string Str1("waten!") , Str2("waten");
    cout << Is_Same_Str(Str1,Str2)<< endl;
    cout<<"----------Change -------------"<<endl;
    Str1 = "waten";
    Str2 = "waten";
    cout << Is_Same_Str(Str1,Str2)<< endl;
    return 0;
}

/*
The Answer as follow ----->

0
----------Change -------------
1

Process returned 0 (0x0)   execution time : 0.020 s
Press any key to continue.

*/
