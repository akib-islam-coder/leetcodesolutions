

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize)
{

    int * ret_arr = (int *)malloc(sizeof(int)*numsSize);
    memset(ret_arr, -1, sizeof(int)*numsSize);
    *returnSize = numsSize;
    
    
    int i=0;
    for(i=0; i<numsSize; i++)
    {
        int pos = index[i];
        int val = nums[i];
        
        if(ret_arr[pos] == -1)
        {
            ret_arr[pos] = val;
            
        }
        else    //Already occupied, shift the elements
        {
            int j=0;
            for(j=numsSize-2; j>=pos ; j--)
            {
                ret_arr[j+1] = ret_arr[j];
            }
            
            ret_arr[pos] = val;
        }
    }
    return ret_arr;
    
}