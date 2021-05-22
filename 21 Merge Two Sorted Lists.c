/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode * trav1 = l1;
    struct ListNode * prev_trav1 = NULL;
    struct ListNode * trav2 = l2;
    struct ListNode * next_trav2 = NULL;
    
    if((l1 == NULL) && (l2 != NULL))
    {
        return l2;
    }
    else if((l1 != NULL) && (l2 == NULL))
    {
        return l1;
    }
    
    while((trav1!=NULL) && (trav2!=NULL))
    {
        if(trav1->val <= trav2->val)
        {
            prev_trav1 = trav1;
            trav1 = trav1->next;
        }
        else    
        {
            next_trav2 = trav2->next;
            l2 = trav2->next;
            
            if(prev_trav1!=NULL)
            {
                prev_trav1->next = trav2;
                trav2->next = trav1;
                prev_trav1 = prev_trav1->next;
                trav2 = next_trav2;
            }
            else
            {
                l1 = trav2;
                trav2->next = trav1;
                prev_trav1 = trav2;
                trav2 = next_trav2;
            }
        }
        
    }
    
    if(trav1 == NULL)
    {
        if(prev_trav1 != NULL)
            prev_trav1->next = trav2;
    }
    
    return l1;
    
}