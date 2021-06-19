

int findNumbers(int* nums, int numsSize)
{
    int i=0;
    int count = 0;
    
    for(i=0; i<numsSize; i++)
    {
        int no_of_digits = 0;    
        
        while(nums[i] > 0)
        {
            no_of_digits++;
            nums[i] /= 10;
        }
        
        if((no_of_digits %2) == 0)
        {
            count++;
        }
    }
    return count;
}