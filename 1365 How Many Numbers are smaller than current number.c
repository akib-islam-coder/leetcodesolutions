int hash_table[101] = {0};


int find_small_number(int num)
{
    int i=0;
    int sum = 0;
    for(i=0; i<num; i++)
    {
        sum += hash_table[i];
    }
    return sum;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize)
{

    memset(hash_table, 0x00, sizeof(hash_table));
    int i=0;
    for(i=0; i<numsSize; i++)
    {
        hash_table[nums[i]] += 1;
    }
    
    int * ret_arr = (int *)malloc(sizeof(int)*numsSize);
    
    for(i=0; i<numsSize; i++)
    {
        ret_arr[i] = find_small_number(nums[i]);
    }
    
    *returnSize = numsSize;
    return ret_arr;
    
}