/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2)
{
    struct ListNode * trav_ptr1 = list1;
    struct ListNode * trav_ptr2 = list2;
    
    int count_1 = 0;
    int count_2 = 0;
    
    struct ListNode * a_node_cur = NULL;
    struct ListNode * a_node_next = NULL;
    
    struct ListNode * b_node_cur = NULL;
    struct ListNode * b_node_next = NULL;
    
    while(count_1 != a)
    {
        a_node_cur = trav_ptr1;
        trav_ptr1 = trav_ptr1->next;
        a_node_next = trav_ptr1;
        count_1++;
    }
    int remaining = b - a + 1;
    
    while(count_2 != remaining)
    {
        b_node_cur = trav_ptr1;
        trav_ptr1 = trav_ptr1->next;
        b_node_next = trav_ptr1;
        count_2++;
    }
    
    a_node_cur->next = list2;
    
    while(trav_ptr2->next != NULL)
    {
        trav_ptr2 = trav_ptr2->next;
    }
    trav_ptr2->next = b_node_next;
    
    //Delete the intermediate nodes
    trav_ptr1 = a_node_next;
    
    while(trav_ptr1 != b_node_cur)
    {
        trav_ptr2 = trav_ptr1;
        trav_ptr1 = trav_ptr1->next;
        free(trav_ptr2);
    }
    
    free(trav_ptr1);
    
    return list1;
}