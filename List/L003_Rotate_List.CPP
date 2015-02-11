/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*
 当K小于链表长度时；
 1-申请faster , slower分别 指向head ；
 2-让faster 先走K步；
 3-把faster , slower按照相同的step = 1 走；
 4-直到faster->next == NULL 为止；
 5-把slower->next插入到前面;
        faster->next = head->next；
        head = slower->next ;
        slower->next = NULL;
当K大于链表的长度时，K = (K)%Len;
当等于链表的长度时时，链表不移动；
 */
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *faster , *slower ;
        faster = head; slower = head;
        int len = 0 ;
        while(faster->next != NULL)
        {
            faster = faster->next ;
            len++;
        }
        faster = head; //重置
        if(len == k)
            return head ;
        else 
        {
            k = k%len ;
            while(k--)
            {
                faster = faster->next ;
            }
            for(;faster->next != NULL  ;faster = faster->next , slower = slower->next  )
                ;
            faster->next = head->next；
            head = slower->next ;
            slower->next = NULL;
        }
    return head;
    }
};