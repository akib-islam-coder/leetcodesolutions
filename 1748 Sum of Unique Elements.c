int hashtable[101] = {0};

int sumOfUnique(int* nums, int numsSize)
{
    memset(hashtable, 0x00, sizeof(hashtable));
    int i=0;
    for(i=0; i<numsSize; i++)
    {
        hashtable[nums[i]] += 1;
    }
    
    int count = 0;
    for(i=0; i<numsSize; i++)
    {
        if(hashtable[nums[i]] == 1)
        {
            count += nums[i];
        }
    }
    return count;
}