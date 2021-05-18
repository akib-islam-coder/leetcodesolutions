/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void inorder(struct TreeNode * node_ptr, int * inorder_arr, int * inorder_trav_index)
{
    struct TreeNode * node = node_ptr;
    
    if(node != NULL)
    {
        inorder(node->left, inorder_arr, inorder_trav_index);
        inorder_arr[(*inorder_trav_index)++] = node->val;
        inorder(node->right, inorder_arr, inorder_trav_index);
    }
}

int nodes_count(struct TreeNode * root)
{
    if(root!=NULL)
        return (1 + nodes_count(root->left) + nodes_count(root->right));
    else
        return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{   
    
    //Count the no of elements
    int no_of_nodes = nodes_count(root);
    
    int * inorder_arr = (int *)malloc(sizeof(int) * no_of_nodes);
    
    if(root == NULL)
    {
        *returnSize = no_of_nodes;
        return inorder_arr;
    }
    
    struct TreeNode * trav_ptr = root;
    
    static int inorder_trav_index = 0;
    inorder_trav_index = 0;
    inorder(trav_ptr, inorder_arr, &inorder_trav_index);
    
    
    *returnSize = inorder_trav_index;
    return inorder_arr;
}