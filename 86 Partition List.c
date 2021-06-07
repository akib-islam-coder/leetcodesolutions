/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x)
{
    if(head == NULL || (head->next == NULL))
        return head;
    
    struct ListNode * prev_ptr = NULL;
    struct ListNode * trav_ptr = head;
    
    while(trav_ptr && (trav_ptr->val < x))
    {
        prev_ptr = trav_ptr;
        trav_ptr = trav_ptr->next;
    }
    
    if(!trav_ptr)   //End of list without finding any greater node than x
    {
        return head;
    }
    
    struct ListNode * node_greater_than_x = trav_ptr;
    
    struct ListNode * prev_trav_ptr = trav_ptr;
    trav_ptr = trav_ptr->next;
    
    while(trav_ptr)
    {
        if(trav_ptr->val >= x)
        {
            prev_trav_ptr = trav_ptr;
            trav_ptr = trav_ptr->next;
        }
        else
        {
            prev_trav_ptr->next = trav_ptr->next;
            
            if(prev_ptr!=NULL)
            {
                trav_ptr->next = prev_ptr->next;
                prev_ptr->next = trav_ptr;
            }
            else
            {
                head = trav_ptr;
                trav_ptr->next = node_greater_than_x;     
            }
            
            prev_ptr = trav_ptr;
            trav_ptr = prev_trav_ptr->next;
            
        }
    }
    return head;
    
}