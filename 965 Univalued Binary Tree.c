/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void Traversal(struct TreeNode * root, bool * univ_tree, int * val)
{
    if(root == NULL)
        return;
    
    if(*val == INT_MIN)
    {
        *val = root->val;
    }
    
    if( *val != root->val)
    {
        *univ_tree = false;
        return;
    }
    else
    {
        Traversal(root->left, univ_tree, val);
        Traversal(root->right, univ_tree, val);
    }
    return;
}

bool isUnivalTree(struct TreeNode* root)
{
    static bool univ_tree = true;
    univ_tree = true;
        
    int val = INT_MIN;
    
    Traversal(root, &univ_tree, &val);
    return univ_tree;
    
}