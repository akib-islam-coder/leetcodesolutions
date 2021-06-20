/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX_NODES 100000
typedef struct
{
    struct TreeNode * arr[MAX_NODES];
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

void max_element_search(int * max_val_in_stack, Stack * tmp_stack)
{
    if(isStackEmpty(tmp_stack))
    {
        *max_val_in_stack = INT_MIN;
        return;
    }
    
    int i=0;
    int max = INT_MIN;
    for(i=0; i<=tmp_stack->top; i++)
    {
        if(tmp_stack->arr[i]->val >= max)
        {
            max = tmp_stack->arr[i]->val;
        }
    }
    *max_val_in_stack = max;
}

void preorder(struct TreeNode * root, int * count, Stack * tmp_stack, int * max_val_in_stack)
{
    if(root == NULL)
        return;
    
    if(isStackEmpty(tmp_stack)) //Root Node
    {
        *count += 1;
        *max_val_in_stack = root->val;
        push(tmp_stack, root);
    }
    else
    {
        if(root->val >= *max_val_in_stack)
        {
            *max_val_in_stack = root->val;
            *count += 1;
        }
        push(tmp_stack, root);
    }
    
    
    preorder(root->left, count, tmp_stack, max_val_in_stack);
    
    if(root->left != NULL)
    {
        struct TreeNode * pop_element = pop(tmp_stack);
    
        //Search the max element
        max_element_search(max_val_in_stack, tmp_stack);
    }
    
    preorder(root->right, count, tmp_stack, max_val_in_stack);
    
    if(root->right != NULL)
    {
        struct TreeNode *pop_element = pop(tmp_stack);
    
        max_element_search(max_val_in_stack, tmp_stack);
    }
    return;
}

int goodNodes(struct TreeNode* root)
{
    int count = 0;
    int max_val_in_stack = 0;
    
    Stack tmp_stack;
    tmp_stack.top = -1;
    memset(tmp_stack.arr, NULL, sizeof(struct TreeNode *) * MAX_NODES);
    
    preorder(root, &count, &tmp_stack, &max_val_in_stack);
    return count;
}