/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode * trav_ptr = head;
    struct ListNode * prev_ptr = NULL;
    
    if(head == NULL)
    {
        return head;
    }
    
    while(trav_ptr->next != NULL)
    {

        if(trav_ptr->val == trav_ptr->next->val)
        {
            struct ListNode * del_node = trav_ptr->next;
            trav_ptr->next = del_node->next;
            free(del_node);
        }
        else
        {
            trav_ptr = trav_ptr->next;
        }
      
    }
    return head;
}