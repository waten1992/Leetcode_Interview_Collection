/*
leetcode Binary Search Tree Construction

*/
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std ;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    Solution():root(nullptr)
    {}
    ~Solution()
    {
        DestroyBST(root);
    }
    void Insert_Node(int value)
    {
        Insert_BST(root,value);
    }
    void Print_Tree()
    {
        Print_Tree(root);
    }
protected:
    TreeNode * root ;
private:
    void DestroyBST(TreeNode *&tree) //析构函数
    {
        if ( tree != nullptr)
        {
            DestroyBST(tree->left);
            DestroyBST(tree->right);
            delete tree;
            tree = nullptr ;
        }
    }
    void Insert_BST(TreeNode *&root , int value) //二叉查找树
    {
        if (root == nullptr)
            root = new TreeNode(value);
        else if (root->val > value)
            Insert_BST(root->left , value) ;
        else if (root->val < value)
            Insert_BST(root->right , value);
        else
            ;
    }

    void Print_Tree(TreeNode *tree) //中序遍历
    {
        if(tree != nullptr)
        {
            Print_Tree(tree->left) ;
            cout<<tree->val<<"\t" ;
            Print_Tree(tree->right) ;
        }
    }
};
int main()
{
    int a[] = {5,2,3,6};
    Solution S;
    for(int i = 0 ; i < sizeof(a)/sizeof(a[0]) ; i++ )
        S.Insert_Node(a[i]);
    S.Print_Tree();
    return 0 ;
}
/*
The answer as follow-->
2       3       5       6
Process returned 0 (0x0)   execution time : 0.020 s
Press any key to continue.
*/
