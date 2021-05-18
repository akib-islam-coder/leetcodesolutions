typedef struct node
{
    int data;
    int index;
    struct node * next;
}Node;


Node * hashtable[100] = {NULL};

int hash_index(int index)
{
    return (index%100);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{

    /*
    * O(n) complexity time. In each iteration, we will search if (target - nums[i]) is found at hash table.
    * If yes, then the element found at hash table and nums[i] adds up to the target. If no, continue.
    */
    
    int i = 0, count=0;
    bool match_found = false;
    
    *returnSize = 2;
    int * ret_arr = (int *)malloc(sizeof(int)*(*returnSize));
    int ret_arr_index = 0;
    
    memset(hashtable, NULL, 100 * sizeof(Node *));
    
    //Insert all the items in hashtable
    for(i=0; i<numsSize; i++)
    {
        int index = hash_index(nums[i]);
        if(index < 0)
        {
            index = (-1 * index);
        }
        
        Node * new_node = (Node *)malloc(sizeof(Node));
        new_node->data  = nums[i];
        new_node->index = i;
        new_node->next  = NULL;
    
        
        if(hashtable[index] == NULL)
        {
            hashtable[index] = new_node;    
        }
        else
        {
            Node * trav_ptr = hashtable[index];
            
            while(trav_ptr->next != NULL)   //Not inserting in sorting order
            {
                trav_ptr = trav_ptr->next;
            }
            
            trav_ptr->next = new_node;
        }
    }
    
    i=0;
    int search_element;
    
    for(i=0; i<numsSize && (match_found==false); i++)
    {
        count = 0;
        search_element = 0;
        search_element = target - nums[i];
        
        ret_arr[0] = i;
        
        //Search the search_element in the hash table
        int index;
        
        if(search_element < 0)
        {
            index = hash_index(-1 * search_element);
        }
        else
        {
            index = hash_index(search_element);
        }

        Node * trav_ptr = hashtable[index];
        
        if(search_element == nums[i])   //Two elements of same data should exists if successful solution
        {
            count = 0; 

            while(trav_ptr != NULL)
            {
                if(trav_ptr->data == search_element)
                {
                    count++;
                }
                
                if(count == 2)
                {
                    ret_arr[1] =  trav_ptr->index;
                    match_found = true;
                    break;
                }
                
                trav_ptr = trav_ptr->next;
            }
        }
        else
        {
            while(trav_ptr != NULL)
            {
                if(trav_ptr->data == search_element)
                {
                    ret_arr[1] =  trav_ptr->index;
                    match_found = true;
                    break;
                }
                
                trav_ptr = trav_ptr->next;
            }
        }
    }
    
    return ret_arr;
    
}