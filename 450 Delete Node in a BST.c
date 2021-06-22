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
    
    int left = height(root->left);
    int right = height(root->right);
    
    if(left >= right)
        return (1+left);
    else
        return (1+right);
}

struct TreeNode * inorder_succesor(struct TreeNode * root)
{
    //Go to first right and then leftmost element is the inorder_successor
    root = root->right;
    
    if(root == NULL)
        return NULL;
    
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

struct TreeNode * inorder_predessor(struct TreeNode * root)
{
    //Got to first left and then rightmost element is the inorder_predessor
    root = root->left;
    
    if(root == NULL)
        return NULL;
    
    while(root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key)
{
    if(root == NULL)
        return NULL;
    
    if((root->left == NULL) && (root->right == NULL) && (root->val == key))
    {
        free(root);
        return NULL;
    }
    
    if(key < root->val)
        root->left = deleteNode(root->left, key);
    
    else if(key > root->val)
        root->right = deleteNode(root->right, key);
    
    else if(key == root->val)
    {
        //Check the height of the subtrees. Based on the height of the subtree we will use inorder sucessor or predecessor. 
        int left_ht = height(root->left);
        int right_ht = height(root->right);

        struct TreeNode * del_node = NULL;
        
        if(left_ht >= right_ht)
        {
            del_node = inorder_succesor(root);   
            if(del_node == NULL)    //No right child
            {
                del_node = inorder_predessor(root);
                
                //Copy the inorder_sucessor or predecessor value in the root node
                root->val = del_node->val;
                root->left = deleteNode(root->left, del_node->val);
            }
            else
            {
                //Copy the inorder_succesor or predecessor value in the root node
                root->val = del_node->val;
                root->right = deleteNode(root->right, del_node->val);
            }
        }
        else
        {
            del_node = inorder_predessor(root);
            if(del_node == NULL)    //No left child
            {
                del_node = inorder_succesor(root);
                
                //Copy the inorder_succesor or predecessor value in the root node
                root->val = del_node->val;
                root->right = deleteNode(root->right, del_node->val);
            }
            else
            {
                //Copy the inorder_succesor or predecessor value in the root node
                root->val = del_node->val;
                root->left = deleteNode(root->left, del_node->val);
            }
        }
        
    }
    return root;
    
}