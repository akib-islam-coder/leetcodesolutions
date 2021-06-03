/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool hasPathSum(struct TreeNode* root, int targetSum)
{

    if(root == NULL)
    {
        return false;
    }
    
    int rem_sum = targetSum - root->val;

    if(rem_sum == 0 && (!root->left) && (!root->right))
    {
        return true;
    }
    
    bool flag = false;
    
    if(root->left)
    {
        flag = hasPathSum(root->left, rem_sum);
        if(flag)
            return flag;
    }
    
    if(root->right)
        flag = hasPathSum(root->right, rem_sum);
    
    return flag;
}