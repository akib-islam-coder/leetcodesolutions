/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverse_list(struct ListNode* head)
{
	if (head == NULL)
		return head;

	struct ListNode* prev_node = NULL;
	struct ListNode* cur_node  = head;
	struct ListNode* next_node = head->next;

	while (cur_node != NULL)
	{
		cur_node->next = prev_node;
		prev_node = cur_node;
		cur_node = next_node;

		if (next_node != NULL)
		{
			next_node = next_node->next;
		}
	}
	head = prev_node;
	return head;
}


bool isPalindrome(struct ListNode* head)
{
    if(head == NULL)
        return false;
    
    if(head->next == NULL)
        return true;
    
    struct ListNode * slow = head;
    struct ListNode * fast = head->next;
    
    while(fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next;
        
        if(fast->next != NULL)
            fast = fast->next;
    }
    
   slow->next = reverse_list(slow->next);
    
   struct ListNode * trav1 = head;  //First half of list
   struct ListNode * trav2 = slow->next;  //Second half of list
    
   bool is_palindrone = true;
    
    while(trav2!=NULL)
    {
        if(trav1->val != trav2->val)
        {
            is_palindrone =  false;
            break;
        }
        else
        {
            trav1 = trav1->next;
            trav2 = trav2->next;
        }
    }
    
    return is_palindrone;

}