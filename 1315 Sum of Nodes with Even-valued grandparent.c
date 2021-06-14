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
    struct TreeNode * arr_ptr[10000];
    int top;
}Stack;


int isStackFull(Stack * tmp_stack)
{
    if(tmp_stack->top == 10000-1)
        return 1;
    else
        return 0;
}

int isStackEmpty(Stack * tmp_stack)
{
    if(tmp_stack->top == -1)
        return 1;
    else 
        return 0;
}

void push(Stack * tmp_stack, struct TreeNode * element)
{
    if(isStackFull(tmp_stack))
        return;
    
    tmp_stack->arr_ptr[++(tmp_stack->top)] = element;
}

struct TreeNode * pop(Stack * tmp_stack)
{
    if(isStackEmpty(tmp_stack))
        return NULL;
    
    return tmp_stack->arr_ptr[(tmp_stack->top)--];
}

int peek(Stack * tmp_stack, int index)
{
    return tmp_stack->arr_ptr[index]->val;
}

int ret_sum = 0;
int even_val_gp(struct TreeNode * root, Stack * tmp_stack)
{
    
    if(root == NULL)
        return 0;
    
    if(tmp_stack->top < 1)
    {
        push(tmp_stack, root);
        even_val_gp(root->left, tmp_stack);
        even_val_gp(root->right, tmp_stack);
        pop(tmp_stack);
    }
    else
    {
        int gp_val = peek(tmp_stack, tmp_stack->top-1);
        if(gp_val%2 == 0)
        {
            
            ret_sum += root->val;
        }
        
        if((root->left==NULL) && (root->right == NULL))
            return 0;
        
        push(tmp_stack, root);
        even_val_gp(root->left, tmp_stack);
        even_val_gp(root->right, tmp_stack);
        pop(tmp_stack);
    }
    return ret_sum;
}

int sumEvenGrandparent(struct TreeNode* root)
{
    ret_sum = 0;
    Stack tmp_stack;
    tmp_stack.top = -1;
    
    even_val_gp(root, &tmp_stack);
    return ret_sum;
}