/*
 思路：要求结构和值相同
 递归实现我写的代码不行，还是用递归吧！
 1-判断是否为空,处理都为空状态
 2-新建2个栈stack<TreeNode *> ST ，ST1  保存已近比过的元素
 3-压入根节点，建立while循环，当栈两个其中一个为空时，退出循环
 4-弹出栈顶元素继续比较，值相同就继续，否者退出去
 5-如果遇到NULL ，都不压入；判断栈是否，若否，则继续。若是，则退出
 6-最后在判断两个栈若不全为空，则返回false

 Runtime: 3 ms
 */
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) 
    {
        if ( p == NULL && q == NULL) //处理都是为空树的情况
            return true ;
        stack<TreeNode *> ST , ST1 ;
        TreeNode *s , *s1;
        ST.push(p);     ST1.push(q);
        while(!ST.empty() && !ST1.empty())
        {
            s = ST.top();       s1 = ST1.top();
            if(s == NULL || s1 == NULL) //若其中有一个为空，则为错误 ，因为上次都为NULL 是没有压入栈的
                return false;
            if (s->val != s1->val) //value didn't match ，判断值是否相等
                return false;
            ST.pop();       ST1.pop();
            if(s->left != NULL || s1->left != NULL) //有左子树则压入左子树
            {
                 ST.push(s->left);      ST1.push(s1->left);
            }
            if(s->right != NULL || s1->right != NULL)//若有右子树则压入右子树
            {
                 ST.push(s->right);      ST1.push(s1->right);
            }
        }
        if(!ST.empty() || !ST1.empty()) //不全为空，则返回错误的
            return false;
        else
            return true ;
    }
};