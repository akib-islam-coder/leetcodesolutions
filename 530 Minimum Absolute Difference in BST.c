/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void inorder(struct TreeNode * root, int * ret_arr, int * ret_arr_index)
{
    if(root==NULL)
        return;
    
    inorder(root->left, ret_arr, ret_arr_index);
    ret_arr[(*ret_arr_index)++] = root->val;
    inorder(root->right, ret_arr, ret_arr_index);  
}

int count_nodes(struct TreeNode * root)
{
    if(root==NULL)
        return 0;
    
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

int getMinimumDifference(struct TreeNode* root)
{
    int no_of_nodes = count_nodes(root);
    int * ret_arr = (int *)malloc(sizeof(int) * no_of_nodes);
    int ret_arr_index = 0;
    
    //Inorder of BST gives the sorted elements in ascending order
    inorder(root, ret_arr, &ret_arr_index); 
    
    int i=0;
    int min_diff = INT_MAX;
    
    for(i=0; i<no_of_nodes-1; i++)
    {
        int num1 = ret_arr[i];
        int num2 = ret_arr[i+1];
        
        int diff = (num1-num2 > 0) ? (num1 - num2) : (num2 - num1);
        if(diff <= min_diff)
        {
            min_diff = diff;
        }
    }
    free(ret_arr);
    return min_diff;
}