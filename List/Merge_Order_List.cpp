/*
描述：合并2个有序链表的面向过程程序；
*/
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void Head_Insert(ListNode *Head ,int item)
{
    ListNode *Tmp ;
    Tmp = new ListNode(item);
    Tmp->next = Head->next;
    Head->next =  Tmp ;
#if 1 //for test !
    cout<<Tmp->val<<endl;
#endif // 0
}
void Display_List(ListNode *Head)
{
    ListNode *Tmp ;
    Tmp = Head->next ;
    while(Tmp != NULL)
    {
        cout<<Tmp->val<<"->";
        Tmp = Tmp->next;
    }
    cout<<"NULL"<<endl;
}
ListNode * Merge_list(ListNode *s1 , ListNode *s2)
{
    ListNode *Merge , *Tmp ,*Rear;
    Merge = new ListNode(-1);
    Rear = Merge ;
    for ( ; s1 != NULL && s2 != NULL; Rear = Rear->next ,Rear->next = NULL )
    {
        if(s1->val <= s2->val)
        {
            Tmp = s1->next ; //保留下一个元素；
            Rear->next = s1 ; //尾插法
            s1 = Tmp;
        }
        else
        {
            Tmp = s2->next ; //保留下一个元素；
            Rear->next = s2 ;
            s2 = Tmp;
        }
    }
    if(s1 != NULL) //剩下的由新的链表未节点指向
        Rear->next = s1;
    if(s2 != NULL)
        Rear->next = s2 ;
    return Merge;
}

int main()
{
    ListNode * S1 = new ListNode(-1);
    ListNode * S2 = new ListNode(-1);
    int a[] = {3,2,1};
    int b[] = {9,8,5,2};
    for(int i = 0 ; i < sizeof(a)/sizeof(a[0]) ; i++ ) //用头插法建立有序链表
        Head_Insert(S1,a[i]);
    Display_List(S1);

    for(int i = 0 ; i < sizeof(b)/sizeof(b[0]) ; i++ )
        Head_Insert(S2,b[i]);
    Display_List(S2);
    ListNode *Tmp ;
    Tmp = Merge_list(S1->next,S2->next);
    Display_List(Tmp);
    return 0;
}
/*
The answer as follow ---->
3
2
1
1->2->3->NULL
9
8
5
2
2->5->8->9->NULL
1->2->2->3->5->8->9->NULL

Process returned 0 (0x0)   execution time : 0.033 s
Press any key to continue.
*/

