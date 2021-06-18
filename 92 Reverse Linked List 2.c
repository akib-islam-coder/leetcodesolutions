/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseBetween(struct ListNode* head, int left, int right)
{
    int cur_count = 1;
    
    if( (head==NULL) || (head->next == NULL))
    {
        return head;
        
    }
    
    struct ListNode * prev_ptr = NULL;
    struct ListNode * trav_ptr = head;
    
    while(cur_count != left)
    {
        cur_count++;
        prev_ptr = trav_ptr;
        trav_ptr = trav_ptr->next;      
    }
    
    struct ListNode * start_ptr = NULL;
    start_ptr = trav_ptr;
    
    trav_ptr = head;    //Reset trav_ptr
    
    struct ListNode * end_ptr = NULL;
    cur_count = 1;
    
    while(cur_count != right)
    {
        cur_count++;
        trav_ptr = trav_ptr->next;
    }
    end_ptr = trav_ptr;
    
    struct ListNode * next_ptr = end_ptr->next;
    
    trav_ptr = start_ptr;
    
    struct ListNode * prev_trav_ptr = prev_ptr;
    struct ListNode * next_trav_ptr = trav_ptr->next;
    
    while(trav_ptr != next_ptr)
    {
        trav_ptr->next = prev_trav_ptr;
        prev_trav_ptr = trav_ptr;
        trav_ptr = next_trav_ptr;
        if(next_trav_ptr !=NULL)
            next_trav_ptr = next_trav_ptr->next;
    }
    
    if(prev_ptr == NULL)
    {
        head = prev_trav_ptr;
    }
    else
    {
        prev_ptr->next = prev_trav_ptr;
    }
    
    
    start_ptr->next = trav_ptr;
    
    return head;
}