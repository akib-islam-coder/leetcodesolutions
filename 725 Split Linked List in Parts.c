/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int count_nodes(struct ListNode *root)
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** splitListToParts(struct ListNode* root, int k, int* returnSize)
{
    int no_of_nodes = count_nodes(root);
    
    int no_of_elements_in_each_half;
    int rem;
    
    if( k <= no_of_nodes)
    {
      no_of_elements_in_each_half  = (no_of_nodes/k);
      rem = (no_of_nodes%k);
    }
    else
    {
        no_of_elements_in_each_half = 1;
        rem = 0;
    }
    
    struct ListNode ** list_ptr = (struct ListNode **)malloc(sizeof(struct ListNode *)*k);
    
    int i=0;
    for(i=0; i<k; i++)
    {
        memset((list_ptr+i), NULL, sizeof(struct ListNode *));
    }
    
    int list_ptr_index = 0;
    
    struct ListNode * trav_ptr = root;
    struct ListNode * next_ptr = root;
    int count = 1;
    
    while(trav_ptr)
    {
       if(count == no_of_elements_in_each_half)
       {
           if(rem != 0)
           {
               rem--;
               count = 1;
               trav_ptr = trav_ptr->next;
               next_ptr = trav_ptr->next;
               trav_ptr->next = NULL;
               *(list_ptr + list_ptr_index) = root;
               list_ptr_index++;
               
               root = next_ptr;
               trav_ptr = next_ptr;
           }
           else
           {
               count = 1;
               next_ptr = trav_ptr->next;
               trav_ptr->next = NULL;
               
               *(list_ptr + list_ptr_index) = root;
               list_ptr_index++;
               
               root = next_ptr;
               trav_ptr = next_ptr;
           }
       }
       else
       {
           count++;
           trav_ptr = trav_ptr->next;
       }       
    }
    
    
        *returnSize = k;
    
    return list_ptr;

    
}