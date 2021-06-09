/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

void preorder_trav(struct Node * root, int * ret_arr, int * ret_arr_index)
{
    if(root == NULL)
        return;
    
    ret_arr[*ret_arr_index] = root->val;
    *ret_arr_index += 1;
    
    int i=0;
    for(i=0; i<root->numChildren; i++)
    {
        preorder_trav( root->children[i], ret_arr, ret_arr_index);    
    }
}

int no_of_nodes = 0;

void nodes(struct Node * root)
{
    if(root == NULL)
        return;
    
    no_of_nodes += 1;
    
    int i=0;
    for(i=0; i<root->numChildren; i++)
    {
        nodes( root->children[i]);    
    }
    
    
}



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorder(struct Node* root, int* returnSize) 
{
    no_of_nodes = 0;
    
    nodes(root);
    
    int * ret_arr = (int *)malloc(sizeof(int) * no_of_nodes);
    int ret_arr_index = 0;
    
    preorder_trav(root, ret_arr, &ret_arr_index);
    *returnSize = ret_arr_index;
    return ret_arr;
    
    
}