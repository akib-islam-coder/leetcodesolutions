

/*
*   BruteForce Approach - We will take one extra array and then merge nums1 and num2 in sorted order in that array. Space Complexity - O(m+n)
*   Also, Run Time Complexity will be O(m+n)
*/
double findMedianSortedArrays_BruteForce(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int * sorted_arr = (int *)malloc(sizeof(int) * (nums1Size + nums2Size));
    
    int sorted_arr_index = 0;
    int nums1_index = 0;
    int nums2_index = 0;
    
    //Traverse till we reach the end of one list or two list if equal length
    while((nums1_index < nums1Size) && (nums2_index < nums2Size))
    {
        if(nums1[nums1_index] <= nums2[nums2_index])
        {
            sorted_arr[sorted_arr_index++] = nums1[nums1_index++];
        }
        else
        {
            sorted_arr[sorted_arr_index++] = nums2[nums2_index++];
        }
    }

    while(nums1_index < nums1Size)
    {
        sorted_arr[sorted_arr_index++] = nums1[nums1_index++];
    }
    
    while(nums2_index < nums2Size)
    {
        sorted_arr[sorted_arr_index++] = nums2[nums2_index++];
    }
    
    double ret_val;
    if(sorted_arr_index%2)
    {
        ret_val =  (sorted_arr[sorted_arr_index/2]);
    }
    else
    {
        ret_val =  ((double)( sorted_arr[sorted_arr_index/2] + sorted_arr[sorted_arr_index/2 - 1]))/2;
    }
    
    free(sorted_arr);
    return ret_val;
}



double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{

    //Bruteforce approach
    return findMedianSortedArrays_BruteForce(nums1, nums1Size, nums2, nums2Size);
    
}