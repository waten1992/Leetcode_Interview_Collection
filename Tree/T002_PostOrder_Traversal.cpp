/*
 1-处理树为空的情况；
 2-申请一个栈stack<ff > ST 保存已近访问过的节点
 3-申请一个结构体 ff保存 节点指针 和 标记是否已近访问过
 4-建立一个while循环 条件是栈不为为空和节点不为空

Given a binary tree, return the postorder traversal of its nodes' values.

67 / 67 test cases passed.
Status: Accepted
Runtime: 3 ms
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<ff> ST; 
        ff f ; 
        if(root == nullptr)
            return result;
         TreeNode *Tmp  = root;//指向根节点 
        while(!ST.empty() || Tmp != nullptr)
        {
            while(Tmp != nullptr) //入栈根节点，继续把左子树压入栈中
            {
                f.p = Tmp ;
                f.flag = true ;//表示已近访问了此节点
                ST.push(f);
                Tmp = Tmp->left; //继续把左子树压入栈中
            }

            f = ST.top();
            ST.pop(); //弹出节点
            Tmp = f.p;
            if(f.flag == true) //已经访问过左子树
            {
            	f.flag = false; //表示出栈时，已近访问过右子树
            	ST.push(f);//从新入栈
            	Tmp = Tmp->right;
            }
            else //已经访问右子树
            {
            	result.push_back(Tmp->val);
            	Tmp = nullptr;
            }
        }
        return result;
    }
private:
    struct ff
    {
        TreeNode *p;
        bool flag ; 
    };

};

