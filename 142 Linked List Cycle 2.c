/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head)
{
    struct ListNode * slow = head;
    struct ListNode * fast = head;
    bool loop_found = false;
    
    while(fast!=NULL)
    {
        slow = slow->next;
        fast = fast->next;
        
        if(fast != NULL)
            fast = fast->next;
        
        if((slow!=NULL) && (fast!=NULL) &&(slow == fast))
        {
            loop_found = true;
            break;
        }
    }
    
    if(!loop_found)
        return NULL;
    
    
    //Initialize slow pointer to head and then increase both pointer one step at a time. The point they meet is the first node of loop
    slow = head;
    
    while(slow!=fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}