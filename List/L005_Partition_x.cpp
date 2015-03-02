 /*
 思路：
 1-建立一个新链表保存，大于等于X的
 2-建立另一个新链表保存，小于X的
 2-合并2个表新链表；
 ---------------------
 步骤：
 1-分别建立2个链表的头结点 A_dummy B_dummy
 2-大于等于X放在 B_dummy，用尾插法
 3-小于X放在 A_dummy，用尾插法
 4-合并A_dummy B_dummy ，并把尾节点置为NULL
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) 
    {
       if( head == NULL || head->next == NULL)
        	return head ;
        ListNode * A_Cur , *B_Cur, *Tmp;
        ListNode *A_dummy = new ListNode(-1) ;
        ListNode *B_dummy = new ListNode(-1) ;
        A_Cur = A_dummy;
        B_Cur = B_dummy;

        for (Tmp = head; Tmp != NULL; Tmp = Tmp->next) //分离
        {
        	if(Tmp->val >= x)
        	{
        		B_Cur->next =Tmp ;
        		B_Cur = B_Cur->next ;
        	}
        	else //小于X
        	{
        		A_Cur->next =Tmp ;
        		A_Cur = A_Cur->next ;
        	}
        }
        A_Cur->next = B_dummy->next ; //合并链表
        B_Cur->next = NULL; //尾节点置NULL
    return A_dummy->next;
    }
};