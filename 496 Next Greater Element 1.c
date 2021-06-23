

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    int * ret_arr = (int *)malloc(sizeof(int) * nums1Size);
    int ret_arr_index = 0;
    int i=0;
    for(i=0; i<nums1Size; i++)
    {
        int arr1_element = nums1[i];
        
        int j=0;
        for(j=0; j<nums2Size; j++)
        {
            if(nums2[j] == arr1_element)
            {
                break;
            }
                
        }
        
        int second_max = INT_MAX;
        int k=0;
        for(k=j+1; k<nums2Size; k++)
        {
            if(nums2[k] > arr1_element)
            {
                second_max = nums2[k];
                break;
            }
        }
        
        if(second_max == INT_MAX)
        {
            ret_arr[ret_arr_index++] = -1;
        }
        else
        {
            ret_arr[ret_arr_index++] = second_max;
        }
    }
    *returnSize = ret_arr_index;
    return ret_arr;
    
}