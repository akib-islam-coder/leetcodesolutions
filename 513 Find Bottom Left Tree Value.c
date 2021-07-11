/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int find_height(struct TreeNode * root)
{
    if(root == NULL)
        return 0;
    
    int left = find_height(root->left);
    int right = find_height(root->right);
    
    if(left >= right)
        return left+1;
    else
        return right+1;
}

void preorder(struct TreeNode * root, int height, int cur_height, int * val, bool * found)
{
    if(root == NULL)
        return;
    
    preorder(root->left, height, cur_height+1, val, found);
    if(cur_height == height && *found == false)
    {
        *found = true;
        *val = root->val;
        return;
    }
    preorder(root->right, height, cur_height+1, val, found);
    
}

int findBottomLeftValue(struct TreeNode* root)
{
    int height = find_height(root);
    int val = 0;
    bool found = false;
    preorder(root, height, 1, &val, &found);
    return val;
}