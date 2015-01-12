#include <iostream>
#include <cstring>
using namespace std;

void *mymemcpy(void *dest , const  void *src , size_t size )
{
	char *post_src ;
	char *post_dest ;
	if (NULL == dest || NULL == src)
		return NULL;
	post_src = (char *)src + size -1 ;
	post_dest = (char *)dest + size -1 ;
	while(size--)
	{
		*post_dest-- = *post_src--;
	}
return dest ;
}
int main()
{
    const char *src = "waten006";
    char dest[10];

    mymemcpy( dest , src , strlen(src) );
    cout<<dest<<endl;

    return 0;
}

/*
The Answer as follow---->

waten006

Process returned 0 (0x0)   execution time : 0.019 s
Press any key to continue.

*/
