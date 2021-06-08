/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int levels[2];
long long int parent_arr[2];
int i=0;

void Cousins(struct TreeNode * root, int x, int y, int level)
{
    if((root == NULL))
        return;
    
    
    if((root->left!=NULL) && ((root->left->val == x) || (root->left->val == y)))
    {
        levels[i] = level+1;
        parent_arr[i++] = root;
    }
    
    if((root->right!=NULL)  && ((root->right->val == x) || (root->right->val == y)))
    {
        levels[i] = level+1;
        parent_arr[i++] = root;
    }
    
    Cousins(root->left, x, y, level+1);
    Cousins(root->right, x, y, level+1);
}



bool isCousins(struct TreeNode* root, int x, int y)
{
    if(root == NULL)
        return false;
    
    memset(levels, INT_MIN, sizeof(levels));
    memset(parent_arr, NULL, sizeof(parent_arr));
    i=0;
    Cousins(root, x, y, 0);

    if( (levels[0] == levels[1]) && (parent_arr[0] != parent_arr[1]))
    {
        return true;
    }
    else
    {
        return false;
    }
    
}