/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define NODES 10000

typedef struct
{
    int arr[NODES];
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
    if(tmp_stack->top == NODES-1)
        return 1;
    else
        return 0;
}

void push(Stack * tmp_stack, int element)
{
    if(isStackFull(tmp_stack))
        return;
    
    tmp_stack->arr[++(tmp_stack->top)] =  element;
}

int pop(Stack * tmp_stack)
{
    if(isStackEmpty(tmp_stack))
        return -1;
    
    int ret_element = tmp_stack->arr[(tmp_stack->top)];
    tmp_stack->top--;
    return ret_element;
}

int peek(Stack * tmp_stack, int index)
{
    return tmp_stack->arr[index];
}

void original_tree(TreeNode * root, TreeNode * target, Stack * original_stack, bool * target_count)
{
    if(root == NULL)
        return;
    
    if((*target_count == false) && (root!=target))
    {
        push(original_stack, root->val);
    }
    
    if(root == target)
    {
        *target_count = true;
        return;
    }
    
    original_tree(root->left,  target,  original_stack, target_count);
    original_tree(root->right,  target,  original_stack, target_count);
    
    if(*target_count == false)
    {
        int pop_element = pop(original_stack);
    }
}

void cloned_tree(TreeNode * root, int target, Stack * clone_stack, Stack * original_stack, TreeNode ** ret_node)
{
    if(root == NULL)
        return;
    
    if(root->val!=target)
    {
        push(clone_stack, root->val);
    }
    
    if(root->val == target)
    {
        //Analyse the stack, it clone and original stack is same, then it is the target node in clone tree (in case duplicates are allowed)
        int i=0;
        if(clone_stack->top == original_stack->top)
        {
            bool match = true;
            for(i=0; i<=clone_stack->top; i++)
            {
                if(peek(clone_stack, i) != peek(original_stack, i))
                {
                    match = false;
                    break;
                }
            }
            
            if(match)
            {
                *ret_node = root;
                return;
            }
        }
    }
    
    cloned_tree(root->left,  target, clone_stack, original_stack, ret_node);
    cloned_tree(root->right, target, clone_stack, original_stack, ret_node);
    int pop_element = pop(clone_stack);
}

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
    {
        Stack original_stack;
        original_stack.top = -1;
        bool target_found = false;
        
        Stack clone_stack;
        clone_stack.top = -1;
        
        original_tree(original, target, &original_stack, &target_found);
        
        TreeNode * ret_node = original;
        
        cloned_tree(cloned, target->val ,&clone_stack, &original_stack, &ret_node);
        return ret_node;
    }
};