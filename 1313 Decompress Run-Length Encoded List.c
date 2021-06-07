/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decompressRLElist(int* nums, int numsSize, int* returnSize)
{

    int i=0, j=0;
    int freq = nums[0];
    int val  = nums[1];
    
    int * ret_arr = (int *)malloc(sizeof(int)*freq);
    for(j=0; j<freq; j++)
    {
        ret_arr[j] = val;
    }
       
    int prev_freq = freq;
    
    for(i=2; i<numsSize; i=i+2)
    {
      
        freq = nums[i];
        val  = nums[i+1];
        
        ret_arr = (int *)realloc(ret_arr, sizeof(int)*(freq + prev_freq));
        
        for(j=0; j<freq; j++)
        {
            ret_arr[j+prev_freq] = val;
        }   
        
        prev_freq += freq;    
    }
    
    *returnSize = prev_freq;
    return ret_arr;
    
    
}