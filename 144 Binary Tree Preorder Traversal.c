/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX_STACK_SIZE 100

typedef struct stack
{
    struct TreeNode * arr[MAX_STACK_SIZE];
    int top;
}Stack;

int isStackFull(Stack * preorder_stack)
{
    if(preorder_stack->top == MAX_STACK_SIZE-1)
        return 1;
    else
        return 0;
}

int isStackEmpty(Stack * preorder_stack)
{
    if(preorder_stack->top == -1)
        return 1;
    else
        return 0;
}

void push(Stack * preorder_stack, struct TreeNode * element)
{
    if(isStackFull(preorder_stack))
    {
        return;
    }
    
    preorder_stack->arr[++(preorder_stack->top)] = element;
}

struct TreeNode * pop(Stack * preorder_stack)
{
    if(isStackEmpty(preorder_stack))
        return NULL;
    
    struct TreeNode * ret_val = preorder_stack->arr[preorder_stack->top];
    (preorder_stack->top)--;
    return ret_val;
}

int nodes_count(struct TreeNode * root)
{
    
    int count = 0;
    struct TreeNode * trav_ptr = root;
    
    if(trav_ptr != NULL)
    {
        int left_count  = nodes_count(trav_ptr->left);
        int right_count = nodes_count(trav_ptr->right);
        return left_count + right_count + 1;
    }
    else
    {
        return 0;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    Stack preorder_stack;
    preorder_stack.top = -1;

    
    int no_of_nodes = nodes_count(root);
    
    int * ret_arr = (int *)malloc(sizeof(int)*no_of_nodes);
    int ret_arr_index = 0;
    *returnSize = no_of_nodes;   
    
    struct TreeNode * trav_ptr = root;
    
    while((trav_ptr!=NULL) || (!isStackEmpty(&preorder_stack)))
    {
        if(trav_ptr != NULL)
        {
            ret_arr[ret_arr_index++] = trav_ptr->val;
            push(&preorder_stack, trav_ptr);
            trav_ptr = trav_ptr->left;
        }
        else if(trav_ptr == NULL)
        {
            trav_ptr = pop(&preorder_stack);
            trav_ptr = trav_ptr->right;
        }
    }
    return ret_arr;
    
}