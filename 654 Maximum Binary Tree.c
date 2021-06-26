/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode * build_root(int max_val)
{
    if(root == NULL)
        return;
    
    struct TreeNode * new_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    new_node->val = max_val;
    new_node->left = NULL;
    new_node->right = NULL;  
}

struct TreeNode * build_tree(struct TreeNode * root, int * nums, int start_index, int end_index, struct TreeNode * prev_node, int last)
{
    if(root==NULL)
        return;
    
    int i=0;
    int max_num = INT_MIN;
    int index = 0;
    
    for(i=start_index;i<=end_index;i++)
    {
        if(nums[i] >= max_num)
        {
            max_num = nums[i];
            index = i;
        }
    }
    
    struct TreeNode * new_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    new_node->val = max_num;
    
    if(i!=start_index)
    {
        root->left = build_tree(root->left, nums, 0, i-1, root, last);
    }
    else if(i==start_index)
    {
        new_node->left = NULL;
    }
    
    if(i!=end_index)
    {
        root->right = build_tree(root->right, nums, i+1, last, root, last);
    }
    else if(i==end_index)
    {
        new_node->right = NULL;
    }
    
}


struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize)
{
    int max_val = INT_MIN;
    int i=0;
    int index = 0;
    for(i=0; i<numsSize; i++)
    {
        if(nums[i] >= max_val)
        {
            max_val = nums[i];
            index = i;
        }
    }
    
    struct TreeNode * root = NULL;   
    root = build_root(max_val);         //Build the root Node
    
    //Build the left subtree
    build_tree(root->left, int * nums, 0, index-1, root, numsSize-1)
}