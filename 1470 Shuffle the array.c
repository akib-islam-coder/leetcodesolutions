

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize)
{
    int * ret_arr = (int *)malloc(sizeof(int) * numsSize);
    int i=0;
    int ret_arr_index = 0;
    for(i=0; i<n; i++)
    {
        ret_arr[ret_arr_index++]   =  nums[i];
        ret_arr[ret_arr_index++]   =  nums[n+i];
    }
    
    *returnSize = ret_arr_index;
    return ret_arr;
}