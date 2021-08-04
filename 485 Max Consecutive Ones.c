

int findMaxConsecutiveOnes(int* nums, int numsSize)
{
    int end_index = 0;
    
    int max_sum = 0;
    int cur_sum = 0;
    
    int i=0;
    for(end_index=0; end_index<numsSize; )
    {
        if(nums[end_index] == 0)
        {
            if(cur_sum >= max_sum)
            {
                max_sum = cur_sum;
            }
            cur_sum = 0;
            end_index++;
        }
        else if(nums[end_index] == 1)
        {
            end_index++;
            cur_sum++;
        }
    }
    
    if(cur_sum >= max_sum)
    {
        max_sum = cur_sum;
    }
    return max_sum;
    
}