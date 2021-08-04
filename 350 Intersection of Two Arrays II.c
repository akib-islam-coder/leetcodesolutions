int hashtable1[1001] = {0};
int hashtable2[1001] = {0};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    memset(hashtable1, 0x00, sizeof(hashtable1));
    memset(hashtable2, 0x00, sizeof(hashtable2));
    
    int * ret_arr = NULL;
    int ret_arr_index = 0;
    
    int i=0;
    for(i=0; i<nums1Size; i++)
    {
        hashtable1[nums1[i]] += 1;
    }
    
    for(i=0; i<nums2Size; i++)
    {
        hashtable2[nums2[i]] += 1;
    }
    
    
    if(nums2Size <= nums1Size)
    {
        ret_arr = (int *)malloc(sizeof(int) * nums2Size);
         ret_arr_index = 0;
        
        for(i=0; i<nums2Size; i++)
        {
            if(hashtable1[nums2[i]] > 0)
            {
                ret_arr[ret_arr_index++] = nums2[i];
                hashtable1[nums2[i]] -= 1;
            }
        }
        
    }
    else
    {
        ret_arr = (int *)malloc(sizeof(int) * nums1Size);
         ret_arr_index = 0;
        
        for(i=0; i<nums1Size; i++)
        {
            if(hashtable2[nums1[i]] > 0)
            {
                ret_arr[ret_arr_index++] = nums1[i];
                hashtable2[nums1[i]] -= 1;
            }
        }
    }
    *returnSize = ret_arr_index;
    return ret_arr;
    
}