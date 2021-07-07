/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int count_nodes(struct TreeNode * root)
{
    if(root == NULL)
        return 0;
    
    return (1 + count_nodes(root->left) + count_nodes(root->right));
}


void inorder(struct TreeNode * root, int * ret_arr, int * ret_arr_index)
{
    if(root == NULL)
        return;
    
    inorder(root->left, ret_arr, ret_arr_index);
    ret_arr[(*ret_arr_index)++] = root->val;
    inorder(root->right, ret_arr, ret_arr_index);
}

struct TreeNode* increasingBST(struct TreeNode* root)
{
    int nodes = count_nodes(root);
    int * ret_arr = (int *)malloc(sizeof(int) * nodes);
    int ret_arr_index = 0;
    
    inorder(root, ret_arr, &ret_arr_index);
    
    struct TreeNode * node_arr = (struct TreeNode *)malloc(sizeof(struct TreeNode) * nodes);
    int node_arr_index = 0;
    
    int i=0;
    for(i=0; i<nodes; i++)
    {
        node_arr[i].val = ret_arr[i];
        node_arr[i].left =  NULL;
        
        if(i+1 != nodes)
            node_arr[i].right = &node_arr[i+1];
        else
            node_arr[i].right = NULL;
    }
    return &node_arr[0];
}