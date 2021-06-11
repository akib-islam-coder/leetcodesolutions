/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void preorder(struct TreeNode * root, int * arr, int * arr_index)
{
    if(root == NULL)
        return;
    
    if((root->left == NULL) && (root->right == NULL))   //If leaf node
    {
        arr[*arr_index] = root->val;
        *arr_index += 1;
    }
    
    preorder(root->left, arr, arr_index);
    preorder(root->right, arr, arr_index);
}


bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2)
{
    int * arr1 = (int *)malloc(sizeof(int) * 200);
    int arr1_index = 0;
    
    int * arr2 = (int *)malloc(sizeof(int) * 200);
    int arr2_index = 0;
    
    preorder(root1, arr1, &arr1_index);
    preorder(root2, arr2, &arr2_index);
    
    bool similar = true;
    if(arr1_index != arr2_index)
    {
        similar = false;        
    }
    else
    {
        int i=0;
        for(i=0; i<arr1_index; i++)
        {
            if(arr1[i] != arr2[i])
            {
                similar = false;
                break;
            }
        }
    }
    return similar;
    
}