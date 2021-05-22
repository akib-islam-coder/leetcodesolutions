

int searchInsert(int* nums, int numsSize, int target)
{
    
    int mid = 0;
    int low = 0;
    int high = (numsSize-1);
    bool search_found = false;
    
    //Applying binary search
    while(low <= high)
    {
        mid = (low + high)/2;
        
        if(nums[mid] == target)
        {
            search_found = true;
            break;
        }
        
        else if(target > nums[mid])
        {
            low = mid+1;
        }
        
        else if(target < nums[mid])
        {
            high = mid-1;
        }
    }
      
    if(target > nums[mid])
    {
        return mid+1;
    }
    else if(target < nums[mid])
    {
            return mid;

    }
    
    return mid; //If search is successful
}