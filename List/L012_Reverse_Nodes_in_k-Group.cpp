/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

-----------------------------------------------
1-每次向前走K步，reverse 这个K个节点；

81 / 81 test cases passed.
Status: Accepted
Runtime: 32 ms
*/



class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) 
    {
    	if(head == NULL || head->next == NULL || k < 2) //空 ，或者 1个元素， K = 1
    	    return head;
    	ListNode dummy(-1);
    	dummy.next = head ;
        for(ListNode *pre = &dummy ,*cur = head ; cur ; cur = pre->next)
        {	
        	for (int i = 1; i < k && cur; i++)   //从1 开始 本来cur = head 
    	    	cur = cur->next;
    		if(cur == NULL)  //不足K个
    	    	break; 
    	    pre = Reverse( pre , pre->next , cur );
        }
    return dummy.next;
    }
    ListNode * Reverse(ListNode *pre , ListNode * begin , ListNode *end)
    {
    	ListNode *Next_end = end->next; //保存后面的节点
    	for(ListNode *P = begin , *cur = begin->next , *Next = cur->next ; cur != Next_end ; 
    		P = cur , cur = Next ,Next = Next ? Next->next :NULL)
    	{
    		cur->next = P ;
    	}
    	pre->next = end;
    	begin->next = Next_end; //逆转最后的元素
    return begin; //返回最的那个元素
    }
};