/*
 判断是否是搜索二叉树；
    1-找出左子树的最大值 LMax < root ;
    2-找出右子树的最小值 RMin >root ；
    3-在递归的调用判断，左子树小于root ， 有子树大于root
 --------------------
Runtime: 20 ms
-------------------------
 */
class Solution {
public:
    bool isValidBST(TreeNode *root) 
    {
        return Judge_BST( root, LONG_MIN, LONG_MAX   );
    }
    
    bool Judge_BST(TreeNode *root , long int LMax ,long int  RMin)
    {
        if (root == NULL)
            return true ;
        if((root->val <= LMax) || (root->val >= RMin)) //大于右最小 ， 小于左最大 ，即不是搜索二叉树
            return false ;
        return (Judge_BST(root->left ,LMax,root->val) && Judge_BST(root->right ,root->val , RMin));//递归调用左子树和右子树
    }
};