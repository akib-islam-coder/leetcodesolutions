
/*
*   Time Complexity - O(n)
*/
int removeElement(int* nums, int numsSize, int val)
{
    int i = 0;
    int last = numsSize-1;
    
    while((i < numsSize) && (i <= last))
    {
        if(nums[i] == val)
        {
            nums[i] = nums[last--];
        }
        else
        {
            i++;
        }
    }
    return (last+1);
    
}