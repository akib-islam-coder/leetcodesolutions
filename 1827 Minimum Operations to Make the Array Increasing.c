int minOperations(int* nums, int numsSize)
{
    int i=0;
    int count = 0;
    for(i=1; i<numsSize; )
    {
        if(nums[i] <= nums[i-1])
        {
            nums[i] += 1;
            count++;
        }
        else
        {
            i++;
        }
    }
    return count;
}