/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    int carry = 0;
    
    struct ListNode * trav_ptr1 = l1;
    struct ListNode * trav_ptr2 = l2;
    
    struct ListNode * head = NULL;
    struct ListNode * last_node_ptr = NULL;
    
    while((trav_ptr1!=NULL) && (trav_ptr2!=NULL))
    {
        int data = (trav_ptr1->val) + (trav_ptr2->val) + carry;
        
        if(data >= 10)
        {
            carry =  1;
            data  -= 10;
        }
        else
        {
            carry = 0;
        }
        
        struct ListNode * new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
        new_node->val = data;
        
        if(head == NULL)
        {
            head = new_node;
        }
        else
        {
            last_node_ptr->next = new_node;
        }       
        new_node->next = NULL;
        
        last_node_ptr = new_node;
        
        trav_ptr1 = trav_ptr1->next;
        trav_ptr2 = trav_ptr2->next;
    }
    
    while(trav_ptr1 != NULL)
    {
        int data = (trav_ptr1->val) + carry;
        if(data >= 10)
        {
            carry =  1;
            data  -= 10;
        }
        else
        {
            carry = 0;
        }
        
        struct ListNode * new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
        new_node->val = data;
        
        if(head == NULL)
        {
            head = new_node;
        }
        else
        {
            last_node_ptr->next = new_node;
        }       
        new_node->next = NULL;
        
        last_node_ptr = new_node;
        trav_ptr1 = trav_ptr1->next;       
    }
    
    while(trav_ptr2 != NULL)
    {
        int data = (trav_ptr2->val) + carry;
        if(data >= 10)
        {
            carry =  1;
            data  -= 10;
        }
        else
        {
            carry = 0;
        }
        
        struct ListNode * new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
        new_node->val = data;
        
        if(head == NULL)
        {
            head = new_node;
        }
        else
        {
            last_node_ptr->next = new_node;
        }       
        new_node->next = NULL;
        
        last_node_ptr = new_node;
        trav_ptr2 = trav_ptr2->next;       
    }
    
    if(carry)
    {
        struct ListNode * new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
        new_node->val = carry;
        
        if(head == NULL)
        {
            head = new_node;
        }
        else
        {
            last_node_ptr->next = new_node;
        }       
        new_node->next = NULL;
        
        last_node_ptr = new_node;
    }
    
    return head;
}