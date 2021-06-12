/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void preorder(struct TreeNode* root, int * tmp_arr, int * tmp_arr_index)
{
    if(root == NULL)
        return;
    
    tmp_arr[(*tmp_arr_index)++] = root->val;
    
    if((root->left == NULL) && (root->right != NULL))
    {
        tmp_arr[(*tmp_arr_index)++] = INT_MIN;
    }
    
    preorder(root->left, tmp_arr, tmp_arr_index);
    
    if((root->right == NULL) && (root->left != NULL))
    {
        tmp_arr[(*tmp_arr_index)++] = INT_MIN;
    }
    
    preorder(root->right, tmp_arr, tmp_arr_index);
    return;
}

int nodes(struct TreeNode * root)
{
    if(root == NULL)
        return 0;
    
    int left = nodes(root->left);
    int right = nodes(root->right);
    return (left + right + 1);
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{

    
   int * p_arr = (int *)malloc(sizeof(int) * 200);
   int p_arr_index = 0;
    
   preorder(p, p_arr, &p_arr_index);
    
   int * q_arr = (int *)malloc(sizeof(int) * 200);
   int q_arr_index = 0;
    
   preorder(q, q_arr, &q_arr_index);
    
   if(q_arr_index != p_arr_index)
       return false;
    else
    {
        int i=0;
        for(i=0; i<p_arr_index; i++)
        {
            if(p_arr[i] != q_arr[i])
            {
                free(p_arr);
                free(q_arr);
                return false;
            }
        }
    }
    
    free(p_arr);
    free(q_arr);
    return true;
}