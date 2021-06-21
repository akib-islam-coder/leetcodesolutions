/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* insertIntoBST(struct TreeNode* root, int val)
{    
    if(root == NULL)
    {
        struct TreeNode * new_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        new_node->val = val;
        new_node->left = NULL;
        new_node->right = NULL;
        root = new_node;
        return root;
    }
    
    if(val < root->val)
    {
        if(root->left != NULL)
            insertIntoBST(root->left, val);
        else
        {
            struct TreeNode * new_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            new_node->val = val;
            new_node->left = NULL;
            new_node->right = NULL;
            
            root->left = new_node;
        }
    }
    else if(val > root->val)
    {
        if(root->right != NULL)
            insertIntoBST(root->right, val);
        else
        {
            struct TreeNode * new_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            new_node->val = val;
            new_node->left = NULL;
            new_node->right = NULL;
            
            root->right = new_node;
        }
    }
    return root;
}