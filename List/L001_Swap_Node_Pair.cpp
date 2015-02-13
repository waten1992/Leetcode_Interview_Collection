/**
 * 思路：
 *      1-把相邻的先拆成2个链表
 *      2-在交换位置合并
 */
 
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 }

class Solution 
{
public:
    ListNode *swapPairs(ListNode *head) //Leetcode 默认没有头节点 
    {
 		if (head == NULL || head->next == NULL)
 			return head; //若为空链表或者只有一个元素
 		else
 		{
 			ListNode *new_head = new ListNode(-1);
 			ListNode *Tmp ,*Rear, *faster , *slower ;
 			Rear = new_head;
 			slower = head;  faster = slower->next; //faster快一步
 			while (faster != NULL ) //拆链表 
 			{
 				Rear->next = faster ; //指向第一个元素
 				if(faster->next == NULL) 
 				{
 					faster = faster->next ; //使得faster指向NULL;
 					slower->next = NULL ; //使得slower->next == NULL 
 				}
 				else
 				{
 					slower->next = faster->next ; //跳转到下一个元素
 					slower = slower->next; //指向原链表当前节点
 					faster = slower->next ; //指向slower下一个
 				}
 				Rear = Rear->next ; 
 				Rear->next = NULL ;
 			}

 			faster = new_head->next ; //重新指向new_head->next ,有头结点 ;
 			slower = head ; //无头结点
 			ListNode *new_Tmp;
 			Rear = faster ;
 			while( faster != NULL && slower != NULL ) //合并链表
 			{
 				Tmp = slower->next ; //保存下一个
 				new_Tmp = faster->next ; //保存下一个
 				faster->next = slower ; //链接下一个
 				slower->next = new_Tmp ;
 				Rear = slower;
 				faster = new_Tmp ;
 				slower = Tmp ;
 			}
 			if(slower != NULL)
 				Rear->next = slower;

 			return new_head->next;
 		}
    }
};