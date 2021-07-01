void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    //In order to do merge, we will require one auxillary array
    int * tmp_arr = (int *)malloc(sizeof(int) *(m+n));
    int tmp_arr_index = 0;
    
    int i=0, j=0;
    
    for(i=0,j=0; i<m && j<n;)
    {
        if(nums1[i] <= nums2[j])
        {
            tmp_arr[tmp_arr_index++] = nums1[i++];
        }
        else
        {
            tmp_arr[tmp_arr_index++] = nums2[j++];
        }
    }
    
    while(i<m)
    {
        tmp_arr[tmp_arr_index++] = nums1[i++];
    }
    
    while(j<n)
    {
        tmp_arr[tmp_arr_index++] = nums2[j++];
    }

    memcpy(&nums1[0], &tmp_arr[0], sizeof(int)*(tmp_arr_index));
    free(tmp_arr);
    return nums1;
    
}