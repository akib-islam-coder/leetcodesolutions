/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode*  preorder(struct TreeNode * root, int target, struct TreeNode * parent, bool left)
{
    if(root == NULL)
        return;
    
    if(root->val == target)
    {
        if((root->left == NULL) && (root->right == NULL))   //Leaf Node
        {
            if((left == true) && parent)
            {
                parent->left = NULL;
                free(root);
                return NULL;
            }
            else if((left == false) && parent)
            {
                parent->right = NULL;
                free(root);
                return NULL;
            }
            else if(!parent)
            {
                free(root);
                root = NULL;
                return root;
            }

        }
    }
    
    preorder(root->left, target, root, true);
    if(root->val == target)
    {
        if((root->left == NULL) && (root->right == NULL))   //Leaf Node
        {
            if((left == true) && parent)
            {
                parent->left = NULL;
                free(root);
                return NULL;
            }
            else if((left == false) && parent)
            {
                parent->right = NULL;
                free(root);
                return NULL;
            }
            else if(!parent)
            {
                free(root);
                root = NULL;
                return root;
            }
        }
    }
  
    
    preorder(root->right, target, root, false);
    if(root->val == target)
    {
        if((root->left == NULL) && (root->right == NULL))   //Leaf Node
        {
            if((left == true) && parent)
            {
                parent->left = NULL;
                free(root);
                return NULL;
            }
            else if((left == false) && parent)
            {
                parent->right = NULL;
                free(root);
                return NULL;
            }
            else if(!parent)    //Root node is to be deleted
            {
                free(root);
              
                root = NULL;
                return root;
            }
        }
    }
    
    return root;
}

struct TreeNode* removeLeafNodes(struct TreeNode* root, int target)
{
      
    struct TreeNode * parent = NULL;
    
    root = preorder(root, target, parent, false);
    return root;
}