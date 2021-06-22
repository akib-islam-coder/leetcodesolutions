

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize)
{
    int * ret_arr = (int *)malloc(sizeof(int) * numsSize);
    int ret_arr_index = 0;
    
    int i=0;
    for(i=0; i<numsSize; i++)
    {
        if(nums[i]%2 == 0)
        {
            ret_arr[ret_arr_index++] = nums[i];
        }
    }
    
    for(i=0; i<numsSize; i++)
    {
        if(nums[i]%2 == 1)
        {
            ret_arr[ret_arr_index++] = nums[i];
        }
    }
    *returnSize = ret_arr_index;
    return ret_arr;
   
}