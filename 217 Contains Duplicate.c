struct Node
{
    int val;
    int freq;
    struct Node * next;
};

struct Node * hashtable[100];

void insert_hashtable(int num)
{

    int index = num % 100;
    if(index < 0)
    {
        index *= -1;
    }
    if(hashtable[index] == NULL)    //First Element
    {
         struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));
         new_node->val = num;
         new_node->next = NULL;
         new_node->freq = 1;
         hashtable[index] = new_node;
    
    }
    else
    {
        struct Node * trav_ptr = hashtable[index];
        struct Node * prev_ptr = NULL;
        
        while(trav_ptr!=NULL && trav_ptr->val != num)
        {
            prev_ptr = trav_ptr;
            trav_ptr = trav_ptr->next;
        }
        
        
        if(prev_ptr == NULL)
        {
            trav_ptr->freq += 1;
        }
        
        if(trav_ptr == NULL)
        {
           struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));
           new_node->val = num;
           new_node->next = NULL;
           new_node->freq = 1; 
           prev_ptr->next = new_node;
        }
        else if(trav_ptr->val == num)
        {
            trav_ptr->freq += 1;
        }
        
    }
}

bool containsDuplicate(int* nums, int numsSize)
{
    int i=0;
    for(i=0; i<100; i++)
    {
        hashtable[i] = NULL;
    }
    
    for(i=0; i<numsSize; i++)
    {
        insert_hashtable(nums[i]);
    }
    
    bool ret = false;
    
    for(i=0; i<100; i++)
    {
        struct Node * trav_ptr = hashtable[i];
        
        while(trav_ptr != NULL)
        {
            if(trav_ptr->freq >= 2)
            {
                ret = true;
                break;
            }
            trav_ptr = trav_ptr->next;
        }
        
        if(ret == true)
            break;
    }
    return ret;
    
}