/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#define MAX_NO_OF_NODES 10000
typedef struct stack
{
    int data_arr[MAX_NO_OF_NODES];
    int top;
}Stack;

int isStackFull(Stack * next_larger_node_stack)
{
    if(next_larger_node_stack->top == (MAX_NO_OF_NODES-1))
    {
        return 1;
    }
    else
        return 0;
}

void enqueue( Stack * next_larger_node_stack, int data)
{
    if(isStackFull(next_larger_node_stack))
    {
        return;
    } 
    next_larger_node_stack->data_arr[++(next_larger_node_stack->top)] = data;
}

int count_and_items_push(struct ListNode * head, Stack * next_larger_node_stack)
{
    struct ListNode * trav_ptr = head;
    int count = 0;
    while(trav_ptr!=NULL)
    {
        enqueue(next_larger_node_stack, trav_ptr->val);
        count++;
        trav_ptr = trav_ptr->next;
    }
    return count;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextLargerNodes(struct ListNode* head, int* returnSize)
{
    Stack next_larger_node_stack;
    next_larger_node_stack.top = -1;
    
    //Count number of nodes and push item in the stack
    int no_of_nodes = count_and_items_push(head, &next_larger_node_stack);
    *returnSize = no_of_nodes;
    
    int * ret_arr = (int *)malloc(sizeof(int)*no_of_nodes);
    int ret_arr_index = 0;
    
    struct ListNode * trav_ptr = head;
    
    int stack_index = 0;
    
    while(trav_ptr!=NULL)
    {
        int i=0;
        bool next_larger_node_found = false;
        for(i=stack_index+1; i<=next_larger_node_stack.top; i++)
        {
            if(i > next_larger_node_stack.top)
            {
                next_larger_node_found = false;
                break;
            }
            
            if(next_larger_node_stack.data_arr[i] > trav_ptr->val)
            {
                next_larger_node_found = true;
                ret_arr[ret_arr_index++] = next_larger_node_stack.data_arr[i];
                break;
            }
        }
        
        if(!next_larger_node_found)
        {
            ret_arr[ret_arr_index++] = 0;
        }
        stack_index++;
        trav_ptr = trav_ptr->next;
    }
    return ret_arr;
    
}