/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX_NODES 5000

typedef struct
{
    struct TreeNode * arr[5000];
    int top;
}Stack;

int isStackEmpty(Stack * tmp_stack)
{
    if(tmp_stack->top == -1)
        return 1;
    else
        return 0;
}

int isStackFull(Stack * tmp_stack)
{
    if(tmp_stack->top == MAX_NODES-1)
        return 1;
    else
        return 0;
}

void push(Stack * tmp_stack, struct TreeNode * element)
{
    if(isStackFull(tmp_stack))
        return;
    
    tmp_stack->arr[++(tmp_stack->top)] = element;
}

struct TreeNode * pop(Stack * tmp_stack)
{
    if(isStackEmpty(tmp_stack))
        return NULL;
    
    return tmp_stack->arr[(tmp_stack->top)--];
}

int peek(Stack * tmp_stack, int index)
{
    return tmp_stack->arr[index]->val;
}

void preorder(struct TreeNode * root, Stack * tmp_stack, int * max_diff)
{
    if(root == NULL)
        return;

    push(tmp_stack, root);

    
    int i=0;
    for(i=0; i<tmp_stack->top; i++)
    {
        int diff = peek(tmp_stack, i) - root->val;
        if(diff<0)
        {
            diff *= -1;
        }
        
        if(diff >= *max_diff)
        {
            *max_diff = diff;
        }
    }
    
    preorder(root->left, tmp_stack, max_diff);
    preorder(root->right, tmp_stack, max_diff);
    struct TreeNode * pop_node = pop(tmp_stack);

}

int maxAncestorDiff(struct TreeNode* root)
{
    Stack tmp_stack;
    tmp_stack.top = -1;
    int max_diff = 0;
    
    preorder(root, &tmp_stack, &max_diff);
    return max_diff;
}