/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
--------------------------------
1-建立头结点 dummy ;
2-前面的当前的节点不断的和后面的节点比较，直到不相等时，才移动。相等则删除

166 / 166 test cases passed.
Status: Accepted
Runtime: 19 ms
*/

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) 
    {
       	if(head == NULL || head->next == NULL)
       		return head ;
        ListNode dummy(head->val - 1); //和后面的节点不同即可
        dummy.next = head ;
        ListNode *cur = head , *pre = &dummy ;
        if(head)
        {
			while(cur && cur->next)
			{
				if(cur->val != cur->next->val)
				{
					pre = pre->next ;
					cur = cur->next ;
				}
				else
				{
					while((cur->next) && (cur->val == cur->next->val))
						cur = cur->next ;
					cur = cur->next; //跳出最后一个相同的

					ListNode *Tmp ;
					Tmp = pre->next;
					pre->next = cur ; //跳过相同的节点
					while(Tmp != cur) //删除相同的节点
					{
						ListNode *del ;
						del = Tmp ;
						Tmp = Tmp->next ;
						delete del;
					}
				}
			}			
			return dummy.next;
        }

    return head;
    }
};