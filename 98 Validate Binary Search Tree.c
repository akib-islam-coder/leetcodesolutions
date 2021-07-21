/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int count(struct TreeNode * root)
{
    if(root == NULL)
        return 0;
    
    return (1 + count(root->left) + count(root->right));
}

void inorder(struct TreeNode * root, int * arr, int * arr_count)
{
    if(root == NULL)
        return;
    
    inorder(root->left, arr, arr_count);
    arr[(*arr_count)++] = root->val;
    inorder(root->right, arr, arr_count);
}

bool isValidBST(struct TreeNode* root)
{
    //Inorder of a BST gives a sorted array
    int no_of_nodes = count(root);
    int * arr = (int *)malloc(sizeof(int) * no_of_nodes);
    int arr_count = 0;
    
    inorder(root, arr, &arr_count);
    
    
    int i=0;
    bool match = true;
    
    int prev = arr[0];
    for(i=1; i<arr_count; i++)
    {
        if(arr[i] > prev)
        {
            prev = arr[i];
        }
        else
        {
            match = false;
            break;
        }
    }
    return match;
}