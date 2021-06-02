/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int min = INT_MAX;
bool min_found = false;

int minDepthPath(struct TreeNode * root, int level)
{
   if(root == NULL)
        return 0;
    
    if(((!root->left))&(!(root->right)))    //Left Node
    {
        if(level <= min)
        {
            min = level;
            min_found = true;
        }
        return min;
    }
    
    minDepthPath(root->left, level+1);
    minDepthPath(root->right, level+1);
    return min;    
}

int minDepth(struct TreeNode* root)
{
    min = INT_MAX;
    min_found = false;
    
    int level = 1;
    minDepthPath(root, level);
    if(min_found)
        return min;
    else
        return 0;
}