/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int global_sum = 0;

void sum_root_to_leaves(struct TreeNode * root, int sum)
{
    if(root == NULL)
        return;
    
    int new_sum = (sum*10) + root->val;
    
    if((root->left == NULL) && (root->right == NULL))
    {
        global_sum += new_sum;
        return;
    }
        
    sum_root_to_leaves(root->left, new_sum);
    sum_root_to_leaves(root->right, new_sum);
   
}


int sumNumbers(struct TreeNode* root)
{
    global_sum = 0;
    int sum = 0;
    sum_root_to_leaves(root, sum);
    
    return global_sum;
    
}