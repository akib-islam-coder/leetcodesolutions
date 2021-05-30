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
    long int arr[MAX_STACK_SIZE];
    int top;
}Stack;

int count_nodes(struct TreeNode * root)
{
    if(root == NULL)
        return 0;
    else
    {
        int left = count_nodes(root->left);
        int right = count_nodes(root->right);
        return left+right+1;
    }
}

int isStackEmpty(Stack * postorder_stack)
{
    if(postorder_stack->top == -1)
        return 1;
    else 
        return 0;
}

int isStackFull(Stack * postorder_stack)
{
    if(postorder_stack->top == MAX_STACK_SIZE-1)
        return 1;
    else
        return 0;
}

void push(Stack * postorder_stack, long int element)
{
    if(isStackFull(postorder_stack))
        return;
    postorder_stack->arr[++(postorder_stack->top)] = element;
    return;
}

long int pop(Stack * postorder_stack)
{
    if(isStackEmpty(postorder_stack))
        return NULL;
    struct TreeNode * ret_val = postorder_stack->arr[(postorder_stack->top)];
    (postorder_stack->top)--;
    return ret_val;
}



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    int no_of_nodes = count_nodes(root);
    *returnSize = no_of_nodes;
    
    int * ret_arr = (int *)malloc(sizeof(int)*no_of_nodes);
    int ret_arr_index = 0;
    
    struct TreeNode * trav_ptr = root;
    long int tmp = 0;
    
    Stack postorder_stack;
    postorder_stack.top = -1;
    
    while((trav_ptr!=NULL) || (!isStackEmpty(&postorder_stack)))
    {
        if(trav_ptr != NULL)
        {
            tmp = trav_ptr;
            push(&postorder_stack, tmp);
            trav_ptr = trav_ptr->left;
        }
        else
        {
            tmp = pop(&postorder_stack);
            
            if(tmp < 0)
            {
                trav_ptr = (-1*tmp);
                ret_arr[ret_arr_index++] = trav_ptr->val;
                trav_ptr = NULL;
            }
            else
            {
                trav_ptr = tmp;
                tmp = (-1 * (long int)trav_ptr);
                push(&postorder_stack, tmp);
                trav_ptr = trav_ptr->right;
            }          
        }
    }
    return ret_arr;
}