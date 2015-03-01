/*
Leetcode Linklist 默认是没有头结点
*/

#include <iostream>
using namespace std;

struct ListNodes
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    Solution():Head(nullptr) {}
    ~Solution()
    {
        Destroy(Head);
    }
    void Tail_Insert(int item)
    {
        Tail_Insert(Head ,item);
    }
    void Display_List()
    {
        Display_List(Head);
    }
protected:
    ListNode * Head;
private:
    void Tail_Insert(ListNode *&Head ,int item) //尾插法
    {
        ListNode * Rear , * Current ;
        Rear = Head ;
        if (Head == nullptr) //当为空节点
        {
            Current = new ListNode(item); //新建节点
            Head = Current;
        }
        else
        {
            while (Rear->next != NULL) //找到最后的
            {
                Rear = Rear->next;
            }

            Current = new ListNode(item); //新建节点
            Current->next = Rear->next;
            Rear->next = Current ;
            Rear = Rear->next;
            Rear->next = NULL ;
        }

#if 0 //for test !
        cout<<Current->val<<endl;
#endif
    }
    void Destroy(ListNode *&Head)
    {
        ListNode *Tmp ;
        while(Head != nullptr)
        {
            Tmp = Head->next ;
            delete Head ;
            Head = Tmp ;
        }
    }
    void Display_List(ListNode *Head)
    {
        ListNode *Tmp ;
        Tmp = Head ;
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
    int a[] = {1,2,3,4,5};
    Solution S;
    for(int i= 0 ; i < sizeof(a)/sizeof(a[0]) ; i++ )
        S.Tail_Insert(a[i]);
    S.Display_List();
    return 0;
}

/*
The answer as follow-->

1->2->3->4->5->NULL

Process returned 0 (0x0)   execution time : 0.020 s
Press any key to continue.
*/
