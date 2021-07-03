/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void postorder(struct TreeNode * root, struct TreeNode * p, struct TreeNode * q, bool * p_found, bool * q_found)
{
    if(root == NULL)
        return;
    
    if(p==root || q==root)
    {
        if(p==root)
            *p_found = true;
        
        if(q==root)
            *q_found = true;
    }
    
    postorder(root->left, p, q, p_found, q_found);
    postorder(root->right, p, q, p_found, q_found);
}

void check(struct TreeNode * root, struct TreeNode * p, struct TreeNode * q, struct TreeNode ** ret_node)
{
    if(root == NULL)
        return;
    
    bool p_found = false;
    bool q_found = false;
    
    check(root->left, p, q, ret_node);
    
    if(*ret_node != NULL)
        return;
    
    check(root->right, p, q, ret_node);
    
    if(*ret_node != NULL)
        return;
    
    if(root->left==NULL && root->right==NULL)   //leaf node
    {
        return;
    }
    else if(root->left==NULL && root->right!=NULL)
    {
        p_found = false;
        q_found = false;
        postorder(root->right, p, q, &p_found, &q_found);
             
        if((p_found && root==q) || (q_found && root==p) || (p_found && q_found))
        {
            *ret_node = root;
            return;
        }

    }
    else if(root->left!=NULL && root->right==NULL)
    {
        p_found = false;
        q_found = false;
        postorder(root->left, p, q, &p_found, &q_found);
        
        if((p_found && root==q) || (q_found && root==p) || (p_found && q_found))
        {
            *ret_node = root;
            return;
        }
    }
    else if(root->left!=NULL && root->right!=NULL)
    {
        p_found = false;
        q_found = false;
        postorder(root->left, p, q, &p_found, &q_found);

        if((p_found && root==q) || (q_found && root==p) || (p_found && q_found))
        {
            *ret_node = root;
            return;
        }
        
        postorder(root->right, p, q, &p_found, &q_found);
        
        if((p_found && root==q) || (q_found && root==p) || (p_found && q_found))
        {
            *ret_node = root;
            return;
        }
    }   
}


struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) 
{
    
    struct TreeNode * ret_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    ret_node = NULL;
    check(root, p, q, &ret_node);

    return ret_node;
  
        
}