/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool identical(struct TreeNode * root, struct TreeNode * subRoot)
{
    if((root==NULL) && (subRoot == NULL))
        return true;
    
    if((root==NULL) && (subRoot != NULL))
        return false;
    
    if((subRoot == NULL) && (root!=NULL))
        return false;
    
    if(root->val == subRoot->val)
    {
        bool ret_val = identical(root->left, subRoot->left);
        if(ret_val)
            ret_val = identical(root->right, subRoot->right);
        
        return ret_val;
    }
    else
    {
        return false;
    }
}

bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
{
    if(subRoot==NULL)
        return true;
    
    if(root==NULL)
        return false;
    
    if(root->val == subRoot->val)
    {
        if(identical(root, subRoot))
        {
            return true;
        }
    }

    bool ret_val = isSubtree(root->left, subRoot);
    if(ret_val)
        return ret_val;
    
    ret_val = isSubtree(root->right, subRoot);
    return ret_val;

}