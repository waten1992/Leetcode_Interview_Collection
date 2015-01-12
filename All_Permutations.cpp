#if 1
#include <stdio.h>
#include <string.h>
static int Record = 0;
void Swap(char *a ,char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}
//递归全排列，start 为全排列开始的下标， length 为str数组的长度
void AllRange(char* str,int start,int length)
{

	if(start == length-1)
	{
		Record++ ;
		printf("THIS IS %d-->%s\n",Record,str);
	}
	else
	{
		for(int i=start;i<=length-1;i++)
		{	//从下标为start的数开始，分别与它后面的数字交换
			Swap( &str[start] , &str[i] ) ; //和后面的字符交换

			AllRange( str , start+1 , length ) ;

			Swap( &str[start] , &str[i] ) ; //恢复之前的状态
		}
	}
}
void Permutation(char* str)
{
	if(str == NULL)
		return;
	AllRange(str,0,strlen(str));
}
int main()
{
	char str[] = "abc";

	Permutation(str);
	return 0;
}


#endif


/*
The Answer as follows-->

THIS IS 1-->abc
THIS IS 2-->acb
THIS IS 3-->bac
THIS IS 4-->bca
THIS IS 5-->cba
THIS IS 6-->cab

Process returned 0 (0x0)   execution time : 0.030 s
Press any key to continue.

*/

