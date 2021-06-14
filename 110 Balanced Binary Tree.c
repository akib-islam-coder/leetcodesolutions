/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int height(struct TreeNode * root)
{
    if(root == NULL)
        return 0;
    
    int left = height(root->left);
    int right = height(root->right);
    
    if(left >= right)
        return (left+1);
    else
        return (right+1);
}


void check_height(struct TreeNode * root, bool * flag)
{
    if(root == NULL)
        return;
    
    int left_subtree_ht = height(root->left);
    int right_subtree_ht = height(root->right);
    
    int diff = (left_subtree_ht >= right_subtree_ht) ? (left_subtree_ht - right_subtree_ht):(right_subtree_ht - left_subtree_ht);
    
    if(diff >= 2)
    {
        *flag = false;
        return;
    }
    
    check_height(root->left, flag);
    check_height(root->right, flag);
}


bool isBalanced(struct TreeNode* root)
{
    bool flag = true;
    
    check_height(root, &flag);
    return flag;
}