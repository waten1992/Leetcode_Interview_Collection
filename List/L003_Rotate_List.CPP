/*
描述：一个链表循环向右移动K位，返回头结点，请编写一个函数实现；
例如：
        原始链表：1->2->3->4->NULL;
        条件：向右循环移动K = 2 位;
        结果：3->4->1->2->NULL;
解决方案：
        1-计算链表长度len;
        2-判断K 和链表长度的关系？
        当K大于链表的长度时，K = (K)%Len;
        当等于链表的长度时或者等于0时，链表不移动；
        当K小于链表长度时；
            1-申请faster , slower分别 指向head ；
            2-让faster 先走K步；
            3-把faster , slower按照相同的step = 1 走；
            4-直到faster->next == NULL 为止；
            5-把slower->next插入到前面;
                faster->next = head->next；//默认有头结点 ，形成循环链表
                head->next = slower->next ; //找到首节点
                slower->next = NULL; //尾节点置NULL，断开循环链表
*/
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
protected:
    ListNode *head = new ListNode(-1);
public:

    ListNode *Rotate_Right( int k)
    {
        ListNode *faster , *slower ;
        faster = head;
        slower = head;
        int len = 0 ;
        if (head == NULL)
            return head;
        while(faster->next != NULL) //统计链表的长度
        {
            faster = faster->next ;
            len++;
        }
        faster = head; //重置
        if(len == k || k == 0)  //输入数为零和链表长度都返回头结点
            return head ;
        else
        {
            k = k%len ; //计算移动多少步
            while(k--) //先移动K步
                faster = faster->next ;
            for(; faster->next != NULL  ; faster = faster->next , slower = slower->next  ) 
                ;//当faster->next == NULL时 ，faster就指向了最后的节点
            faster->next = head->next ; //形成环
            head->next = slower->next ;//找到移动后的首节点
            slower->next = NULL ;//把尾节点置为NULL,断开循环链表
        }
        return head;
    }

    void Tail_Insert(int item) //尾插法
    {
        ListNode * Rear , * Current ;
        Rear = head;
        while (Rear->next != NULL) //找到最后的
        {
            Rear = Rear->next;
        }
        Current = new ListNode(item); //新建节点
        Current->next = Rear->next;
        Rear->next = Current ;
        Rear = Rear->next;
        Rear->next = NULL ;
#if 0 //for test !
        cout<<Current->data<<endl;
#endif
    }

    void Display_List() //有头结点的输出程序
    {
        ListNode *Tmp ;
        Tmp = head->next ;
        while(Tmp != NULL)
        {
            cout<<Tmp->val<<"->";
            Tmp = Tmp->next;
        }
        cout<<"NULL"<<endl;
    }
};
int main()
{
    Solution A ;
    for(int i = 0 ; i < 5 ; i++)
        A.Tail_Insert(i);
    cout<<"The original list---->"<<endl;
    A.Display_List();
    cout<<"Rotata Right list ---->"<<endl;
    A.Rotate_Right(2);
    A.Display_List();
    return 0 ;
}
/*
The answer as follow--->

The original list---->
0->1->2->3->4->NULL
Rotata Right list ---->
3->4->0->1->2->NULL

Process returned 0 (0x0)   execution time : 0.078 s
Press any key to continue.
*/
