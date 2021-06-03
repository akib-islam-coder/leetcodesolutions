/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode * reverse_list(struct ListNode * root)
{
    if(root == NULL)
        return root;
    
    if(root->next == NULL)
        return root;
    
    struct ListNode * cur_ptr  = root;
    struct ListNode * prev_ptr = NULL;
    struct ListNode * next_ptr = root->next;
    
    while(cur_ptr != NULL)
    {
        cur_ptr->next = prev_ptr;
        prev_ptr = cur_ptr;
        cur_ptr = next_ptr;
        
        if(next_ptr!=NULL)
            next_ptr = next_ptr->next;
    }
    return prev_ptr;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int carry = 0;
    
    l1 = reverse_list(l1);
    l2 = reverse_list(l2);
    
    struct ListNode * trav_ptr1 = l1;
    struct ListNode * trav_ptr2 = l2;
    
    struct ListNode * ret_node = NULL;
    
    while(trav_ptr1 && trav_ptr2)
    {
        int sum = trav_ptr1->val + trav_ptr2->val + carry;
        if(sum > 9 )
        {
            carry = 1;
            sum -= 10;
        }
        else
        {
            carry = 0;
        }
        
        struct ListNode * new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
        new_node->val = sum;
        
        if(ret_node == NULL)
        {
            new_node->next = NULL;
        }
        else
        {
            new_node->next = ret_node;
        }
        ret_node = new_node;
        
        trav_ptr1 = trav_ptr1->next;
        trav_ptr2 = trav_ptr2->next;
    }
    
    while(trav_ptr1 || trav_ptr2)
    {
        int sum;
        if(trav_ptr1)
             sum = trav_ptr1->val + carry;
        else
             sum = trav_ptr2->val + carry;
        
        if(sum > 9)
        {
            carry = 1;
            sum -= 10;
        }
        else
        {
            carry = 0;
        }
        
        struct ListNode * new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
        new_node->val = sum;
        
        if(ret_node == NULL)
        {
            new_node->next = NULL;
        }
        else
        {
            new_node->next = ret_node;
        }
        ret_node = new_node;
        
        if(trav_ptr1)
        {
            trav_ptr1 = trav_ptr1->next;
        }
        else
        {
            trav_ptr2 = trav_ptr2->next;
        }
        
    }
    
    if(carry)
    {
        struct ListNode * new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
        new_node->val = carry;
        if(ret_node == NULL)
        {
            new_node->next = NULL;
        }
        else
        {
            new_node->next = ret_node;
        }
        ret_node = new_node;
    }

    return ret_node;
}