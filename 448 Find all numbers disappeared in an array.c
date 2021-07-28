

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize)
{
    int * hashtable = (int *)malloc(sizeof(int) * (numsSize+1));
    
    int i=0;
    hashtable[0] = 0;
    for(i=1; i<numsSize+1; i++)
    {
        hashtable[i] = 1;
    }
    
    
    for(i=0; i<numsSize; i++)
    {
        hashtable[nums[i]] = 0;
    }
    
    int * ret_arr = (int *)malloc(sizeof(int) * (numsSize+1));
    int ret_arr_index = 0;
    
    for(i=0; i<numsSize+1; i++)
    {
        if(hashtable[i] == 1)
            ret_arr[ret_arr_index++] = i; 
    }
    *returnSize = ret_arr_index;
    return ret_arr;
    
}