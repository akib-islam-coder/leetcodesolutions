/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX_NODES 1

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
    if(tmp_stack->top == MAX_NODES - 1)
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

void preorder(struct TreeNode * root, struct TreeNode ** new_linked_list, Stack * tmp_stack)
{
    if(root == NULL)
        return;
    
    struct TreeNode * new_linked_node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    
    if(isStackEmpty(tmp_stack))    //Root Node
    {     
        printf("new_node : %p\r\n", new_linked_node);
        new_linked_node->val = root->val;
        new_linked_node->left = NULL;
        new_linked_node->right = NULL;
        
        *new_linked_list = new_linked_node;
        
        push(tmp_stack, new_linked_node);
    }
    else
    {
        struct TreeNode * prev_linked_node = pop(tmp_stack);
        prev_linked_node->right = new_linked_node;
        new_linked_node->val = root->val;
        new_linked_node->left = NULL;
        new_linked_node->right = NULL;
        
        push(tmp_stack, new_linked_node);
    }
    
    preorder(root->left, new_linked_list, tmp_stack);
    
    preorder(root->right, new_linked_list, tmp_stack);   
}

int count_nodes(struct TreeNode * root)
{
    if(root == NULL)
        return 0;
    
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

void flatten(struct TreeNode* root)
{
    
    if(root == NULL)
    {
        return NULL;
    }
    
    int no_of_nodes = count_nodes(root);
    struct TreeNode * new_linked_list = NULL;
    
    Stack tmp_stack;
    tmp_stack.top = -1;
    
    preorder(root, &new_linked_list, &tmp_stack);
    *root = *new_linked_list;
    
    
    return;
    
}