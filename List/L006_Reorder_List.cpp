/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
------------------------

思路：
1-用快慢指针法，把slower指向后面的链表reverse.用B指向后面的链表
2-合并两个链表
*/
class Solution {
public:
    void reorderList(ListNode *head)
    {
        ListNode *slower , *faster ;
   		if(head == NULL || head->next == NULL)//处理当链表为空或者只有一个情况下     
   			return head;
        for( slower = head , faster = slower->next->next ; faster != NULL && faster->next != NULL ;slower = slower->next)
        	 faster = faster->next->next;
        if(faster != NULL) //处理奇数情况
        	slower = slower->next;
        ListNode *A , *B;
        B = slower->next ; //新链表
        slower->next = NULL ; //分离链表
        /*
			再次使用faster 和 slower ；
        */
		ListNode dummy(-1);
		slower = B;//指向新链表的首节点
		B = &dummy;
		B->next = slower ;//完成头节点形成；
		faster =  slower->next;
		/*-------逆转---*/
    }
};


/*
 1-快慢指针分离链表；
 2-逆转后面的链表；
 3-合并前面的2个链表

13 / 13 test cases passed.
Status: Accepted
Runtime: 74 ms
 */
class Solution {
public:
    void reorderList(ListNode *head) 
    {
        if (head == NULL || head->next == NULL)
            return ;
        ListNode *faster = head , *slower = head ,*pre ;
        while(faster != NULL && faster->next != NULL)
        {
            pre = slower;
            faster = faster->next->next;
            slower = slower->next;
        }    
       
        pre->next = NULL; //断开
        
        slower = reverse(slower);
        
        ListNode  *cur = head;
        while(cur->next)
        {
            ListNode *Tmp = cur->next ;
            cur->next = slower ;
            slower = slower->next;
            cur->next->next =Tmp ;
            cur = Tmp ;
        }
        cur->next = slower;
        
    }
    
    ListNode* reverse(ListNode *head) 
    {
        if (head == NULL || head->next == NULL) return head;
        ListNode *prev = head;
        for (ListNode *curr = head->next, *next = curr->next; curr;
            prev = curr, curr = next, next = next ? next->next : NULL) 
        {
              curr->next = prev;
        }
        head->next = NULL;
    return prev;
    }
};