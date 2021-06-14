/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void symmetric(struct TreeNode * root1, struct TreeNode * root2, bool * flag)
{
    if(!root1 && !root2)
        return;
    
    if( (root1 == NULL) && (root2!=NULL) )
    {
        *flag = false;
        return;
    }
    
    if(  (root2 == NULL) && (root1!=NULL))
    {
        *flag = false;
        return;
    }
        
    if(root1->val != root2->val)
    {
        *flag = false;
        return;
    }
    
    symmetric(root1->left, root2->right, flag);
    symmetric(root1->right, root2->left, flag);
}

bool isSymmetric(struct TreeNode* root)
{
    bool flag = true;
    symmetric(root->left, root->right, &flag);
    return flag;
}