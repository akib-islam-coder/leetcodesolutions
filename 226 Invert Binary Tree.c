/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* invertTree(struct TreeNode* root)
{
    if(root == NULL)
        return root;
    
    
    if((root->left == NULL) && (root->right == NULL))
        return root;
    
    struct TreeNode * left_node = root->left;
    root->left = root->right;
    root->right = left_node;
    
    invertTree(root->left);
    invertTree(root->right);
    
    return root;
    
}