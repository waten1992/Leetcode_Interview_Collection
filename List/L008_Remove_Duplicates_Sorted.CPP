/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
----------------------------------------------

Runtime: 22 ms
*/
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        	return head ;
      	ListNode *pre = head , *post = head->next , *Tmp;
      	while(post)
        {
        	if(pre->val == post->val)
        	{
        	    pre->next = post->next;
        	    delete post;
        	    post = pre->next;
        	}
        	else
        	{
        		pre = pre->next;
        		post = post->next;
        	}
        }
        return head;
    }
};