/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int sum = 0;

void traversal(struct TreeNode* root, int low, int high)
{
    if(root == NULL)
        return;
    
    if((root->val >= low) && (root->val <= high))
    {
        sum += root->val;
    }
    
    traversal(root->left, low, high);
    traversal(root->right, low, high);
}

int rangeSumBST(struct TreeNode* root, int low, int high)
{
    memset(&sum, 0x00, sizeof(sum));
    traversal(root, low, high);
    return sum;   
}