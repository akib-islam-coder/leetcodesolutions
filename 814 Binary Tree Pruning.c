/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* pruneTree(struct TreeNode* root)
{
     if(root == NULL)
        return NULL;
    
    if((root->val == 0) && (root->left == NULL) && (root->right == NULL))
    {
        struct TreeNode * del_node = root;
        free(del_node);
        return NULL;
    }
    
    
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    
    if((root->val == 0) && (root->left == NULL) && (root->right == NULL))
    {
        struct TreeNode * del_node = root;
        free(del_node);
        return NULL;
    }
    return root;
}