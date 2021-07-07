/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) 
{
    if(root == NULL)
        return NULL;
    
    struct TreeNode * left = lowestCommonAncestor(root->left, p, q);
    
    if(p == root || q == root)
    {
       if(left != NULL)
           return root;
    }
    
    struct TreeNode * right = lowestCommonAncestor(root->right, p, q);
    
    
    if(root == p || root == q)
    {
        return root;
    }
    
    if(left==NULL && right==NULL)
        return NULL;
    else if(left!=NULL && right==NULL)
        return left;
    else if(left==NULL && right!=NULL)
        return right;
    
    return root;
}