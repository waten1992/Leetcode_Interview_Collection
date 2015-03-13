 /*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

 1-先让一个faster指针走n步；
 2-在让faster slower 2个指针一起走，直到faster走到NULL

207 / 207 test cases passed.
Status: Accepted
Runtime: 13 ms
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode dummy(-1);
        ListNode *faster = head , *slower = head ;
        dummy.next = head ;
        while(n--)
        	faster = faster->next;
        while( faster != NULL && faster->next != NULL)
        {
        	faster = faster->next;
        	slower = slower->next;
        }
        if (faster == NULL) //当删除头结点时
        {
        	dummy.next = slower->next;
        	delete slower;
        	return dummy.next;
        }
        else
	    {
	    	ListNode *Tmp = slower->next;
	        slower->next = slower->next->next ;
	        delete Tmp;
	    } 
	return dummy.next;
    }
};