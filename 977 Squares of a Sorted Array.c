void merge(int * nums, int low, int mid, int high)
{
    int * tmp_arr = (int *)malloc(sizeof(int) * (high-low+1));
    int tmp_arr_index = 0;
    
    int i=0, j=0;
 
    
    for(i=low, j=mid+1; i<=mid && j<=high; )
    {
        if(nums[i]<=nums[j])
        {
            tmp_arr[tmp_arr_index++] = nums[i++];
        }
        else
        {
            tmp_arr[tmp_arr_index++] = nums[j++];
        }
    }
    
    while(i<=mid)
    {
        tmp_arr[tmp_arr_index++] = nums[i++];
    }
    
    while(j<=high)
    {
        tmp_arr[tmp_arr_index++] = nums[j++];
    }
    
    
    memcpy(&nums[low], tmp_arr, sizeof(int)*(high-low+1));
    free(tmp_arr);
}

void merge_sort(int * nums, int low, int high)
{
    if(low<high)
    {
        int mid = (low+high)/2;
        merge_sort(nums, low, mid);
        merge_sort(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize)
{
    int i=0;
    for(i=0; i<numsSize; i++)
    {
        nums[i] = (nums[i] * nums[i]);
    }
    
    
    merge_sort(nums, 0, numsSize-1);
    *returnSize = numsSize;
    return nums;
}