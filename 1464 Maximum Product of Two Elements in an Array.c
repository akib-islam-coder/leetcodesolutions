int maxProduct(int* nums, int numsSize)
{
    //Find two maximum
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    
    int i=0;
    for(i=0; i<numsSize; i++)
    {
        if(nums[i] >= max1)
        {
            max2 = max1;
            max1 = nums[i];
        }
        else
        {
            if(nums[i] >= max2)
            {
                max2 = nums[i];
            }
        }
        
    }
    

    return (max2-1)*(max1-1);
    
}