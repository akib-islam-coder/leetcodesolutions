/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define STACK_SIZE 100

typedef struct
{
    struct TreeNode * arr[STACK_SIZE];
    int top;
}Stack;

int isStackFull(Stack * tmp_stack)
{
    if(tmp_stack->top == STACK_SIZE - 1)
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
    
    tmp_stack->arr[++(tmp_stack->top)] = element;
    return;
}

struct TreeNode * peek(Stack * tmp_stack, int index)
{
    return tmp_stack->arr[index];    
}

struct TreeNode * pop(Stack * tmp_stack)
{
    if(isStackEmpty(tmp_stack))
    {
        return NULL;
    }

    struct TreeNode * ret_node = tmp_stack->arr[tmp_stack->top];
    (tmp_stack->top)--;
    return ret_node;
}

int height(struct TreeNode * root)
{
    if(root == NULL)
        return 0;
    
    int left = height(root->left);
    int right = height(root->right);
    
    if(left >= right)
        return left+1;
    else
        return right+1;
}

int leaf_count(struct TreeNode * root)
{
    if(root == NULL)
        return 0;
    
    if((root->left == NULL) && (root->right == NULL))
    {
        return 1;
    }
    
    int left = leaf_count(root->left);
    int right = leaf_count(root->right);
    return (left + right);
}

int digits(int nums)
{
    int count = 0;
    while(nums > 0)
    {
        count++;
        nums /= 10;
    }
    return count;
}

void preorder(struct TreeNode * root, Stack * tmp_stack, char ** ptr_arr, int * ptr_arr_index)
{
    if(root == NULL)
        return;

    
    if((root->left == NULL) && (root->right == NULL))   //leaf node
    {
        int path_len = tmp_stack->top+2;
        char * ret_arr = (char *)malloc(sizeof(char) * (path_len * 5));
        int ret_arr_index = 0;
        
        ptr_arr[*ptr_arr_index] = ret_arr;
        *ptr_arr_index += 1;
        
        
        int i=0;
        for(i=0; i<=tmp_stack->top; i++)
        {
            int num = peek(tmp_stack, i)->val;
            if(num < 0)
            {
                ret_arr[ret_arr_index++] = '-';
                num *= -1;
            }
            
            int no_of_digits = digits(num);
            if(no_of_digits == 1)
            {
                ret_arr[ret_arr_index++] = num + '0';    
            }
            else if(no_of_digits == 2)
            {
                ret_arr[ret_arr_index+1] = (num%10) + '0';
                num /= 10;
                ret_arr[ret_arr_index] = (num%10) + '0';
                ret_arr_index += 2;
            }
            else if(no_of_digits == 3)
            {
                ret_arr[ret_arr_index+2] = (num%10) + '0';
                num /= 10;
                ret_arr[ret_arr_index+1] = (num%10) + '0';
                num /= 10;
                ret_arr[ret_arr_index] = (num%10) + '0';
                ret_arr_index += 3;
            }         
            ret_arr[ret_arr_index++] = '-';
            ret_arr[ret_arr_index++] = '>';        
        }

        int num = root->val;
        if(num < 0)
        {
            ret_arr[ret_arr_index++] = '-';
            num *= -1;
        }
        int no_of_digits = digits(num);
        

        if(no_of_digits == 1)
        {
            ret_arr[ret_arr_index++] = num + '0';    
        }
        else if(no_of_digits == 2)
        {
            ret_arr[ret_arr_index+1] = (num%10) + '0';
            num /= 10;
            ret_arr[ret_arr_index] = (num%10) + '0';
            ret_arr_index += 2;
        }
        else if(no_of_digits == 3)
        {
            ret_arr[ret_arr_index+2] = (num%10) + '0';
            num /= 10;
            ret_arr[ret_arr_index+1] = (num%10) + '0';
            num /= 10;
            ret_arr[ret_arr_index] = (num%10) + '0';
            ret_arr_index += 3;
        }  
        
        ret_arr[ret_arr_index] = '\0';
        return;
    }
    
    push(tmp_stack, root);
    
    preorder(root->left, tmp_stack, ptr_arr, ptr_arr_index);
    preorder(root->right, tmp_stack, ptr_arr, ptr_arr_index);
    struct TreeNode * ret_node = pop(tmp_stack);
    return;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** binaryTreePaths(struct TreeNode* root, int* returnSize)
{
    
    int height_of_tree = height(root);
    int no_of_leaf_nodes = leaf_count(root);
    
    char ** ptr_arr = (char **)malloc(sizeof(char *) * no_of_leaf_nodes);
    int ptr_arr_index = 0;
    
    Stack tmp_stack;
    tmp_stack.top = -1;
    memset(tmp_stack.arr, NULL, sizeof(tmp_stack.arr));
    
    preorder(root, &tmp_stack, ptr_arr, &ptr_arr_index);
    
    *returnSize = no_of_leaf_nodes;
    return ptr_arr;
}