struct Node
{
    int val;
    int rank;
    struct Node * next;
};

struct Node * pos_hashtable[1000000] = {0};
struct Node * neg_hashtable[1000000] = {0};


void merge(int * arr, int low, int mid, int high)
{
    int * tmp_arr = (int *)malloc(sizeof(int) * (high - low + 1));
    int tmp_arr_index = 0;
    
    int i=0, j=0;
    for(i=low, j=mid+1; i<=mid && j<=high; )
    {
        if(arr[i] <= arr[j])
        {
            tmp_arr[tmp_arr_index++] = arr[i++];
        }
        else
        {
            tmp_arr[tmp_arr_index++] = arr[j++];
        }
    }
    
    while(i<=mid)
    {
        tmp_arr[tmp_arr_index++] = arr[i++];
    }
    
    while(j<=high)
    {
        tmp_arr[tmp_arr_index++] = arr[j++];
    }
    
    memcpy(&arr[low], tmp_arr, sizeof(int) * tmp_arr_index);
    free(tmp_arr);
}

void merge_sort(int * arr, int low, int high)
{
    if(low < high)
    {
        int mid = (low + high)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

void insert_neg_hashtable(int element, int data)
{
    int index = (element * -1);
    index %= 1000000;
    struct Node * trav_ptr = NULL;
    
    if(neg_hashtable[index] == NULL)
    {
        struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->val = element;
        new_node->rank = data;
        neg_hashtable[index] = new_node;
    }
    else
    {
        struct Node * prev_ptr = NULL;
        trav_ptr = neg_hashtable[index];
        
        while(trav_ptr != NULL && trav_ptr->val != element)
        {
            prev_ptr = trav_ptr;
            trav_ptr = trav_ptr->next;
        }
        
        
        if(prev_ptr == NULL)
        {
            struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));
            new_node->val = element;
            new_node->rank = data;
            neg_hashtable[index] = new_node;
        }
        else if(trav_ptr == NULL)
        {
            struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));
            new_node->val = element;
            new_node->rank = data;
            prev_ptr->next = new_node;
        }
        else if(trav_ptr->val == element)
        {
            
        }
    }
}

void insert_pos_hashtable(int element, int data)
{
    int index = element % 1000000;
    struct Node * trav_ptr = NULL;
    
    if(pos_hashtable[index] == NULL)
    {
        struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->val = element;
        new_node->rank = data;
        pos_hashtable[index] = new_node;
    }
    else
    {
        struct Node * prev_ptr = NULL;
        trav_ptr = pos_hashtable[index];
        
        while(trav_ptr != NULL && trav_ptr->val != element)
        {
            prev_ptr = trav_ptr;
            trav_ptr = trav_ptr->next;
        }
        
        
        if(prev_ptr == NULL)
        {
            struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));
            new_node->val = element;
            new_node->rank = data;
            pos_hashtable[index] = new_node;
        }
        else if(trav_ptr == NULL)
        {
            struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));
            new_node->val = element;
            new_node->rank = data;
            prev_ptr->next = new_node;
        }
        else if(trav_ptr->val == element)
        {
            
        }
    } 
}

int search_neg_hashtable(int element)
{
    int index = (element * -1);
    index %= 1000000;
    
    struct Node * trav_ptr = NULL;
    
    if(neg_hashtable[index]->val == element)
    {
        return neg_hashtable[index]->rank;
    }
    else
    {
        struct Node * prev_ptr = NULL;
        trav_ptr = neg_hashtable[index];
        
        while(trav_ptr != NULL && trav_ptr->val != element)
        {
            prev_ptr = trav_ptr;
            trav_ptr = trav_ptr->next;
        }
        
        return trav_ptr->rank;
    }
    
}

int search_pos_hashtable(int element)
{
    int index = (element % 1000000);
    
    struct Node * trav_ptr = NULL;
    
    if(pos_hashtable[index]->val == element)
    {
        return pos_hashtable[index]->rank;
    }
    else
    {
        struct Node * prev_ptr = NULL;
        trav_ptr = pos_hashtable[index];
        
        while(trav_ptr != NULL && trav_ptr->val != element)
        {
            prev_ptr = trav_ptr;
            trav_ptr = trav_ptr->next;
        }
        
        return trav_ptr->rank;
    }
    
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* arrayRankTransform(int* arr, int arrSize, int* returnSize)
{
    int * ret_arr = (int *)malloc(sizeof(int) * arrSize);
    int ret_arr_index = 0;
    
    //Sort the arr
    int * tmp_arr = (int *)malloc(sizeof(int) * arrSize);
    memcpy(tmp_arr, arr, sizeof(int)*arrSize);
    
    merge_sort(tmp_arr, 0, arrSize-1);
    
    //Sorted array is present in tmp_arr, Populate the hashtable
    int i=0;
    int rank = 1;
    int prev_element = INT_MIN;
    printf("arrSize : %d\r\n", arrSize);
    
    for(i=0; i<arrSize; i++)
    {

        if(tmp_arr[i] < 0)
        {
            if(i==0)
            {
                insert_neg_hashtable(tmp_arr[i], rank);
                prev_element = tmp_arr[i];
                rank++;
            }
            else
            {
                if(tmp_arr[i] == prev_element)
                {
                    continue;
                }
                else
                {
                   insert_neg_hashtable(tmp_arr[i], rank);
                    prev_element = tmp_arr[i];
                    rank++; 
                }
            }
        }
        else
        {
            if(i==0)
            {
                insert_pos_hashtable(tmp_arr[i], rank);
                prev_element = tmp_arr[i];
                rank++;
            }
            else
            {
                if(tmp_arr[i] == prev_element)
                {
                    continue;
                }
                else
                {
                   insert_pos_hashtable(tmp_arr[i], rank);
                    prev_element = tmp_arr[i];
                    rank++; 
                }
            }
        }
    }
    
    
    
    for(i=0; i<arrSize; i++)
    {
        if(arr[i] >= 0)
        {
            ret_arr[ret_arr_index++] = search_pos_hashtable(arr[i]);
        }
        else
        {
            ret_arr[ret_arr_index++] = search_neg_hashtable(arr[i]);
        }
    }
    
    *returnSize = ret_arr_index;
    return ret_arr;
}