/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head)
{
    if(head == NULL)
        return head;
    
    if(head->next == NULL)
        return head;
    
    struct ListNode * prev_ptr = NULL;
    struct ListNode * cur_ptr  = head;
    struct ListNode * next_ptr = head->next;
    
    //Swap first two nodes
    if(cur_ptr == head)
    {
        cur_ptr->next = next_ptr->next;
        next_ptr->next = cur_ptr;
        head = next_ptr;
        
        prev_ptr = cur_ptr;
        cur_ptr = cur_ptr->next;
        
        if(cur_ptr)
            next_ptr = cur_ptr->next;
    }
    
    while(cur_ptr != NULL && next_ptr!=NULL)
    {
        cur_ptr->next = next_ptr->next;;
        next_ptr->next = cur_ptr;
        prev_ptr->next = next_ptr;
        
        prev_ptr = cur_ptr;
        cur_ptr = cur_ptr->next;
        
        if(cur_ptr)
            next_ptr = cur_ptr->next;     
    }
    
    return head;
    
    
}