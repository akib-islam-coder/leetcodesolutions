/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int first_min  = INT_MAX;
int second_min = INT_MAX;
int max_flag_set = false;

void preorder(struct TreeNode * root)
{
    if(root == NULL)
        return;
    
    if(root->val <= first_min)
    {
        first_min = root->val;
    }
    else if( (root->val > first_min) && (root->val <= second_min))
    {
        second_min = root->val;
        max_flag_set = true;
    }
    
    preorder(root->left);
    preorder(root->right);
}

int findSecondMinimumValue(struct TreeNode* root)
{
    first_min  = INT_MAX;
    second_min = INT_MAX;
    max_flag_set = false;
    
    preorder(root);
    if((second_min == INT_MAX) && (!max_flag_set))
        return -1;
    else
        return second_min;
}