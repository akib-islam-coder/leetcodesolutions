/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize)
{
    int * running_sum_arr = (int *)malloc(sizeof(int) * numsSize);
    
    int running_sum = 0;
    
    int  i = 0;
    for(i=0; i<numsSize; i++)
    {
        running_sum += nums[i];
        running_sum_arr[i] = running_sum;
    }
    *returnSize = numsSize;
    return running_sum_arr;
    
}