/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/*
*   Algorithm : Maintain a stack
*   1. If the preorder[i] value is less than node, insert it to left
*   2. If the preorder[i] value is more than node, check the value with the previous node from stack. If the value lies in between, then insert it to the right of current node
*      Else pop out the previous node and compare the value from the previous nodes in stack, if it lies in between, then insert to the right of current node.
*   3. If stack is empty, insert it to the right of the current node.
*/


#define MAX_NODES 100

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

struct TreeNode * peek(Stack * tmp_stack, int index)
{
    return tmp_stack->arr[index];
}

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize)
{   
    Stack tmp_stack;
    tmp_stack.top = -1;  
    
    struct TreeNode * root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    root->left = NULL;
    root->right = NULL;
    
    struct TreeNode * trav_ptr = root;
    
    int i=1;
    while(i < preorderSize)
    {
        if(preorder[i] < trav_ptr->val) 
        {
           // printf("less than : %d, preorder[i] : %d\r\n", trav_ptr->val, preorder[i]);
            struct TreeNode * new_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            new_node->val = preorder[i];
            new_node->left = NULL;
            new_node->right = NULL;
            
            trav_ptr->left = new_node;
            push(&tmp_stack, trav_ptr);
            trav_ptr = new_node;
        }
        else   
        {
            printf("more than : %d\r\n", trav_ptr->val);
            struct TreeNode * peek_element = NULL;
            // printf("tmp_stack.top : %d\r\n",tmp_stack.top);
            
            int j=0;
            for(j=tmp_stack.top; j>=0; j--)
            {
                peek_element = peek(&tmp_stack,j);

                if(preorder[i] > peek_element->val)
                {
                    trav_ptr = pop(&tmp_stack);
                }
                else
                {
                    struct TreeNode * new_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
                    new_node->val = preorder[i];
                    new_node->left = NULL;
                    new_node->right = NULL;
                        
                    trav_ptr->right = new_node;
                    trav_ptr = new_node;
                    break;
                }

            }
            
            if(isStackEmpty(&tmp_stack))
            {
                struct TreeNode * new_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
                new_node->val = preorder[i];
                new_node->left = NULL;
                new_node->right = NULL;
                
                trav_ptr->right = new_node;
                trav_ptr = new_node;
            }
        }
        i++;
    }
    return root;
}