/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* middleNode(struct ListNode* head)
{

        struct ListNode * slow_ptr = head;
        struct ListNode * fast_ptr = head->next;
    
        while(fast_ptr != NULL)
        {
            slow_ptr = slow_ptr->next;
            
            fast_ptr = fast_ptr->next;
            if(fast_ptr!=NULL)
            {
                fast_ptr = fast_ptr->next;
            }
        }
    
    return slow_ptr;
}