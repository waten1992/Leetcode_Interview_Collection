/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?

快慢指针法 

16 / 16 test cases passed.
Status: Accepted
Runtime: 21 ms
*/


class Solution {
public:
    bool hasCycle(ListNode *head)
    {
    	ListNode *faster = head, *slower = head ;
    	while(faster && faster->next)
    	{
    		faster = faster->next->next;
    		slower = slower->next;

    		if(faster == slower)
    			return true ;	
    	}

    	return false ;
    }
};