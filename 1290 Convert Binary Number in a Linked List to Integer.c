/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#define MAX_ELEMENTS    30

typedef struct stack
{
    int arr[MAX_ELEMENTS];
    int top;
}Stack;

int isStackFull(Stack * binary_stack)
{
    if(binary_stack->top == MAX_ELEMENTS-1)
    {
         return 1;
    }
    else 
    {
        return 0;
    }
}

int isStackEmpty(Stack * binary_stack)
{
    if(binary_stack->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(Stack * binary_stack, int element)
{
    if(isStackFull(binary_stack))
    {
        return;
    }
    
    binary_stack->arr[++(binary_stack->top)] = element;
    return;
}

int dequeue(Stack * binary_stack)
{
    if(isStackEmpty(binary_stack))
    {
        return 0;
    }
    
    int ret_val = binary_stack->arr[(binary_stack->top)--];
    return ret_val;
}

int getDecimalValue(struct ListNode* head)
{
    Stack binary_stack;
    binary_stack.top = -1;
    
    struct ListNode * trav_ptr = head;
    
    while(trav_ptr!=NULL)
    {
        enqueue(&binary_stack, trav_ptr->val);
        trav_ptr = trav_ptr->next;
    }
    
    int exp_val = 0;
    int num = 0;
    
    while(!isStackEmpty(&binary_stack))
    {
        num += (dequeue(&binary_stack) * pow(2, exp_val));
        exp_val++;
    }
    
    return num;
    
}