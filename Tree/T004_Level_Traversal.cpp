/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*-----------------------------------------
 
    用队列queue<TreeNode *> qu 存储每一层元素，核心是如何分离每一层。
方案一：
    1-采用插入NULL来分割 每一层的元素，即是每次完成一次层元素就要插入NULL；
    2-当遍历的时候遇到NULL，则表示这一层就是要完成了。
    3-使用整层追加，分离代码，让代码的结构清晰简单；
方案二：
    1-采用连个队列，Current_level--->存储本层元素 , Next_level-->存储下一层的元素；
 -------------------------------------------*/
/*+++++++++++++++++++++++++
 方案一：Runtime: 10 ms    
+++++++++++++++++++++++++*/
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root)  //使用NULL 分离 ， 使得代码清晰易懂
    {
        queue<TreeNode *> qu ;
        vector<vector<int>> result ;
        if(root == NULL)
            return result;
        qu.push(root);
        while(!qu.empty()) //直到所有的元素都归为零
        {
            qu.push(NULL); //每一层都插入一个 NULL
            result.push_back(Get_Next_Level(qu));  //追加整层
            qu.pop(); //把NULL pop 出去
        }
     return result;  
    }
    
    vector<int> Get_Next_Level(queue<TreeNode *> &qu)  //获得整层的元素
    {
        vector<int> Next_Element; 
        
        if(qu.empty())
            return Next_Element ;
        while(qu.front() != NULL) //直到遇到NULL 表示这一层才算结束
        {
            TreeNode *Tmp = qu.front() ;
            qu.pop() ;
            if(Tmp->left != NULL) //左孩子
                qu.push(Tmp->left);
            if(Tmp->right != NULL)//右孩子
                qu.push(Tmp->right);
            Next_Element.push_back(Tmp->val) ; //存储到vector中
        }
    return Next_Element ;
    }
};

/*--------------------------------------------------------------------------------------------*/
/*==============
Runtime: 8 ms
===============*/
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root)  //使用NULL 分离 ， 使得代码清晰易懂
    {
        queue<TreeNode *> Current_level ,  Next_level ;
        vector<vector<int>> result ;
        vector<int> level; //储存每一层的值
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
            result.push_back(level);  //追加整层
            level.clear();//清空level 的值
            swap(Current_level,Next_level); //交换两层元素，使得Current_level 继续循环，直到Next_level 为空了
        }
     return result;  
    }
};