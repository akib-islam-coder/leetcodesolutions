/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root)
{
    struct TreeNode * trav_ptr = root;
    int left_count = 0;
    int right_count = 0;
    
    if(trav_ptr)
    {
        left_count = maxDepth(trav_ptr->left);
        right_count = maxDepth(trav_ptr->right);
        
        if(left_count >= right_count)
        {
            return left_count+1;
        }
        else if(right_count > left_count)
        {
            return right_count+1;
        }
    }
    else
    {
        return 0;
    }
    return 0;
}