 /*
 描述：前序遍历用非递归。

 思路： 建立一个栈保存右子树 ，不断的把左子树压入vector中，直到左子树为空，在依次弹出栈中的元素；
 
 1-建立一个vector<int> tree  和 一个stack<TreeNode *> ST ;
   vector<int> tree--->保存先序遍历的序列值
   stack<TreeNode *> ST--->保存右子树
 
 2-开始建立循环，若有右子树不断的压入进栈，左子树则不断的压入vector；
    当左子树完全压入栈之后，开始弹栈直到栈为空退出循环；
 
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> tree ;
        stack<TreeNode *> ST;
      
        TreeNode *Tmp = root;//Tmp指向当前的根节点
        while(Tmp != NULL)
        {
            tree.push_back(Tmp->val); //压入当前的根节点
           
            while(Tmp->left != NULL) //左子树
            {
                tree.push_back(Tmp->left->val);
                if(Tmp->right != NULL) //压入当前的右子树的根节点
                    ST.push(Tmp->right);
                Tmp = Tmp->left ; //迭代
            }
            if(Tmp->right != NULL) //压入当前的右子树的根节点,即是在左子树为空的情况；
                    ST.push(Tmp->right);
            if(ST.empty()) //保证ST.top()能取值
                break;
            Tmp = ST.top() ; //获取栈顶元素
            ST.pop();
        }
        
        return tree;
    }
};