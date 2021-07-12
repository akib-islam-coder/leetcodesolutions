void merge(int * arr, int low, int mid, int high)
{
    int * ret_arr = (int *)malloc(sizeof(int) * (high - low + 1));
    int ret_arr_index = 0;
    
    int i=0,j=0;
    for(i=low, j=mid+1; i<=mid && j<=high; )
    {
        if(arr[i] <= arr[j])
        {
            ret_arr[ret_arr_index++] = arr[i++];
        }
        else
        {
            ret_arr[ret_arr_index++] = arr[j++];
        }
    }
    
    while(i<=mid)
    {
        ret_arr[ret_arr_index++] = arr[i++];
    }
    
    while(j<=high)
    {
        ret_arr[ret_arr_index++] = arr[j++];
    }
    
    memcpy(&arr[low], ret_arr, sizeof(int) * ret_arr_index);
    free(ret_arr);
}


void merge_sort(int * arr, int low, int high)
{
    if(low < high)
    {
        int mid = (low + high)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    //Common elements in both the arrays
    
    merge_sort(nums1, 0, nums1Size-1);
    merge_sort(nums2, 0, nums2Size-1);
    int * ret_arr = (int *)malloc(sizeof(int) * (nums1Size + nums2Size));
    int ret_arr_index = 0;
    int prev_element = INT_MIN;
    
    int i=0,j=0;
    for(i=0, j=0; i<nums1Size && j<nums2Size; )
    {
        if(nums1[i] == nums2[j])
        {
            if(prev_element != nums1[i])
            {
                ret_arr[ret_arr_index++] = nums1[i];
                prev_element = nums1[i];
                i++;
                j++;
            }
            else
            {
                i++;
                j++;
            }
        }
        else if(nums1[i] < nums2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    
    *returnSize = ret_arr_index;
    return ret_arr;
}