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