#include <stdio.h>
#include <stdlib.h>
/*
    数组的倒置，即是循环右移
*/

int x[]={1,2,3,4,5,6,7};
int rotdist, n;

/* Alg 1: Rotate by reversal */

void reverse(int i, int j)
{   int t;
    while (i < j)
    {
        t = x[i]; x[i] = x[j]; x[j] = t;
        i++;
        j--;
    }
}
void revrot(int rotdist, int n)
{   reverse(0, rotdist-1);//前部倒转
    reverse(rotdist, n-1); //后部倒转
    reverse(0, n-1); //整体倒转
}

int main()
{
    int i , Input ,len = sizeof(x)/sizeof(x[0]);
    printf("Before reverse :\n");
    for(i = 0 ; i < len ; i++ )
        printf(" %d" , x[i]);
    printf("\nPlease Input a spacial number(0~7) --> \n");
    scanf("%d",&Input);

    revrot(Input, 7);

    printf("\nThe spacial number is %d",Input);
    printf("\nThe reverse after : \n");
    for( i =0 ; i< len ; i++ )
            printf(" %d",x[i]);
    return 0;
}
/*
THE ANSWER AS FOLLOWS ------>

Before reverse :
 1 2 3 4 5 6 7
Please Input a spacial number(0~7) -->
3

The spacial number is 3
The reverse after :
 4 5 6 7 1 2 3
Process returned 0 (0x0)   execution time : 2.215 s
Press any key to continue.

*/