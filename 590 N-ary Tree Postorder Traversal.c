/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */
int no_of_nodes(struct Node * root)
{
    if(root == NULL)
        return 0;
    
    if(root->numChildren == 0)
        return 1;
    
    int i=0;
    int sum = 0;
    
    for(i=0; i< root->numChildren; i++)
    {
        sum += no_of_nodes(root->children[i]);
    }
    
    return (sum + 1);
}


void postorder_traversal(struct Node * root, int * ret_arr, int * ret_arr_index)
{
    if(root == NULL)
        return;
    
    if(root->numChildren == 0)
    {
        ret_arr[(*ret_arr_index)++] = root->val;
        return;
    }
    
    int i=0;
    for(i=0; i< root->numChildren; i++)
    {
        postorder_traversal(root->children[i], ret_arr, ret_arr_index);
    }
    
    ret_arr[(*ret_arr_index)++] = root->val;
    return;    
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorder(struct Node* root, int* returnSize)
{
    int nodes = no_of_nodes(root);
    
    int * ret_arr = (int *)malloc(sizeof(int) * nodes);
    int ret_arr_index = 0;
    
    postorder_traversal(root, ret_arr, &ret_arr_index);
    *returnSize = ret_arr_index;
    return ret_arr;
}