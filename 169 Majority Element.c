

int majorityElement(int* nums, int numsSize)
{
    //Since its guranteed that majority element always exists, Solving it by bayer moore voting algorithm
    int majority_element = nums[0];
    int count = 1;
    
    int i=0;
    for(i=1; i<numsSize; i++)
    {
        if(nums[i] == majority_element)
        {
            count++;
        }
        else
        {
            count--;
            
            if(count == 0)
            {
                majority_element = nums[i];
                count = 1;
            }
        }
    }
    return majority_element;
}