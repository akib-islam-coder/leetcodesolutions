int * hashtable = NULL;

int missingNumber(int* nums, int numsSize)
{
    hashtable = (int *)malloc(sizeof(int) * (numsSize+1));   
    
    int i=0;
    for(i=0; i<numsSize+1; i++)
    {
        hashtable[i] = 0;
    }
    
    for(i=0; i<numsSize; i++)
    {
        hashtable[nums[i]] = 1;
    }
    
    int missing_num = 0;
    for(i=0; i<numsSize+1; i++)
    {
        if(hashtable[i] == 0)
        {
            missing_num = i;
            break;
        }
    }
    return missing_num;
    
}