

int singleNumber(int* nums, int numsSize)
{
    //XOR of a number with same number gives 0
    //If we XOR all elements, the same number will cancel out and we will be left with a single odd number
    if(numsSize <= 1)
    {
        return nums[0];        
    }
    int i=0;
    int val = nums[0];
    for(i=1; i<numsSize; i++)
    {
        val ^= nums[i];
    }
    return val;
}