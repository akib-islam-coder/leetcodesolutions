double findMaxAverage(int* nums, int numsSize, int k)
{
    double max_average = INT_MIN;
    int start_index = 0;
    int end_index = 0;
    int current_sum = 0;
    
    for(end_index=0; end_index<numsSize; )
    {
        if(end_index - start_index < k)
        {
            current_sum += nums[end_index];
       
        }
        else
        {
            current_sum -= nums[start_index];
            start_index++;
            current_sum += nums[end_index];     
        }
        
        if(end_index - start_index == k-1)
        {
            double cur_average = ((double)current_sum)/(k);
            if(cur_average >= max_average)
            {
                   max_average = cur_average;
            }
        }
        end_index++;   
    }
    return max_average;
}