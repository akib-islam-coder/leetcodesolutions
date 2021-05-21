
/*
*   Time Complexity O(n)
*/
int removeDuplicates(int* nums, int numsSize)
{

    int i=0;
    int shift_done = 0;
    int j=0;               
    for(i=0; i<numsSize-1; i++)
    {
 
        //Compare adjacent elements
        if(nums[i] == nums[i+1])
        {
           continue;
        }
        else
        {
            nums[j] = nums[i];
            j++;
        }
    }
    
    if(numsSize > 0)
        nums[j++] = nums[numsSize-1];
    
    return j;
    
    
}