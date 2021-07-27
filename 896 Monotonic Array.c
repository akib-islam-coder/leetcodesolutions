

bool isMonotonic(int* nums, int numsSize)
{
    int i=0;
    bool increase = false;
    bool decrease = false;
    bool ret_val = true;
    
    if(numsSize == 1)
        return true;
    
    if(nums[1] == nums[0])
    {
        increase = true;
        decrease = true;
    }
    else if(nums[1] > nums[0])
    {
        increase = true;
    }
    else
    {
        decrease = true;
    }
    
    for(i=2; i<numsSize; i++)
    {
        
        if(increase==true && decrease==false)   //Monotonous increasing
        {
            if(nums[i] < nums[i-1])
            {
                ret_val = false;
                break;
            }
        }
        else if(increase==false && decrease==true)  //Monotonous decreasing
        {
            if(nums[i] > nums[i-1])
            {
                ret_val = false;
                break;
            }
        }
        else if(increase==true && decrease==true)
        {
            if(nums[i] == nums[i-1])
            {
                increase = true;
                decrease = true;
            }
            else if(nums[i] > nums[i-1])
            {
                increase = true;
                decrease = false;
            }
            else
            {
                increase = false;
                decrease = true;
            }
        }
    }
    return ret_val;
}