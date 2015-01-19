
#if 1
#include <iostream>
using namespace std;

/*
描述：确定一个str中的字符是否都是不同的；(假定ASCII)
解法：hash
        1-清零，建立Identify[256] ={0};
        2-遍历str,Identify[str[Index]] 和 1 的比较，
        3-若相等，则返回false , 若不相等，则Identify[str[Index]] =1 置1；
*/

bool Identify_str(char *str)
{
    char Identify[256] = {0};
    for(int Index = 0 ; str[Index] != '\0' ; Index++)
    {
        if ( Identify[str[Index]] == 1 )
            return false ;
        else
        {
            Identify[str[Index]] = 1 ;
        }
    }

return true;
}

int main()
{
    char *str= "waten006";

    cout<<"The result as -->"<<Identify_str(str)<<endl;
return true ;
}

/*
The Answer as follow ---->

The result as -->0

Process returned 1 (0x1)   execution time : 0.080 s
Press any key to continue.

*/

#endif // 1