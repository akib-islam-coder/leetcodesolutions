/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int count_node(struct ListNode * root)
{
    struct ListNode * trav_ptr = root;
    int count = 0;
    
    while(trav_ptr)
    {
        count++;
        trav_ptr = trav_ptr->next;
    }
    
    return count;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
    struct ListNode * travA = headA;
    struct ListNode * travB = headB;
    
    if((headA == NULL) || (headB == NULL))
        return NULL;
    
    int nodes_in_A = count_node(headA);
    int nodes_in_B = count_node(headB);
    
    int diff;
    if(nodes_in_A >= nodes_in_B)
    {
        diff = nodes_in_A - nodes_in_B;
    }
    else 
    { 
        diff = nodes_in_B - nodes_in_A;
    }
    
    if(diff)
    {
        int trav_count = 0;
        
        if(nodes_in_A >= nodes_in_B)
        {
 
            while(trav_count != diff)
            {
                travA = travA->next;
                trav_count++;
            }
        }
        else
        {
            while(trav_count != diff)
            {
                travB = travB->next;
                trav_count++;
            }
        }
    }

    while(travA && travB)
    {
        if(travA == travB)
        {
            return travA;
        }
        else
        {
            travA = travA->next;
            travB = travB->next;
        }
    }
    
    return NULL;
    
}