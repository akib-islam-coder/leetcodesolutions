/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int height(struct TreeNode * root)
{
    if(root == NULL)
        return 0;
    
    int lt_ht = height(root->left);
    int rt_ht = height(root->right);
    
    if(lt_ht >= rt_ht)
        return lt_ht+1;
    else
        return rt_ht+1;
}

int max(int a, int b)
{
    if(a>=b)
        return a;
    else
        return b;
}

int diameter(struct TreeNode* root)
{
    if(root == NULL)
        return 0;
    
    //Case when the max diameter passes through root node
    int left_st_ht  = height(root->left);
    int right_st_ht = height(root->right);
    
    //Case when the max diameter doesn't passes through root node
    int left_diameter = diameter(root->left);
    int right_diameter = diameter(root->right);

    return max(left_st_ht + right_st_ht + 1, max(left_diameter, right_diameter));
}

int diameterOfBinaryTree(struct TreeNode* root)
{
    int ret_val = diameter(root);
    return ret_val-1;
}