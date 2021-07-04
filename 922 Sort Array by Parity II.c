

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* nums, int numsSize, int* returnSize)
{
    int * ret_arr = (int *)malloc(sizeof(int) * numsSize);
    int ret_arr_count_odd = 1;
    int ret_arr_count_even = 0;
    
    int i=0;
    for(i=0; i<numsSize; i++)
    {
        if(nums[i]%2 == 0)   //Even
        {
            ret_arr[ret_arr_count_even] = nums[i];
            ret_arr_count_even += 2;
        }
        else 
        {
            ret_arr[ret_arr_count_odd] = nums[i];
            ret_arr_count_odd += 2;
        }
    }
    *returnSize = numsSize;
    return ret_arr;
}