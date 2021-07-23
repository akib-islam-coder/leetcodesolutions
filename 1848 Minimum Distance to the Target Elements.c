

int getMinDistance(int* nums, int numsSize, int target, int start)
{
    int i = 0;
    int min = INT_MAX;
    
    for(i=0; i<numsSize; i++)
    {
        if(target == nums[i])
        {
            int diff = (i - start);
            if(diff < 0)
                diff *= -1;
            
            if(diff <= min)
            {
                min = diff;
            }
        }
    }
    return min;
}