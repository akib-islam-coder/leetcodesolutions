/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int sum = 0;

int sum_left(struct TreeNode* root, struct TreeNode * root_parent)
{
  
    if(root == NULL)
        return 0;
    
    if((root->left==NULL) && (root->right==NULL))
    {
        if(root_parent == NULL)
            return 0;
        else if(root_parent->left == root)
            return root->val;
        else if(root_parent->right == root)
            return 0;
    }

    
    int left = sum_left(root->left, root);
    sum += left;
    int right = sum_left(root->right, root);
    sum += right;
    return 0;
}

int sumOfLeftLeaves(struct TreeNode* root)
{
    memset(&sum, 0x00, sizeof(sum));
    sum_left(root, NULL);
    return sum;
}