int max_num(int a, int b)
{
    return a>=b?a:b;
}

int maxSubArray(int* nums, int numsSize)
{
    //Approach - We will do this in linear time O(n). While traversing each element we must see what is the max we can get, whether max in this position or we need to add
    //previous positions as well, Kadane Algorithm
    
    int i=0;
    int cur_sum = 0;
    int max = INT_MIN;
    
    cur_sum = nums[i];
    if(cur_sum > max)
    {
        max = cur_sum;
    }
    
    for(i=1; i<numsSize; i++)
    {
        cur_sum = max_num(nums[i] , nums[i] + cur_sum);
        if(cur_sum > max)
        {
            max = cur_sum;
        }
    }
    return max;
    
}