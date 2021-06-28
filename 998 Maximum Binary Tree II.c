/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode * preorder(struct TreeNode * root, int val)
{
    if(root == NULL)
    {
        struct TreeNode * new_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        new_node->val = val;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    

    if(root->val < val)
    {   
        struct TreeNode * new_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        new_node->val = val;
        new_node->left = NULL;
        new_node->right = NULL;

        new_node->left = root;
        return new_node;      
    }
    
    
    root->right = preorder(root->right, val);

    return root;
    
}

struct TreeNode* insertIntoMaxTree(struct TreeNode* root, int val)
{
    
    if(val > root->val)     //Insert above root
    {
        struct TreeNode * new_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        new_node->val = val;
        new_node->left = root;
        new_node->right = NULL;
        return new_node;
    }
    

    root->right = preorder(root->right, val);
    
    return root;
}