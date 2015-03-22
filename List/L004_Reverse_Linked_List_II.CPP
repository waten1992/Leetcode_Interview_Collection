/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
-----------------------------------
解题思路：
    1-先拆，同时把需要reverse的压栈 ，拆分为 A B;
    2-在把栈中的元素压入 A的末尾，即是尾插法；
    3-合并A B
--------
有很多边界问题，如果m = 1 时，意味着A 部分全部是需要逆转的
好恐怖，一趟处理不过来
-------
可以增加一个实头节点，dummy->next = head ; pre = dummy;
先让程序走[1,m-1]步 ,pre 跟着走这么多步。
current_A = pre->next ;//开始获取reverse 头结点
再让程序走[m,n]步，依次压入栈中；
B = current_A->next; //分离A B
把栈中的元素弹出来，插到Pre后面
----------------------------------
写了2个小时，各种通不过。只好借用他人的代码
Runtime: 4 ms
------------
思路：
    1-建立一个实头结点解决，找前驱的麻烦；
    2-走[1,m-1]步 ，pre 跟着走这么多步；
    3-在走[m,n]步，使用头插法解reverse
*/

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
    	ListNode dummy(-1);
        dummy.next = head;
        ListNode *prev = &dummy;
        for (int i = 0; i < m-1; ++i)
            prev = prev->next;
        ListNode* const head2 = prev;
        prev = head2->next;
        ListNode *cur = prev->next;
        for (int i = m; i < n; ++i) 
        {
            prev->next = cur->next;
            cur->next = head2->next;
            head2->next = cur; // 头插法
            cur = prev->next;
        }
return dummy.next;
    }
};