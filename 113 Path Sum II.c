/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define STACK_SIZE 5000

/*
*   In this problem, we need to keep track of the previous nodes as well from root to leaf node, so we can use stack
*   data structure to track this traversed path information.
*/
typedef struct
{
    struct TreeNode * arr[STACK_SIZE];
    int top;
}Stack;

int isStackFull(Stack * tree_stack)
{
    if(tree_stack->top == STACK_SIZE-1)
        return 1;
    else
        return 0;
}

int isStackEmpty(Stack * tree_stack)
{
    if(tree_stack->top == -1)
        return 1;
    else
        return 0;
}

void push(Stack * tree_stack, struct TreeNode * element)
{
    if(isStackFull(tree_stack))
        return;
    
    tree_stack->arr[++(tree_stack->top)] = element;
    return;
}

struct TreeNode * pop(Stack * tree_stack)
{
    if(isStackEmpty(tree_stack))
        return NULL;
    
    struct TreeNode * ret_element = tree_stack->arr[tree_stack->top];
    --(tree_stack->top);
    return ret_element;
}

int peek(Stack * tree_stack, int index)
{
    return (tree_stack->arr[index])->val;
}

int total_size = 0;

void tree_traverse(struct TreeNode * root, int target_sum, Stack * tree_stack, int sum, int** ret_arr, int * ret_arr_index, int* returnColumnSizes, int * column)
{
    if(root == NULL)
        return;
    
    //Insert the node in the stack
    push(tree_stack, root);
    

    if((sum + root->val == target_sum) && (root->left==NULL) && (root->right==NULL))   //Match found
    {
            
        //Elements in the stack is the path from root to leaf node
        *(ret_arr + *ret_arr_index) = (int *)malloc(sizeof(int)*(tree_stack->top + 1));

        int i=0;
        for(i=0; i<=tree_stack->top; i++)
        {
           *(*(ret_arr + *ret_arr_index) + i) = peek(tree_stack, i);
        }
        *ret_arr_index += 1; 
        
        
        //Fill the columns
        *(returnColumnSizes + *column) = (tree_stack->top + 1);
        
        
        total_size += (tree_stack->top + 1);
        *column += 1;
        
                  
        pop(tree_stack);
        return;
    }   
    
    tree_traverse(root->left, target_sum, tree_stack, sum + root->val, ret_arr, ret_arr_index, returnColumnSizes, column);
    tree_traverse(root->right, target_sum, tree_stack, sum + root->val, ret_arr, ret_arr_index, returnColumnSizes, column);
    
    pop(tree_stack);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes)
{
    total_size = 0;
    
    Stack tree_stack;
    tree_stack.top = -1;
    memset(tree_stack.arr, NULL, sizeof(tree_stack.arr));
    
    int ** ret_arr = (int **)malloc(sizeof(int *)*5000);
    int ret_arr_index = 0;
    
    * returnColumnSizes = (int **)malloc(sizeof(int *)*5000);
    int column_index = 0;
    
    tree_traverse(root, targetSum, &tree_stack, 0, ret_arr, &ret_arr_index, *returnColumnSizes, &column_index);
    
    
    *returnSize = column_index;
    
    return ret_arr;
}