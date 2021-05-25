/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head)
{
    if(head == NULL)
        return head;
    
    if(head->next == NULL)
        return head;
    
    struct ListNode * current = head;
    struct ListNode * p = head->next;
    struct ListNode * q = head->next->next;
    
    while(current != NULL)
    {
        if(current == head)
        {
            current->next = NULL;
        }

        if(p!=NULL)
        {
            p->next = current;
        }
        else
        {
            head = current;
            break;
        }
        
        current = p;
        p = q;
        
        if(q!=NULL)
        {
            q = q->next;
        }
        
    }
    
    return head;
}