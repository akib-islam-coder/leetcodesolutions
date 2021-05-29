/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode * hashtable[100] = {NULL};

int hashindex(int num)
{
    return (num%100);
}

void hashtable_insert(int data, int index)
{
    struct ListNode * new_node = (struct ListNode *)malloc(sizeof(struct ListNode));
    new_node->val = data;
    
    if(hashtable[index] == NULL)
    {
        hashtable[index] = new_node;
        new_node->next = NULL;
        return;
    }
    
    struct ListNode * trav_ptr = hashtable[index];
    
    while(trav_ptr->next != NULL)
    {
        trav_ptr = trav_ptr->next;
    }
    trav_ptr->next = new_node;
    new_node->next = NULL;
    return;
}

bool hash_table_search(int data)
{
    int index = hashindex(data);
    
    if(hashtable[index] == NULL)
    {
        return false;
    }
    
    struct ListNode * trav_ptr = hashtable[index];
    
    while(trav_ptr!=NULL)
    {
        if(trav_ptr->val == data)
        {
            return true;
        }
        trav_ptr = trav_ptr->next;
    }
    return false;
}

int numComponents(struct ListNode* head, int* nums, int numsSize)
{
    memset(hashtable, NULL, sizeof(hashtable));
    
    int i=0;
    
    //Insert the nums in the hashtable
    for(i=0; i<numsSize; i++)
    {
        int hash_index = hashindex(nums[i]);
        hashtable_insert(nums[i], hash_index);
    }
    
    
    struct ListNode * trav_ptr = head;
    
    int num_of_components = 0;
    bool connection = false;
    
    while(trav_ptr!=NULL)
    {
        
        //Search in the hashtable for data
        bool data_found = hash_table_search(trav_ptr->val);
        
        if(data_found)
        {
            connection = true;
        }
        else
        {
            if(connection == true)
            {
                num_of_components++;
                connection = false;
            }       
        }
        trav_ptr = trav_ptr->next;
    }
    
    if(connection)
    {
        num_of_components++;
    }
    return num_of_components;
}