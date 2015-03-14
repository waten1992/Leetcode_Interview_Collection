/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

1-当只有一条链表时，return lists[0];
2-在依次合并链表

Time Limit Exceeded

*/ 
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if(lists.size() == 0)
        	return NULL;
        ListNode *Pre = lists[0]; //第一条链表
        for(int i = 1 ; i < lists.size() ; i++)
        	Pre = Merge_Two_List(Pre , lists[i]); //每条链表和第一条合并
    	return Pre;
    }

    ListNode * Merge_Two_List(ListNode *L1 , ListNode *L2)
    {
    	ListNode dummy(-1);
    	
    	for(ListNode * pre = &dummy ; L1 != NULL || L2 != NULL ; pre = pre->next )
    	{
    		const int a = L1 != NULL? L1->val :INT_MAX ;
    		const int b = L2 != NULL? L2->val :INT_MAX ;
    		if (a <= b)
    		{
    			pre->next = L1 ;
    			L1 = L1->next ;
    		}
    		else 
    		{
    			pre->next = L2 ;
    			L2 = L2->next ;
    		}
    	}
    return dummy.next;
    }
};