/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

208 / 208 test cases passed.
Status: Accepted
Runtime: 18 ms
*/

/*
    1-判断2条链表是否为空，是，返回另一条/ 
    2-建立头结点，节点2条合并的链表
    3-返回链表
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(-1);
        if(l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        ListNode *pre ;
        
        for(pre = &dummy ; l1 != NULL || l2 != NULL ; pre = pre->next)
        {
            const int a = l1==NULL ?INT_MAX :l1->val;
            const int b = l2==NULL ?INT_MAX :l2->val;
            if(a < b)
            {
                pre->next = l1 ;
                l1 = l1->next;
            }
            else
            {
                pre->next = l2 ;
                l2 = l2->next;
            }
        }
        pre->next = NULL ;
        return dummy.next;
    }
};