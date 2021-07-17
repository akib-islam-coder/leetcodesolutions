

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int mid = 0;
    int low = 0;
    int high = 0;
     
    int first_index = -1;
    int last_index = -1;
    int find_index = -1;
    
    low = 0;
    high = numsSize-1;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(target < nums[mid])
        {
            high = mid - 1;
        }
        else if(target > nums[mid])
        {
            low = mid+1;
        }
        else
        {
            find_index = mid;
            break;
        }
    }
    
    bool match_found = true;
    
    //Search to the left of the find_index
    while(match_found == true)
    {
        low = 0;
        high = find_index-1;
        
        while(low <= high)
        {
            mid = (low + high)/2;
            if(target < nums[mid])
            {
                high = mid - 1;
            }
            else if(target > nums[mid])
            {
                low = mid + 1;
            }
            else
            {
                find_index = mid;
                break;
            }
        }
        
        if(low > high)
        {
            match_found = false;
        }
    }
    
    int * ret_arr = (int *)malloc(sizeof(int) * 2);
    ret_arr[0] = find_index;
    
    match_found = true;
    //Search to the right of the find index
    while(match_found == true)
    {
        low = find_index+1;
        high = numsSize-1;
        
        while(low <= high)
        {
            mid = (low + high)/2;
            if(target < nums[mid])
            {
                high = mid - 1;
            }
            else if(target > nums[mid])
            {
                low = mid + 1;
            }
            else
            {
                find_index = mid;
                break;
            }
        }
        
        if(low > high)
        {
            match_found = false;
        }
    }
    ret_arr[1] = find_index;
    *returnSize = 2;
    return ret_arr;
    
}