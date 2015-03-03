/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

---------------
Runtime: 60 ms
解题思路：
参见 https://github.com/waten1992/Cracking_The_Coding_Interview/blob/master/L005_Add_Two_List.cpp
*/
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(-1);
        int carry = 0 ;
        ListNode *pre ;
        pre = &dummy ;
        
        for(ListNode *Pa = l1 ,*Pb = l2 ; Pa != NULL || Pb != NULL ;
        	Pa = Pa==NULL ? NULL :Pa->next, Pb = Pb==NULL ? NULL: Pb->next, pre = pre->next 
         )
        {
        	const int a = Pa == NULL? 0 : Pa->val;
        	const int b = Pb == NULL? 0 : Pb->val;
        	const int value = (a + b + carry) % 10 ; //值
        	carry = (a + b + carry) / 10 ; //进位
        	pre->next = new ListNode(value); //新建节点
        }
    	if(carry != 0)
    		pre->next = new ListNode(carry);
    	return dummy.next;
    }
};