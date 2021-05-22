/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head)
{
    if(head == NULL)
    {
        return false;
    }
    
    struct ListNode * slow_ptr = head;
    struct ListNode * fast_ptr = head;
    
    if(head->next == NULL)
    {
        return false;
    }
    
    bool loop_found = false;;
    while((slow_ptr!=NULL) && (fast_ptr!=NULL))
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next;
        
        if(fast_ptr != NULL)
        {
            fast_ptr = fast_ptr->next;   
        }
        
        if(slow_ptr == fast_ptr)
        {
            loop_found = true;
            break;
        }
        
    }
    
    if((slow_ptr==NULL)||(fast_ptr==NULL))
    {
        loop_found = false;
    }
    
    return loop_found;
}