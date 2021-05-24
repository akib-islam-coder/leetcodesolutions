/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val)
{

    if(head == NULL)
    {
        return head;
    }
    
    struct ListNode * trav_ptr = head;
    struct ListNode * prev_ptr = NULL;
    
    while(trav_ptr!=NULL)
    {
        if(trav_ptr->val == val)
        {
            if(trav_ptr == head)
            {
                head = trav_ptr->next;
                free(trav_ptr);
                trav_ptr = head;
            }
            else
            {
                prev_ptr->next = trav_ptr->next;
                free(trav_ptr);
                trav_ptr = prev_ptr->next;
            }
        }
        else
        {
            prev_ptr = trav_ptr;
            trav_ptr = trav_ptr->next;
        }
    }
    return head;
}