/*
描述：对一个链表进行排序，要求时间复杂度O(Nlog(N)) 空间复杂度O(1)；

解决方案：归并排序原理，先拆分，在比较大小，合并成有序链表
1-递归分离链表
2-比较大小在合并
函数：
       1-分离函数ListNode * splice(ListNode *Node)
       2-合并函数ListNode * Merge_list(ListNode *s1 , ListNode *s2)
       3-排序函数ListNode *sortList(ListNode *head)
*/
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void Head_Insert(ListNode *Head ,int item) //头插法
{
    ListNode *Tmp ;
    Tmp = new ListNode(item);
    Tmp->next = Head->next;
    Head->next =  Tmp ;
#if 1 //for test !
    cout<<Tmp->val<<endl;
#endif // 0
}

ListNode * splice(ListNode *Node) //把链表从中间分开
{
    ListNode *Faster , *Slower ,*new_list;
    Slower = Node;
    Faster = Slower->next; //比慢指针快一步

    while(Faster != NULL && Faster->next != NULL) //快指针每次走两步， 慢的每次走一步
    {
        Faster = Faster->next->next ;
        Slower = Slower->next ;
    }
    new_list =  Slower->next  ; //新的链表直接连接到后面的元素
    Slower->next = NULL ; //断掉前面部分的链表
    cout<<"This is slower_val--->"<<Slower->val<<endl; //for test !
    return new_list;
}

void Display_List(ListNode *Head) //输出函数
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
ListNode * Merge_list(ListNode *s1 , ListNode *s2) //合并函数
{
    ListNode *Merge , *Tmp ,*Rear;
    Merge = new ListNode(-1);
    Rear = Merge ;
    while ( s1 != NULL && s2 != NULL ) //直到有一个链表为空为止
    {
        //  cout<<"s1-->"<<s1->val<<"  s2->"<<s2->val<<endl;
        if(s1->val <= s2->val)
        {
            Tmp = s1->next ; //保留下一个元素；
            Rear->next = s1 ;//尾插法
            s1 = Tmp; //指向下一个元素
        }
        else
        {
            Tmp = s2->next ; //保留下一个元素；
            Rear->next = s2 ; //尾插法
            s2 = Tmp; //指向下一个元素
        }
        Rear = Rear->next;
        Rear->next = NULL; //保持Rear指向新链表的尾节点
    }
    if(s1 != NULL)  //把剩余的链表加入到新链表的尾指针
        Rear->next = s1 ;
    if(s2 != NULL)
        Rear->next = s2 ;
    //return Merge->next; //因为创建了头结点，这样会产生内存泄漏；
    Tmp = Merge->next;
    return Tmp;
}

ListNode *sortList(ListNode *head)
{
    ListNode *new_head ;
    if(head == NULL || head->next == NULL) //当链表为空 或者 只有一个元素时返回
        return head ;
    else
    {
        new_head = splice(head); //先拆链表
        return Merge_list( sortList(head) , sortList(new_head)); //在合并两个拍好序的链表
    }

}
int main()
{
    ListNode * S2 = new ListNode(-99);
    int b[] = {9,11,5,2};
    for(int i = 0 ; i < sizeof(b)/sizeof(b[0]) ; i++ )
        Head_Insert(S2,b[i]);
    cout<<"----The original array --->"<<endl;
    Display_List(S2);

    ListNode *Tmp ;
    Tmp = sortList(S2);
    cout<<"----After Sort array --->"<<endl;
    Display_List(Tmp);

    return 0;
}
/*
The answer as follow------->
9
11
5
2
----The original array --->
2->5->11->9->NULL
This is slower_val--->5
This is slower_val--->11
This is slower_val--->2
This is slower_val--->-99
----After Sort array --->
2->5->9->11->NULL

Process returned 0 (0x0)   execution time : 0.031 s
Press any key to continue.
*/

