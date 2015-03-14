/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

1-当只有一条链表时，return lists[0];
2-在依次合并链表

Time Limit Exceeded
时间复杂度为 O (L1.length() +l2.length +++--)
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



/*
利用优先队列

130 / 130 test cases passed.
Status: Accepted
Runtime: 56 ms
*/

class Solution {

public:

    // custom comparator used to compare between two listNode pointers. 
    // note : all pointers to be compared is supposed to be valid pointers.
    struct comparator
    {
        bool operator() ( ListNode* i, ListNode* j)
         {
            return i->val > j->val;
         }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) 
    {

       // shortcut for edge cases. 
       if (lists.size() == 0) return NULL;
       if (lists.size() == 1) return lists[0]; 

       // initialize the maxHeap. 
       priority_queue<ListNode*, std::vector<ListNode*>, comparator> maxHeap;

       // push the head of each of the items in list. 
       for (int i = 0; i< lists.size(); i++)
       {
           if (lists[i]!= NULL) maxHeap.push(lists[i]);
       }

       // shortcut if we failed to find even one valid list. 
       if (maxHeap.size() == 0) return NULL;

       // build the empty node as the return pointer.
       ListNode returnVal = ListNode(-1), *tmp = &returnVal; 

       // loop until the heap is empty. 
       while (maxHeap.size() >0)
       {
           tmp->next = maxHeap.top();
           maxHeap.pop();
           tmp = tmp->next;
           if (tmp->next != NULL && maxHeap.size()!=0)
           {
               maxHeap.push(tmp->next);
           }
       }

       return returnVal.next;
    }
};