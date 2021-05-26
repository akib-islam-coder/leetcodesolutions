/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int no_of_nodes(struct ListNode * head)
{
    struct ListNode * trav = head;
    int count = 0;
    
    while(trav != NULL)
    {
        trav = trav->next;
        count++;
    }
    return count;
}

struct ListNode* swapNodes(struct ListNode* head, int k)
{
    if(head->next == NULL)
        return head;
    
    int count = no_of_nodes(head);  
    int k_from_end = count - k + 1;
    
    if(k > k_from_end)
    {
        int tmp = 0;
        tmp = k;
        k = k_from_end;
        k_from_end = tmp;
    }
    
    struct ListNode * swap_node1 = head;
    struct ListNode * swap_node1_prev = NULL;
    
    int count1 = 1;
    while(count1 != k)
    {
        swap_node1_prev = swap_node1;
        swap_node1 = swap_node1->next;
        count1++;
    }
    
    
    struct ListNode * swap_node2 = head;
    struct ListNode * swap_node2_prev = NULL;
    
    int count2 = 1;
    while(count2 != k_from_end)
    {
        swap_node2_prev = swap_node2;
        swap_node2 = swap_node2->next;
        count2++;
    }
    
    
    struct ListNode * swap_node1_next = swap_node1->next;
    struct ListNode * swap_node2_next = swap_node2->next;
    
    
    //Exchange Nodes
    if(swap_node1_prev != NULL)
        swap_node1_prev->next = swap_node2;
    else                                        //Swap node is the first node
        head = swap_node2;
        
    
    if(swap_node1_next != swap_node2)
        swap_node2->next = swap_node1_next;
    else
        swap_node2->next = swap_node1;         
    
    
    if(swap_node2_prev != swap_node1)
    {
        if(swap_node2_prev != NULL)
            swap_node2_prev->next = swap_node1;
    }
    
    if(swap_node1->next != swap_node2_next)
        swap_node1->next = swap_node2_next;

    
    return head;

}