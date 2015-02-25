/*
 描述：层次遍历从下层向上层输出；
 解法参见：https://github.com/waten1992/Leetcode_Interview_Collection/blob/master/Tree/T004_Level_Traversal.cpp
 而外的需要一个栈保存每一层的元素，成功分离层元素后，pop()出去
 
 */
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root)
    {
        queue<TreeNode *> Current_level ,  Next_level ;//存储层元素
        vector<vector<int>> result ;
        vector<int> level; //储存每一层的值
        stack<vector<int>>ST ; //保存到每一层的元素
        if(root == NULL)
            return result;
        Current_level.push(root);
        while(!Current_level.empty()) //直到所有的元素都归为零
        {
             while(!Current_level.empty()) //把下一层的元素用Next_level 收集起来；
             {
                TreeNode * Tmp = Current_level.front();
                Current_level.pop();
                level.push_back(Tmp->val);//搜集每一层的值 
                if(Tmp->left != NULL)
                    Next_level.push(Tmp->left);
                if(Tmp->right != NULL)
                    Next_level.push(Tmp->right);
             }
            ST.push(level); //保存每一层的元素
            level.clear();//清空level 的值
            swap(Current_level,Next_level); //交换两层元素，使得Current_level 继续循环，直到Next_level 为空了
        }
        while(!ST.empty())
        {
            result.push_back(ST.top());
            ST.pop();
        }
     return result;  
    }
};