/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



typedef struct 
{
  struct TreeNode * root_node;    
  int * arr_ptr;
  int arr_ptr_len;
  int cur_index;
} BSTIterator;

int count_nodes(struct TreeNode * root)
{
    if(root == NULL)
        return 0;
    
    return (1 + count_nodes(root->left) + count_nodes(root->right));
}

void inorder(struct TreeNode * root, int arr[], int * arr_index)
{
    if(root == NULL)
        return;
    
    inorder(root->left, arr, arr_index);
    arr[(*arr_index)++] = root->val;
    inorder(root->right, arr, arr_index);
}

BSTIterator* bSTIteratorCreate(struct TreeNode* root) 
{
    BSTIterator * bst_obj = (BSTIterator *)malloc(sizeof(BSTIterator));
    bst_obj->root_node = root;
    
    int no_of_nodes = count_nodes(root);
    bst_obj->arr_ptr = (int *)malloc(sizeof(int) * no_of_nodes);
    int arr_index = 0;
    
    inorder(root, bst_obj->arr_ptr, &arr_index);
    bst_obj->arr_ptr_len = arr_index;
    bst_obj->cur_index = -1;
    return bst_obj;
}

int bSTIteratorNext(BSTIterator* obj) 
{
    obj->cur_index += 1;
    return obj->arr_ptr[obj->cur_index];
}

bool bSTIteratorHasNext(BSTIterator* obj) 
{
   if(obj->cur_index + 1 < obj->arr_ptr_len)
       return true;
   else
       return false;
}

void bSTIteratorFree(BSTIterator* obj) 
{
    free(obj);
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);
 
 * bool param_2 = bSTIteratorHasNext(obj);
 
 * bSTIteratorFree(obj);
*/