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

void inorder(struct TreeNode * root, struct TreeNode ** inorder_arr, int * inorder_arr_index)
{
    if(root == NULL)
        return;
    
    inorder(root->left, inorder_arr, inorder_arr_index);
    inorder_arr[(*inorder_arr_index)++] = root;
    inorder(root->right, inorder_arr, inorder_arr_index); 
}

struct TreeNode * create_gst(struct TreeNode ** gst_root, struct TreeNode * root, bool * first)
{
    if(root == NULL)
        return NULL;
    
    struct TreeNode * new_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    new_node->val = root->val;
    new_node->left = NULL;
    new_node->right = NULL;  
    
    if(*first == true)
    {
        *gst_root = new_node;
        *first = false;
    }
    
    new_node->left  = create_gst(gst_root, root->left, first);
    new_node->right = create_gst(gst_root, root->right, first);
    
    return new_node;
}

struct TreeNode* bstToGst(struct TreeNode* root)
{
    int nodes = count_nodes(root);
    struct TreeNode ** inorder_arr = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * nodes);
    int inorder_arr_index = 0;
    
    inorder(root, inorder_arr, &inorder_arr_index);
    
    int * inorder_arr_val = (int *)malloc(sizeof(int) * nodes);
    int inorder_arr_val_index = 0;
    
    int i=0;
    int sum = 0;
    for(i=0; i<nodes; i++)
    {
        inorder_arr_val[i] = inorder_arr[i]->val;
        sum += inorder_arr[i]->val;
    }
    
    int current_sum = 0;
    for(i=0; i<nodes; i++)
    {
        current_sum += inorder_arr_val[i];
        inorder_arr_val[i] += (sum - current_sum);    
    } 
    
    struct TreeNode * gst_root = NULL;
    
    bool first = true;
    create_gst(&gst_root, root, &first);
    
    struct TreeNode ** gst_arr = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * nodes);
    int gst_arr_index = 0;
    
    inorder(gst_root, gst_arr, &gst_arr_index);
    for(i=0; i<nodes; i++)
    {
        gst_arr[i]->val =   inorder_arr_val[i];
    }
    
    free(inorder_arr);
    free(inorder_arr_val);
    free(gst_arr);
    
    return gst_root;
    
    
}