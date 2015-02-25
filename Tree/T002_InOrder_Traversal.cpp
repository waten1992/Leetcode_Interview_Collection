/*
 中序非递归：
        1-把左子树压入栈，当遇到NULL时，在弹出且指向右子树，规避了再次用到了根节点；
 
 Runtime: 6 ms
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> ST ;
        TreeNode *Tmp = root ;
        while(Tmp != NULL || !ST.empty()) //只有当前节点为空且栈为空才结束
        {
            if(Tmp != NULL) //当前节点不为NULL
            {
                ST.push(Tmp);
                Tmp = Tmp->left ;
            }
            else //否者弹出栈顶，指向右子树，规避再次根节点
            {
                Tmp = ST.top();
                ST.pop();
                result.push_back(Tmp->val);//压入vector中，解决左子树
                Tmp = Tmp->right; //指向右孩子
            }
        }
    
        return result;    
    }
};